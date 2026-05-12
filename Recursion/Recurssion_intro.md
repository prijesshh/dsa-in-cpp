# 8. Recursion

---

> What if a function could solve a problem by solving a smaller version of *the same problem*?
> That's the idea behind **recursion** — and it's one of the most elegant (and tricky) tools in programming.

---

## 8.1 What is Recursion?

**A function calling itself is called a recursive function.**

Two rules every recursive function must follow:
- It must **call itself** (with a smaller/simpler input).
- There must be some **base condition that terminates the recursion** — otherwise it runs forever.

### General Structure

```c
type fun(parameter) {
    if (base condition) {
        fun(parameter);   // recursive call
    }
}
```

---

## 8.2 Example 1 — Printing in Descending Order

```c
void fun(int n) {
    if (n > 0) {
        cout << n;
        fun(n - 1);
    }
}

void main() {
    int n = 3;
    fun(n);
}
```

**Execution trace:**

- `main` calls `fun(3)` → prints `3`, calls `fun(2)`
- `fun(2)` → prints `2`, calls `fun(1)`
- `fun(1)` → prints `1`, calls `fun(0)`
- `fun(0)` → base condition `n > 0` is false → **terminates**

**Output: `3 2 1`**

> We can trace a **tree** of any recursive function to understand its execution.

---

## 8.3 Example 2 — Printing in Ascending Order

```c
void fun2(int n) {
    if (n > 0) {
        fun2(n - 1);   // recursive call FIRST
        cout << n;     // print AFTER returning
    }
}

void main() {
    int n = 3;
    fun2(n);
}
```

**Recursion tree:**

```
        fun2(3)
       /        \
   fun2(2)       ↑ 3
   /      \
fun2(1)    ↑ 2
  /    \
fun2(0)  ↑ 1
  |
terminate
```

**Output: `1 2 3`**

> Notice how swapping the order of the `cout` and the recursive call **reverses the output** — this is a key insight into how recursion works.

---

## 8.4 The Two Phases of Recursion

**Recursion has 2 phases:**

```c
void func(param) {
    // ... → this is the CALLING PHASE (ascending phase)
    {
        func(param);   // recursive call
        // ... → this is the RETURNING PHASE (descending phase)
    }
}
```

| Phase | Also Called | When it happens |
|---|---|---|
| Calling phase | Ascending phase | As function calls are being made deeper |
| Returning phase | Descending phase | As functions finish and return back up |

### Recursion vs Loop — What's the Difference?

Both recursion and loops execute something repeatedly. So what's different?

> **→ Recursion has both an ascending phase and a descending phase, but a loop does not.**

A loop only goes forward — it has no "returning" phase. Recursion can perform work both on the way **down** (calling phase) and on the way **back up** (returning phase), which is why it can produce behaviors a simple loop cannot.

---

## 8.5 How Recursion Uses the Stack

> How does the computer actually *manage* all those recursive calls?

```c
void fun2(int n) {
    if (n > 0) {
        fun2(n - 1);
        cout << n;
    }
}

void main() {
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

---

## 📚 Quick Recap

- A **recursive function** is one that calls itself.
- Every recursive function needs a **base condition** to terminate — without it, you get infinite recursion (stack overflow).
- Swapping the position of the recursive call vs. the work (e.g., `cout`) **changes the output order** — this is the calling vs. returning phase at work.
- **Recursion has two phases:** calling (ascending) phase and returning (descending) phase. A loop only has a forward phase.
- Recursion uses the **call stack** — each recursive call creates an activation record on the stack.
- A recursive function called `n+1` times uses **O(n) space** on the stack — making recursive functions **memory consuming**.
- The time complexity of a recursive function is analyzed using a **recurrence relation**.

---
