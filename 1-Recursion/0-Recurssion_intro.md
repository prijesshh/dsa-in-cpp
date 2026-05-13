# 8. Recursion

-- -

    > What if a function could solve a problem by solving a smaller version of *the same problem *
    ? > That's the idea behind **recursion**  -- -

              ##8.1 What is Recursion
          ?

          **A function calling itself is called a recursive function.**

                                                                      Two rules every recursive function must follow
          : -It must **call itself **(with a smaller / simpler input).- There must be some **base condition that terminates the recursion **otherwise it runs forever.

                                                                        ## #General Structure

```c
                                                                        type fun(parameter)
{
    if (base condition)
    {
        fun(parameter); // recursive call
    }
}
```

    -- -

    ##8.2 Example 1 — Printing in Descending Order

```c void
    fun(int n)
{
    if (n > 0)
    {
        cout << n;
        fun(n - 1);
    }
}

void main()
{
    int n = 3;
    fun(n);
}
```

    **Execution trace : **

                        - `main` calls `fun(3)` → prints `3`,
                        calls `fun(2)` - `fun(2)` → prints `2`,
                        calls `fun(1)` - `fun(1)` → prints `1`,
                        calls `fun(0)` - `fun(0)` → base condition `n > 0` is false → * * terminates * *

                                                                                                       **Output : `3 2 1`**

                            > We can trace a * * tree * *of any recursive function to understand its execution.

                                                         -- -

                                                         ##8.3 Example 2 — Printing in Ascending Order

```c void fun2(int n)
{
    if (n > 0)
    {
        fun2(n - 1); // recursive call FIRST
        cout << n;   // print AFTER returning
    }
}

void main()
{
    int n = 3;
    fun2(n);
}
```

            **Recursion tree : **

``` fun2(3) /
                               fun2(2)       ↑ 3 /
                               fun2(1)    ↑ 2 /
                               fun2(0)  ↑ 1 |
    terminate
```

            **Output : `1 2 3`**

    > Notice how swapping the order of the `cout` and the recursive call **reverses the output **this is a key insight into how recursion works.

      -- -

      ##8.4 The Two Phases of Recursion

          **Recursion has 2 phases : **

```c
                                     void func(param)
{
    // ... → this is the CALLING PHASE (ascending phase)
    {
        func(param); // recursive call
        // ... → this is the RETURNING PHASE (descending phase)
    }
}
```

        | Phase | Also Called | When it happens |
        | -- -| -- -| -- -|
        | Calling phase | Ascending phase | As function calls are being made deeper |
        | Returning phase | Descending phase | As functions finish and return back up |

        ## #Recursion vs Loop — What's the Difference?

        Both recursion and
    loops execute something repeatedly.So what's different?

        > **→ Recursion has both an ascending phase and a descending phase,
    but a loop does not.**

                         A loop only goes forward — it has no "returning" phase.Recursion can perform work both on the way *
            *down * *(calling phase) and
        on the way * *back up * *(returning phase),
    which is why it can produce behaviors a simple loop cannot.

        -- -

        ##8.5 How Recursion Uses the Stack

        > How does the computer actually * manage * all those recursive calls
    ?

```c void
    fun2(int n)
{
    if (n > 0)
    {
        fun2(n - 1);
        cout << n;
    }
}

void main()
{
    int n = 3;
    func2(n);
}
```

When this runs, here is what the **memory** looks like:

```
┌──────────────────────────┐
│         HEAP             │  ← empty here (no dynamic allocation)
├──────────────────────────┤
│  func2  │  n = 0         │
│  func2  │  n = 1         │  STACK
│  func2  │  n = 2         │  (activation records)
│  func2  │  n = 3         │
│  main   │  n = 3         │
│  [call stack base]       │
└──────────────────────────┘
```

**Step-by-step:**
1. `main` runs → activation record for `n=3` created on stack.
2. `func2(3)` called → new activation record pushed.
3. `func2(2)` called → another pushed.
4. `func2(1)` called → another pushed.
5. `func2(0)` called → base condition hit → **terminates**.
6. `func2(0)` is complete → its activation record **deleted** → control returns to `func2(1)`.
7. `func2(1)` → `func2(2)` → `func2(3)` each complete and are deleted in order.

**Key conclusion:**

> → `func2` has **4 activation records** on the stack because we call `func2` four times (n=3, 2, 1, 0).
>
> The size of memory consumed by a recursive function with `n+1` calls is in the **order of O(n)**.
>
> → **Recursive functions are memory consuming.**

---

## 8.6 Recurrence Relation

**Recurrence relation** is used to find the **time complexity of recursion**.

> ➕ Added: A recurrence relation expresses the time taken by a recursive function in terms of the time taken by smaller inputs. For example, for `fun(n)` that makes one recursive call to `fun(n-1)` and does O(1) other work:
> `T(n) = T(n-1) + 1`, with base case `T(0) = 1`
> Solving this gives **T(n) = O(n)** — matching what we observed from the stack diagram above.
# 8.7 Recurrence Relation — Time Complexity of Recursion

---

> We know recursion calls itself repeatedly — but how do we calculate its **exact time complexity**?
> The answer is a **recurrence relation**:
a formula that expresses the time of a function in terms of the time of its smaller call.

    -- -

    ##Setting Up the Recurrence Relation

    ## #Example Function

```c void
    func(int n)
{
    if (n > 0) // Takes 1 unit of time
    {
        printf("%d", n); // Takes 1 unit of time
        fun(n - 1);      // Takes T(n-1) time
    }
}
```

    If **
    T(n) *
    *is the total time taken by the function,
    then T(n)
equals the **sum of the total number of statements **in the function.

    So :

```
∴ T(n) = 1 + 1 + T(n - 1)
∴ T(n) = T(n - 1) + 2
```

                         * *Base case:
**When `n = 0`, the `if ` condition is false — only that one check runs :

``` T(0) = 1
```

            Here
            * *2 is a constant **,
       so we write it as * * m * * :

``` T(n) = T(n - 1) + m
```

            -- -

            ##Solving the Recurrence — Back Substitution Method

            We repeatedly substitute the formula into itself to find a pattern :

``` T(n) = T(n - 1) + m

            Since T(n - 1) = T(n - 2) + m :
  ∴ T(n) = T(n - 2) + 2m

            Since T(n - 2) = T(n - 3) + m :
  ∴ T(n) = T(n - 3) + 3m = T(n - 4) + 4m

∴ General pattern : T(n) = T(n - k) + k·m
```

                                           * *Now assume * * `n
                            - k = 0`,
       so `k = n`:

```
∴ T(n) = T(n - n) + n·m
∴ T(n) = T(0) + n·m
∴ T(n) = 1 + n·2(∵ m = 2)
```

                  * *Which is order of n → O(n) * *
