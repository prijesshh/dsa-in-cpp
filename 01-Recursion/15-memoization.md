# 8.10 Memoization

*The recursive Fibonacci function is clean and elegant — but run it for `fib(40)` and watch your CPU sweat. Why? Because it's doing the same work over and over again.*

## The Problem — Repeated Function Calls

Normally we can calculate the Fibonacci series using a recursive function:

```cpp
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
```

> 📝 Note: The base condition was written as `if(n<=0) return n` in the original, but the correct base cases for Fibonacci are `n=0 → 0` and `n=1 → 1`. Fixed to `if(n<=1) return n` so that `fib(1)` correctly returns `1` instead of recursing infinitely.

This approach takes a lot of time and has a time complexity of **O(2^n)**.

### Why O(2^n)? — The Recursion Tree for `fib(5)`

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

All this repeated work is wasted — we are recomputing the same values from scratch every time.

## The Solution — Memoization

**Storing the result of a function call so that it can be utilized again is called memoization.**

If we make a **static or global array** such that it stores the value of each already-called function, then we can look up that value instead of recomputing it — and reduce time complexity.

```cpp
int memo[100];  // global array, initialized to -1

int fib(int n)
{
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];                // return stored result directly
    memo[n] = fib(n - 1) + fib(n - 2); // compute and store
    return memo[n];
}
```

> ➕ Added: The code implementation of memoization using a global array — your note described the concept but didn't show the code, so this makes it concrete.

### How It Reduces Time Complexity

| Approach | Time Complexity | Reason |
|---|---|---|
| Plain recursion | O(2^n) | Same subproblems recomputed repeatedly |
| Memoization | O(n) | Each subproblem computed **once**, then looked up |

Each unique value of `fib(k)` is computed exactly **once** and stored. Every subsequent call for the same `k` just reads from the array in O(1).

---

## 📚 Quick Recap

- The naïve recursive Fibonacci has **O(2^n)** time complexity because it recomputes the same subproblems repeatedly.
- For `fib(5)`, `fib(3)` is called 2 times, `fib(2)` is called 3 times, and so on — all wasted work.
- **Memoization** = storing the result of a function call so it can be reused instead of recomputed.
- Implemented using a **static or global array** that caches results indexed by input.
- Memoization reduces Fibonacci time complexity from **O(2^n) → O(n)**.
- Memoization is the foundation of **Dynamic Programming (top-down approach)**.