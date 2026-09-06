# Push Swap

[![Build](https://github.com/C1STA/push_swap/actions/workflows/build.yml/badge.svg?branch=main)](https://github.com/C1STA/push_swap/actions/workflows/build.yml)

An operation-efficient integer sorting program written in C using two linked
stacks and a restricted instruction set.

Push Swap is an algorithm project from the 42 curriculum. The program receives
a sequence of unique signed integers and prints the stack operations required
to sort them. A companion checker executes those instructions and validates the
result.

## Algorithm

The implementation uses a cost-based insertion strategy:

1. Parse and validate the full signed integer range, rejecting duplicates.
2. Replace values with relative ranks to make comparisons independent of their
   magnitude.
3. Move part of stack A to stack B while preserving a small sorted core.
4. Compute the target position and rotation cost of every candidate in B.
5. Move the cheapest candidate, combining rotations of both stacks when
   possible.
6. Rotate the minimum-ranked value to the top of A.

The data structure stores ranks, positions, target positions, and movement
costs directly in each linked-list node. This keeps the decision process
explicit and avoids auxiliary arrays during sorting.

## Operations

| Family | Instructions | Purpose |
| ------ | ------------ | ------- |
| Swap | `sa`, `sb`, `ss` | Exchange the first two elements |
| Push | `pa`, `pb` | Move the first element between stacks |
| Rotate | `ra`, `rb`, `rr` | Move the first element to the end |
| Reverse rotate | `rra`, `rrb`, `rrr` | Move the last element to the front |

## Build and run

```bash
make
make bonus
```

Run the sorter:

```bash
./push_swap 8 3 5 1 9 2
```

Validate its output with the included checker:

```bash
args=(8 3 5 1 9 2)
./push_swap "${args[@]}" | ./checker "${args[@]}"
```

The checker prints `OK` when the operations sort stack A and leave stack B
empty, or `KO` otherwise.

## Measured performance

The following results were measured over random unique inputs during the
portfolio validation:

| Input size | Samples | Average operations | Maximum observed |
| ---------- | ------: | -----------------: | ---------------: |
| 100 | 60 | 587 | 636 |
| 500 | 20 | 4,786 | 5,065 |

Results vary with the input order. The GitHub Actions workflow additionally
checks representative inputs against limits of 700 operations for 100 values
and 5,500 operations for 500 values.

## Validation

```bash
make
make bonus
valgrind --leak-check=full ./push_swap 4 2 5 1 3
```

The CI workflow builds both executables, tests invalid inputs and signed integer
boundaries, validates generated operations, and enforces operation-count
thresholds.

The curated 42 submission is available through the `42-submission` tag. The
original third-party checker binary is intentionally not included; `make bonus`
builds the checker from source.
