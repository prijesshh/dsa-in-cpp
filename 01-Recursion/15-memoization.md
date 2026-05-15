# Memoization

*The recursive Fibonacci function is clean and elegant but run it for `fib(40)` and watch your CPU sweat. Why? Because it's doing the same work over and over again.*

## The Problem — Repeated Function Calls

Normally we can calculate the Fibonacci series using a recursive function:

```cpp
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}
```

This approach takes a lot of time and has a time complexity of **O(2^n)**.

### Why O(2^n)? The Recursion Tree for `fib(5)`

```
                        fib(5)
                       /       \
                  fib(4)        fib(3)
                 /     \        /    \
            fib(3)   fib(2)  fib(2) fib(1)
            /   \    /   \    /   \
         fib(2) fib(1) fib(1) fib(0) fib(1) fib(0)
         /   \
      fib(1) fib(0)
```

Notice the **repeated calls**:

| Function | Times Called |
|---|---|
| `fib(3)` | 2 times |
| `fib(2)` | 3 times |
| `fib(1)` | 5 times |
| `fib(0)` | 3 times |

All this repeated work is wasted we are recomputing the same values from scratch every time.

## The Solution — Memoization

**Storing the result of a function call so that it can be utilized again is called memoization.**

If we make a **static or global array** such that it stores the value of each already-called function, then we can look up that value instead of recomputing it and reduce time complexity.

### How It Reduces Time Complexity

| Approach | Time Complexity | Reason |
|---|---|---|
| Plain recursion | O(2^n) | Same subproblems recomputed repeatedly |
| Memoization | O(n) | Each subproblem computed **once**, then looked up |

Each unique value of `fib(k)` is computed exactly **once** and stored. Every subsequent call for the same `k` just reads from the array in O(1).
