# DESCRIPTION

push_swap is a project whose objective is to sort a list of integers using two stacks (a and b) and a limited set of operations (sa, pb, ra, etc.).

The main challenge is to find the most efficient way possible to sort the numbers, minimizing the number of moves performed.

The project includes different sorting strategies depending on the size of the stack:
simple algorithms for few numbers,
chunk-based algorithms for intermediate sizes,
radix algorithm for large amounts of data.

# INSTRUCTIONS

Compilation
make
Execution

```
./push_swap 3 2 1 5 4 
 ```

It is also possible to manually select the algorithm:

```
./push_swap --simple 3 2 1
./push_swap --medium 5 8 1 9 2
./push_swap --complex 10 4 7 2 1
```

Optionally, you can use:

```
--bench
```

to collect movement statistics.

# RESOURCES

References used
Official C documentation
push_swap operations manual
Explanations about Radix Sort algorithms
Resources on doubly linked lists and stack manipulation
Videos and articles on optimization strategies in push_swap
Use of AI

AI has been used as support for:

Understanding and debugging algorithms.
Explanation of structures and logic.
Optimization and refactoring of functions.
Error resolution and validations.
Help with project documentation (README).

The implementation, adaptation and final validation of the code have been performed manually during project development.

# PROJECT DETAILS AND JUSTIFICATION OF USE
## 1. Justification of threshold values (Thresholds)
The disorder index is calculated with ft_compute_disorder, which measures how many numbers are out of order compared to the maximum possible.
To do this it counts inversions (pairs of misplaced numbers)
and divides them by the total number of possible pairs.
Thus it obtains a value between:
0 → completely sorted list
1 → completely unsorted list.

### Low Regime (< 0.2)
A value less than 0.2 means that the stack is almost sorted and only a few numbers are out of place.
Using large algorithms here would make unnecessary moves.

### Medium Regime (0.2 ≤ disorder < 0.5)
The stack has intermediate disorder.
In this case it is convenient to divide the numbers into blocks to reduce rotations and sort more efficiently.

### High Regime (≥ 0.5)
The stack is very disordered or almost inverted.
Here you need a more automatic and stable algorithm that works well regardless of the initial order.
---

## 2. Analysis of Internal Techniques and Complexity

### 🟢 Low Regime: ft_simple (Adaptation of insertion sort)

**Description:**
When the stack is almost sorted, the algorithm detects out-of-place elements, temporarily moves them to B, and then reinserts them in the correct position within A.
Since most numbers are already well placed, few operations are needed.

**Time Complexity (Worst case):** O(n)
The number of moves grows approximately linearly, since there are few disordered elements.

**Space Complexity:** O(1)
It does not use significant extra memory, works directly on the existing stacks.
---

### 🟡 Medium Regime: ft_medium (chunk-based)

**Description:**
The algorithm divides the numbers into blocks ("chunks") to sort the stack more efficiently.
It first assigns an index to each element and then moves to B the numbers that belong to the current block. The size of these blocks adapts according to the size of the stack.
Once all elements are in B, they are returned to A by always looking for the largest value and using the shortest rotation (rb or rrb).

**Time Complexity (Worst case):** O(n√n)
Dividing the stack into blocks reduces the number of searches and rotations needed during sorting.

**Space Complexity:** O(n)
Requires extra memory to temporarily store the indices used during stack preprocessing.

---

### 🔴 High Regime: ft_complex_radix (Binary Radix Sort by Bits)

**Description:**
This algorithm sorts numbers using their binary representation.
In each pass it checks a specific bit, starting with the least significant:
if the bit is 0, the number is moved to B
if the bit is 1, the number stays in A
Then the elements from B are returned to A and the process repeats with the next bit.
Since it works bit by bit, performance is stable even when the stack is completely disordered.

**Time Complexity (Worst case):** O(n log n)
The algorithm makes multiple passes over the stack, approximately one for each bit needed to represent the indices.

**Space Complexity:** O(n)
Requires additional memory during the initial indexing phase of the elements.
