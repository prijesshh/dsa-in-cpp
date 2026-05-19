# Arrays

## Concept: What is an Array?

An **array** is a collection of similar data types grouped under one name. Key characteristics:

- It's also called a **vector** (in some programming languages, this refers to a dynamic array)
- Every element in an array can be accessed and identified using an **index value**
- This concept is supported by most modern programming languages (C, C++, Java, Python, etc.)

---

## How It Works: Indexing and Access

Arrays use **zero-based indexing**, meaning the first element is at index `0`, the second at index `1`, and so on.

### Basic Syntax

For an array with 5 elements:

```c
int A[5];        // Declaration: creates space for 5 integers
A[2] = 15;       // Access: assign value 15 to element at index 2
```

In this example:
- `A` is the array name
- `5` is the size (capacity)
- `A[2]` accesses the element at index 2

Here's a visual representation:

```
Index:    0    1    2    3    4
Array A: [ ]  [ ]  [15] [ ]  [ ]
```

---

## Example: Declaration and Initialization

There are several ways to declare and initialize an array:

### 1. Declaration Without Initialization
```c
int A[5];
```

The array is created with **garbage values** (uninitialized memory):

```
Index:    0    1    2    3    4
Array A: [?]  [?]  [?]  [?]  [?]
         (Garbage)
```

> **Note:** Uninitialized arrays contain random values left in memory from previous operations. Always initialize arrays before use!

### 2. Full Initialization
```c
int A[5] = {2, 4, 6, 8, 10};
```

All elements are assigned explicitly:

```
Index:    0    1    2    3    4
Array A: [2]  [4]  [6]  [8]  [10]
```

### 3. Partial Initialization
```c
int A[5] = {2, 4};
```

Only the first two elements are initialized; remaining elements are filled with `0`:

```
Index:    0    1    2    3    4
Array A: [2]  [4]  [0]  [0]  [0]
```

### 4. Initialize All Elements to Zero
```c
int A[5] = {0};
```

All elements are explicitly set to `0`:

```
Index:    0    1    2    3    4
Array A: [0]  [0]  [0]  [0]  [0]
```

### 5. Size Inferred from Initialization
```c
int A[] = {2, 4, 6, 8, 10};
```

The compiler automatically determines the array size (5 in this case) based on the number of elements provided:

```
Index:    0    1    2    3    4
Array A: [2]  [4]  [6]  [8]  [10]
```

---

## Traversing an Array

To access **all elements** in an array, you can **traverse** through it using a loop:

```c
int A[5] = {2, 4, 6, 8};

for (i = 0; i < 5; i++) 
{
    printf("%d", A[i]);
}
```

This loop prints each element sequentially: `2 4 6 8`

---

## Different Ways to Access Elements

The elements in an array can be accessed through multiple methods — all equivalent:

Given the array:
```c
int A[5] = {2, 4, 6, 8};
```

To access the element at **index 2** (value `6`), you can use:

```c
A[2]           // Direct index access
2[A]           // Reverse index syntax (unusual but valid in C!)
*(A + 2)       // Pointer arithmetic: dereference pointer offset
```

All three expressions retrieve the same value: `6`

