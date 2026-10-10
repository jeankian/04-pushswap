# push_swap

*This project was created as part of the 42 curriculum by jia-liew and jifoo.*

## Description

`push_swap` sorts a stack of unique integers using a restricted set of operations
on two stacks, A and B. The objective is to produce a correct result with as few
printed operations as possible.

This implementation contains three sorting strategies—simple, medium, and
complex—and an adaptive strategy that selects between them according to the
measured disorder of the input. A bonus checker reads operations from standard
input, executes them, and reports whether stack A is sorted and stack B is empty.

The program validates command-line input, rejects duplicates and values outside
the range of an `int`, and supports separate numeric arguments or a single quoted
string. Before sorting, it copies and sorts the values with insertion sort and
assigns every node a rank. The algorithms then compare indices rather than the
original integers.

## Implementation work

The project work includes:

- parsing and validating both supported input formats;
- building, indexing, and cleaning up linked-list stacks;
- implementing all required stack operations and operation counting;
- creating simple, chunk-based, and greedy cost-based sorting algorithms;
- measuring input disorder and selecting a strategy adaptively;
- adding benchmark output for strategy and operation analysis; and
- implementing the bonus checker.

## Contributors and responsibilities

The contribution history uses several author identities. Commits by Caleb Foo,
`jifoo`, and `Jae` refer to the same contributor; commits by Jia Jiet Liew,
`jia-liew`, and `JiaJiet02` refer to the other contributor.

### Caleb Foo (`jifoo` / `Jae`)

- integrated `libft` and established the initial project headers and build setup;
- implemented command-line parsing, integer validation, duplicate detection,
  presorting, and rank assignment;
- developed the simple sorting strategy, specialised small-stack handling, and
  circularly sorted-stack optimisation;
- developed the greedy cost-based complex strategy (Turk sort), including target
  selection, signed rotation costs, combined `rr`/`rrr` planning, and related
  experiments;
- implemented the disorder metric, adaptive strategy selection, benchmark mode,
  and the standalone random benchmark tool; and
- carried out later integration, file organisation, bug fixes, and Makefile and
  header updates.

### Jia Jiet Liew (`jia-liew` / `JiaJiet02`)

- implemented the initial stack construction and helped migrate the project from
  generic list nodes to the dedicated `t_stack` representation;
- implemented and tested the swap, push, rotate, reverse-rotate, and combined
  stack operations;
- developed shared sorting and testing utilities, operation counting, and the
  project Makefile during the early integration stages;
- designed, implemented, benchmarked, and refined the sliding-window medium
  chunk algorithm and its B-to-A reconstruction helpers;
- implemented the bonus checker and integrated `get_next_line` and the bonus
  build target; and
- performed the final data-structure simplification, Norm compliance pass, and
  README development.

Both contributors also worked on shared integration points—including `main`,
`push_swap.h`, the Makefile, stack utilities, merge resolution, testing, and the
final adaptive build—so responsibility for those areas is collaborative rather
than exclusive.

## Presorting and indexing

The input values can span the full signed-integer range, so comparing their raw
magnitudes would make the sorting logic unnecessarily awkward. The program first
normalises them into consecutive indices from `0` to `n - 1`.

After parsing and duplicate validation, the values are used to build stack A.
`index_stack` then creates a separate copy of the input array so that the original
order in the stack is preserved. This copied array is sorted with insertion sort.
Insertion sort is appropriate here because this stage is simple preprocessing:
it is easy to implement, uses no additional recursive machinery, and does not
produce any stack operations that count towards the final score.

Each stack node's original value is searched for in the sorted copy. Its position
becomes its index:

```text
Original values:  42  -7  19   3
Sorted copy:      -7   3  19  42
Assigned indices:  3   0   2   1
```

The smallest value therefore always has index `0`, the next-smallest has index
`1`, and the largest has index `n - 1`. The sorted copy is freed after all indices
have been assigned.

This normalisation gives every sorting strategy a compact and predictable range.
Chunk boundaries can be expressed directly as index ranges, minimum and maximum
elements are easy to identify, and target-position calculations do not need to
account for large, negative, or unevenly spaced input values. Because duplicates
are rejected before indexing, every valid node receives one unique rank.

## Sorting strategies

### Small-input handling

Before a general algorithm runs, `sort_checker` detects an already sorted or
circularly sorted stack and handles stacks of two to five elements directly.
Specialised routines avoid the overhead of a general algorithm and give small
inputs short, predictable operation sequences.

### Simple algorithm: insertion-sort adaptation

The simple strategy adapts insertion sort to two stacks. It repeatedly considers
the element at the top of A, searches B for the largest index smaller than that
element, rotates B so that this insertion target is on top, and pushes the element
from A to B. This maintains B in circular descending order. Once A is empty, B is
rotated so that its maximum is on top and every element is pushed back to A,
producing ascending order.

This strategy is deliberately straightforward. Its repeated target searches and
rotations can approach quadratic work. It remains useful as a clear baseline,
although the current P95 benchmark shows that medium or complex is more
operation-efficient at each tested low-disorder size.

### Medium algorithm: sliding-window chunking

The medium strategy divides the index range into chunks and moves eligible
elements from A to B through a sliding window. Elements in the lower part of the
active window are rotated deeper into B, while elements in the upper part remain
near its top. This distribution reduces the rotations needed during
reconstruction. The maximum remaining element is repeatedly located and moved
back to A.

Chunking gives more predictable behaviour than evaluating every possible
insertion on every iteration. It becomes useful once disorder makes the simple
strategy's repeated searches expensive. At medium disorder and 500 elements,
medium averages 3586.0 operations compared with 18274.5 for simple. Complex
averages 3288.7 in that case, while medium remains a practical middle strategy
with simpler decision-making and stable operation counts.

### Complex algorithm: greedy insertion sort (Turk sort)

The complex strategy upgrades the insertion-sort idea by making each insertion
greedy. Simple insertion sort commits to whichever element is currently on top
of A. The complex strategy instead evaluates every candidate in A before choosing
the next move.

For each candidate, it calculates:

- the signed rotation cost required to bring that candidate to the top of A;
- the rotation cost required to bring its insertion position to the top of B; and
- the combined cost, accounting for rotations shared through `rr` or `rrr`.

The cheapest plan is executed, and the process repeats until only three elements
remain in A. Those three are sorted directly. Elements from B are then inserted
into their correct positions in A, after which the minimum is rotated to the top.

This is a greedy insertion sort because every step chooses the locally cheapest
available insertion rather than accepting the next input element. It retains the
ordered-insertion principle of the simple algorithm while reducing unnecessary
rotations, particularly on large or highly disordered inputs. It is also the
strategy used for high disorder because its `O(n log n)` upper bound satisfies
the required complexity target, even where another method records a lower raw
operation count.

## Adaptive strategy selector

Disorder is the proportion of inverted pairs in stack A. A value near zero means
the input is almost sorted; a larger value means it is more scrambled. The default
adaptive policy is:

| Size | Low (`< 0.20`) | Medium (`0.20–0.49`) | High (`>= 0.50`) |
|---:|:---|:---|:---|
| `<= 50` | Complex | Complex | Complex |
| `51–100` | Medium | Medium | Complex |
| `> 100` | Medium | Complex | Complex |

The size branches reflect the P95 benchmark winners among methods permitted in
each regime. For high disorder, complex is always selected to meet the required
`O(n log n)` upper bound. Medium sometimes produces fewer operations on the
tested high-disorder samples, but its `O(n sqrt(n))` bound does not satisfy that
regime. Faster-bounded methods may still be used in the low- and medium-disorder
branches because Big-O expresses an upper bound. The tested sizes provide
evidence for these cut-offs; using them for intermediate or larger sizes is an
explicit extrapolation from the available samples.

### Why chunk sort can outperform Turk sort

Turk sort is greedy: at each step, it calculates the current cost of moving each
candidate and immediately executes the cheapest move. This often removes many
unnecessary rotations, but the cheapest move now is not guaranteed to produce
the cheapest complete sequence. A locally attractive insertion can leave the
remaining elements in awkward positions, increasing the cost of later
insertions. The algorithm does not backtrack or compare complete future paths,
so it cannot recover from an early choice that later proves expensive.

Its performance is also sensitive to the initial rotation of stack A. Two
circular rotations contain the same values in the same cyclic order, but expose
different elements at the top. This changes the first set of candidate costs and
can lead the greedy search through a completely different sequence of choices.
Those early choices affect both stacks, so a small difference in starting
position can accumulate into a large difference in the final operation count.

Chunk sort is less sensitive to individual early decisions. Its window groups
indices by range and places them in broadly useful regions of B before rebuilding
A. It does not always choose the cheapest immediate insertion, but its regular
distribution can create a more favourable global arrangement. This predictable
structure is why chunk sort can outperform Turk sort in some benchmark regimes,
especially when Turk sort's early greedy choices lead to expensive later
rotations.

One possible Turk-sort optimisation is a multi-start search. The program could
simulate the algorithm from several initial rotations of A, record the operations
produced by each run, and then emit only the shortest valid sequence. Trying
every rotation would test all `n` circular starting positions; a cheaper variant
could sample a limited number of evenly spaced or promising rotations. Another
extension could retain several low-cost candidate moves at each early step
instead of committing immediately to one. These approaches reduce dependence on
a single starting position, but require extra simulation time and memory to
store or compare candidate operation sequences. Their added computational cost
would also need to remain within the complexity bound required for the selected
disorder regime.

## Instructions

Build the mandatory program with:

```sh
make
```

Build the bonus checker with:

```sh
make bonus
```

Run the adaptive strategy or select one explicitly:

```sh
./push_swap 4 2 3 1
./push_swap "4 2 3 1"
./push_swap --simple 4 2 3 1
./push_swap --medium 4 2 3 1
./push_swap --complex 4 2 3 1
./push_swap --adaptive 4 2 3 1
```

Add `--bench` before an optional strategy flag to print benchmark information to
standard error:

```sh
./push_swap --bench --adaptive 4 2 3 1
```

## Benchmark results

Each row contains 100 valid trials generated with the fixed seed `420042`. Low
disorder uses approximately 5% random swaps, medium disorder approximately 25%,
and high disorder a complete random shuffle. Operation counts are shown as the
average, median, 95th percentile (P95), and maximum. P95 is the operation count at or
below which 95% of the trials fall. It gives a useful view of near-worst-case
performance without allowing one unusually expensive run to dominate the
comparison, as a maximum can. The adaptive-strategy analysis therefore considers
P95 alongside the average and median when judging how consistently an algorithm
performs.

| Size | Disorder | Algorithm | Valid | Average | Median | P95 | Maximum |
|---:|:---|:---|:---:|---:|---:|---:|---:|
| 50 | Low | Simple | 100/100 | 136.8 | 136.5 | 166 | 173 |
| 50 | Low | Medium | 100/100 | 144.8 | 137.0 | 195 | 198 |
| 50 | Low | Complex | 100/100 | 112.5 | 105.0 | 157 | 178 |
| 50 | Medium | Simple | 100/100 | 278.1 | 279.0 | 323 | 362 |
| 50 | Medium | Medium | 100/100 | 183.8 | 184.0 | 204 | 222 |
| 50 | Medium | Complex | 100/100 | 180.5 | 181.5 | 202 | 222 |
| 50 | High | Simple | 100/100 | 416.9 | 418.0 | 471 | 511 |
| 50 | High | Medium | 100/100 | 233.7 | 233.0 | 250 | 263 |
| 50 | High | Complex | 100/100 | 221.9 | 222.0 | 242 | 255 |
| 100 | Low | Simple | 100/100 | 365.2 | 364.0 | 468 | 483 |
| 100 | Low | Medium | 100/100 | 259.5 | 255.0 | 296 | 322 |
| 100 | Low | Complex | 100/100 | 263.9 | 256.0 | 342 | 385 |
| 100 | Medium | Simple | 100/100 | 893.9 | 890.0 | 1059 | 1122 |
| 100 | Medium | Medium | 100/100 | 421.3 | 422.0 | 459 | 467 |
| 100 | Medium | Complex | 100/100 | 423.8 | 421.5 | 474 | 513 |
| 100 | High | Simple | 100/100 | 1465.7 | 1465.0 | 1605 | 1639 |
| 100 | High | Medium | 100/100 | 545.0 | 543.5 | 573 | 599 |
| 100 | High | Complex | 100/100 | 559.7 | 558.5 | 604 | 636 |
| 500 | Low | Simple | 100/100 | 5119.6 | 5100.0 | 6191 | 6741 |
| 500 | Low | Medium | 100/100 | 1578.7 | 1583.5 | 1688 | 1778 |
| 500 | Low | Complex | 100/100 | 1908.5 | 1880.5 | 2487 | 2527 |
| 500 | Medium | Simple | 100/100 | 18274.5 | 18279.5 | 20133 | 21412 |
| 500 | Medium | Medium | 100/100 | 3586.0 | 3577.0 | 3787 | 3894 |
| 500 | Medium | Complex | 100/100 | 3288.7 | 3284.0 | 3535 | 3626 |
| 500 | High | Simple | 100/100 | 32318.9 | 32257.0 | 33594 | 34247 |
| 500 | High | Medium | 100/100 | 4835.8 | 4834.5 | 4966 | 5082 |
| 500 | High | Complex | 100/100 | 5117.9 | 5121.5 | 5307 | 5458 |

### Adaptive result

The updated selector was then run on the same samples. All 900 outputs were
validated by replaying the emitted operations and checking that A was sorted and
B was empty.

| Size | Disorder | Valid | Average | Median | P95 | Maximum |
|---:|:---|:---:|---:|---:|---:|---:|
| 50 | Low | 100/100 | 112.5 | 105.0 | 157 | 178 |
| 50 | Medium | 100/100 | 180.5 | 181.5 | 202 | 222 |
| 50 | High | 100/100 | 221.9 | 222.0 | 242 | 255 |
| 100 | Low | 100/100 | 259.5 | 255.0 | 296 | 322 |
| 100 | Medium | 100/100 | 421.3 | 422.0 | 459 | 467 |
| 100 | High | 100/100 | 554.7 | 550.0 | 591 | 636 |
| 500 | Low | 100/100 | 1578.7 | 1583.5 | 1688 | 1778 |
| 500 | Medium | 100/100 | 3288.7 | 3284.0 | 3535 | 3626 |
| 500 | High | 100/100 | 5117.9 | 5121.5 | 5307 | 5458 |

## Resources

### Use of AI

AI was used as a review and documentation aid during development. It helped
identify potential bugs and edge cases, inspect memory-management paths, run and
interpret Valgrind leak checks, locate redundant declarations and headers, and
correct spelling and grammar in the documentation. It was also used to explain
concepts such as linked-list ownership, pointer usage, memory cleanup, indexing,
and the reasoning behind the sorting strategies. The algorithms, implementation
decisions, testing, and final code remained the responsibility of the project
authors.

### References

- [Understanding why `content` gives an address instead of a value](https://stackoverflow.com/questions/32147562/why-does-a-content-give-me-a-address-instead-of-a-value)
- [Returning the head of a linked list from a function](https://stackoverflow.com/questions/34007247/returning-head-of-linked-list-from-a-function)
- [Pointers and pointers-to-pointers in a singly linked list](https://stackoverflow.com/questions/75120366/pointers-and-pointers-to-pointers-in-a-singly-linked-list-help-me-understand-in)
- [Push Swap: the least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Push Swap 42 Visualizer](https://push-swap42-visualizer.vercel.app/)
- [Random Number Generator](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php)
- [Push Swap video guide 1](https://www.youtube.com/watch?v=wRvipSG4Mmk&pp=ygUJcHVzaF9zd2Fw)
- [Push Swap video guide 2](https://www.youtube.com/watch?v=OaG81sDEpVk&t=3897s&pp=ygUJcHVzaF9zd2Fw)
- [Push Swap video guide 3](https://www.youtube.com/watch?v=Y95a-8oNqps&t=11s&pp=ygUJcHVzaF9zd2Fw)
