# Tower of Hanoi: Moving Rings with Recursion

## What is the Tower of Hanoi Problem?

The **Tower of Hanoi** is a classic recursive puzzle with three towers (A, B, C) and **n rings** of different sizes.

### Initial Setup
- Tower **A** (Source): Contains all n rings stacked in decreasing order of size (largest at bottom)
- Tower **B** (Auxiliary): Empty tower used as a helper
- Tower **C** (Destination): Where all rings must be moved

### Rules
1. **Only one ring can be moved at a time**
2. **A larger ring can NEVER be placed on top of a smaller ring** (this is the constraint that makes recursion necessary)

---

## How Recursion Solves It

The key insight is breaking the problem into **smaller subproblems**. Here's the recursive strategy:

### Base Case: TOH(1, A, B, C)
When only **1 ring** exists:
- Move the ring directly from source (A) to destination (C)
- The auxiliary tower (B) is not needed
- ---

## Building Up: Step-by-Step Examples

### Case 1: Two Rings — TOH(2, A, B, C)

With rings labeled 1 (top/smallest) and 2 (bottom/largest):

| Step | Action | Explanation |
|------|--------|-------------|
| 1 | `TOH(1, A, C, B)` | Move ring **1** from A to B (using C as auxiliary) |
| 2 | `TOH(1, A, B, C)` | Move ring **2** from A to C (using B as auxiliary) |
| 3 | `TOH(1, B, A, C)` | Move ring **1** from B to C (using A as auxiliary) |

**Visual Progression:**<br>
Start:    A: [2,1]   B: [ ]   C: [ ] <br>
After 1:  A: [2]     B: [1]   C: [ ]<br>
After 2:  A: [ ]     B: [1]   C: [2]<br>
After 3:  A: [ ]     B: [ ]   C: [2,1]   Goal reached<br>
---

### Case 2: Three Rings — TOH(3, A, B, C)

With rings labeled 1 (top), 2 (middle), and 3 (bottom/largest):

| Step | Action | Explanation |
|------|--------|-------------|
| 1 | `TOH(2, A, C, B)` | Move rings **1–2** from A to B (using C as auxiliary) |
| 2 | `TOH(1, A, B, C)` | Move ring **3** from A to C (using B as auxiliary) |
| 3 | `TOH(2, B, A, C)` | Move rings **1–2** from B to C (using A as auxiliary) |

> Note: Steps 1 and 3 expand further using the 2-ring solution recursively.

---

##  General Recursive Formula: TOH(n, A, B, C)

For any number of rings **n**:

### Algorithm Steps
1. **Recursively** move **n–1 rings** from source (A) to auxiliary (B), using destination (C) as helper
   - `TOH(n-1, A, C, B)`

2. Move the **largest ring** (ring n) directly from source (A) to destination (C)
   - No auxiliary needed — it's the only ring left on A

3. **Recursively** move **n–1 rings** from auxiliary (B) to destination (C), using source (A) as helper
   - `TOH(n-1, B, A, C)`

---

## Complexity Analysis

### Time Complexity: **O(2^n)**
- Each call to `TOH(n)` makes 2 recursive calls to `TOH(n-1)`
- For **n rings**, the total number of moves = **2^n - 1**
- Example: 3 rings = 2³ - 1 = 7 moves; 64 rings = 2⁶⁴ - 1 ≈ 18.4 quintillion moves

### Space Complexity: **O(n)**
- Recursion depth = **n** (maximum call stack size)
- Each recursive level stores one function call on the call stack

---

## Why This Works: The Recursive Insight

The elegance of this solution lies in a simple observation:

> **To move n rings from A to C, you must first move n–1 rings out of the way (to B), then move the largest ring (to C), then reassemble the n–1 rings on top of it.**

Each subproblem is identical to the original problem, just with fewer rings this is the essence of **recursion**.

---


- **Tower of Hanoi demonstrates** how recursion breaks a seemingly hard problem into manageable smaller versions of itself
- **The constraint** (larger ring can't sit on smaller ring) forces the recursive structure
- **Exponential growth**: Even small increases in n cause massive increases in moves (64 rings would take millennia)
- **Recursion vs. Iteration**: While this problem has an iterative solution, the recursive approach is far more intuitive and elegant
