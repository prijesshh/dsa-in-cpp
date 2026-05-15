# Taylor Series Using Horner's Rule

*Computing e^x term by term seems straightforward but how many multiplications does it actually take? And can we do better?*

## The Taylor Series of e^x

The Taylor series expansion of e^x up to n terms is:

```
e^x = 1 + x/1! + x²/2! + x³/3! + x⁴/4! + ...   (upto n terms)
```

## Counting the Multiplications — Naïve Approach

Let's have a look at the **number of multiplications** we have to do for each term:

```
1 + x/1 + x²/2! + x³/3! + x⁴/4! + ...

= 1 + x/(1) + (x×x)/(1×2) + (x×x×x)/(1×2×3) + (x×x×x×x)/(1×2×3×4) + ...
```

Multiplications per term:

| Term | Multiplications needed |
|---|---|
| `1` | 0 |
| `x/1` | 0 |
| `x²/2!` | 2 |
| `x³/3!` | 4 |
| `x⁴/4!` | 6 |
| ... | ... |

∴ Total number of multiplications:

```
= 0 + 0 + 2 + 4 + 6 + ...
= 2(1 + 2 + 3 + 4 + ...)
≈ n(n+1) / 2
= O(n²)
```

> So the naïve approach of computing each term independently takes **O(n²) multiplications** — quadratic time.

## Reducing to O(n) — Using Horner's Rule

We can reduce the number of multiplications from **quadratic to linear** by factoring out terms cleverly.

**Example for e^x with n = 4 terms:**

Starting expression:

```
e^x = 1 + x/1 + x²/2! + x³/3! + x⁴/4!
```

**Step 1 — Factor out `x/1` from the last 3 terms:**

```
= 1 + x/1 [ 1 + x/2 + x²/(2×3) + x³/(2×3×4) ]
```

**Step 2 — Factor out `x/2` from the last 2 terms inside:**

```
= 1 + x/1 [ 1 + x/2 [ 1 + x/3 + x²/(3×4) ] ]
```

**Step 3 — Factor out `x/3` from the last term inside:**

```
= 1 + x/1 [ 1 + x/2 [ 1 + x/3 [ 1 + x/4 ] ] ]
```

Here we have to do multiplications in **O(n)** one multiplication per bracket level.

> We use this concept in **Horner's Rule**.

## Why This Matters

| Approach | Multiplications | Time Complexity |
|---|---|---|
| Naïve (term by term) | 0 + 0 + 2 + 4 + 6 + ... | O(n²) |
| Horner's Rule (nested factoring) | One per term | O(n) |

> Horner's Rule can be implemented **recursively** the innermost bracket `[1 + x/4]` is evaluated first, then each outer bracket uses that result. This makes it a natural fit for a recursive function where each call handles one level of nesting, working from the inside out.
