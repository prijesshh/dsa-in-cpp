# Data Structures and Algorithms

---

## Why Does Any of This Matter?

> Why can your computer open a 500MB PDF in seconds? Why can a search engine find results from billions of pages almost instantly?
> The answer lies in how data is **organized and managed in memory**  and that's exactly what Data Structures & Algorithms is about.

---

## 1. Core Terminology

**Data structure** means the arrangement of a collection of data items so that they can be utilized effectively. It is the **management of data on the main memory**.

### Real-World Analogy

Let's assume we have to access a file named `dsa.pdf`. When we double-click on the file to open it, the file is copied from disk to the main memory  and the management of data on that main memory is **data structure**.

> The management of data on the **disk** is called a **database**.

---

## 2. Related Concepts: Data Warehouse & Big Data

### Data Warehouse

We store large amounts of old data across multiple disks (an array of disks)  this storage is called a **data warehouse**. That data is very helpful for generating insights by analyzing it, and the algorithms written to analyze them are called **data mining algorithms**.

### Big Data

With the boom of the internet, large amounts of data are being generated day by day which can't be handled by traditional databases. This large data is called **big data**.

---

## 3. Stack vs Heap Memory

> How does your program actually use RAM? Why do some variables disappear after a function ends, but others stick around?

Stack and heap are both parts of memory  **stack is static memory** whereas **heap is dynamic memory**.

---

### 3.1 Static Memory Allocation (Stack)

First, we need to know that memory is divided into different parts this is called **segmentation of memory**, and each segment has a maximum of **64KB** of storage.

A segment is further divided into three parts:
- **Code section**
- **Stack section**
- **Heap section**

A program uses main memory by dividing into these different sections.

**How it works:**
1. The machine code of the program is first loaded into the **code section**.
2. The CPU then executes the machine code.

#### Example — Single Function

```c
void main() {
    int a;
    float b;
}
```

- Assume `int` = 2 bytes, `float` = 4 bytes → total **6 bytes** needed.
- This memory is allocated in the **stack** for the function this block is called an **activation record** or **stack frame**.
- Since the amount of memory required is determined at **compile time**, this is called **static memory allocation**.

#### Example — Multiple Function Calls

```c
void func2(int i) {
    int a;
}

void func1() {
    int x;
    func2(x);
}

void main() {
    int a;
    int b;
    func1();
}
```

**Execution flow (step by step):**

1. Machine code is copied to the **code section**.
2. `main()` starts executing → activation record created for `a` and `b`.
3. `main()` calls `func1()` → control switches to `func1()` → new activation record created for `x`.
4. `func1()` calls `func2()` → control switches to `func2()` → new activation record created for `a` and `i`.
5. `func2()` is now **on the top of the stack**.
6. `func2()` finishes → its activation record is **deleted**, control returns to `func1()`.
7. `func1()` finishes → its activation record is **deleted**, control returns to `main()`.
8. `main()` finishes → its activation record is also **deleted**.

> 📝 **Key takeaway:** Stack works on a **LIFO (Last In, First Out)** mechanism. The size of stack memory is decided by the **compiler automatically**, and it is also **deleted automatically**.

---

### 3.2 Dynamic Memory Allocation (Heap)

> **Heap** means *piling up*. It should be treated as a **resource** we use it when needed and release it when our work is done.

Key differences from stack:
- A program can access **stack memory directly**.
- A program **cannot access heap memory directly** we access it using a **pointer**.

#### Example — Heap Allocation

```cpp
void main() {
    int *p;            // Assume pointer is 2 bytes — memory auto-allocated in stack
    p = new int[5];    // "new" allocates memory for 5 ints in the heap;
                       // p stores the starting address of the array(which on the heap)
    delete[] p;        // After work is done, we must delete heap memory to avoid memory loss
    p = NULL;          // Now p points to nothing
}
```

> Failing to call `delete[]` after using `new` causes a **memory leak** — heap memory stays reserved even after the program no longer needs it.

---

## 4. Types of Data Structures

There are **2 types** of data structures:

1. **Physical Data Structures** — define how data is actually stored in memory
2. **Logical Data Structures** — define the discipline/rules for operating on that stored data

---

### 4.1 Physical Data Structures

#### Array
- A collection of data elements in **contiguous memory locations**.
- Used when we **know the maximum size** of data elements in advance.
- Can be created in **stack or heap**.

#### Linked List
- It is basically a **dynamic structure**.
- A collection of **nodes**, where each node contains **data** and a **link to the next node**.
- The length of the list can be **increased or reduced dynamically**.
- The linked list itself is created in **heap**, and a **head pointer** in the stack points to the heap.

---

### 4.2 Logical Data Structures

| Data Structure | Category |
|---|---|
| Stack | Linear |
| Queue | Linear |
| Trees | Non-linear |
| Graphs | Non-linear |
| Hash Table | Linear / Tabular |

**Physical vs Logical — How they relate:**

- **Physical data structures** are meant for *storing* data.
- When we want to *operate* on that data (add, sort, search, etc.), the discipline followed for performing those operations is defined by **logical data structures**.
- Logical data structures are **implemented using** physical data structures.

---

## 5. ADT — Abstract Data Type

> **Abstract** means *hiding internal details*.

A **data type** is defined by:
- The **representation** of data (how it's stored)
- The **operations** that can be performed on the data

### Example — The List ADT

```
List:  8, 3, 9, 4, 6, 10, 12
Index: 0, 1, 2, 3, 4,  5,  6
```

To represent this list we need:
- Space for storing elements
- A capacity

We can represent this list using **either an array or a linked list** the internal representation is hidden from the user. That's the "abstract" part.

---

### 5.1 Operations on the List ADT

#### 1. `add(element)` / `append(element)` — Add to end

```
add(15)
List:  8, 3, 9, 4, 6, 10, 12, 15
Index: 0, 1, 2, 3, 4,  5,  6,  7
```

#### 2. `add(index, element)` / `insert(index, element)` — Insert at position

```
add(6, 20)
List:  8, 3, 9, 4, 6, 10, 20, 12, 15
Index: 0, 1, 2, 3, 4,  5,  6,  7,  8
```

#### 3. `remove(index)` — Remove at position

```
remove(6)
List:  8, 3, 9, 4, 6, 10, 12, 15
Index: 0, 1, 2, 3, 4,  5,  6,  7
```

#### 4. `set(index, element)` / `replace(index, element)` — Update at position

```
set(3, 25)
List:  8, 3, 9, 25, 6, 10, 12, 15
Index: 0, 1, 2,  3, 4,  5,  6,  7
```

#### 5. `get(index)` — Retrieve element at position

```
get(7)
Output → 15
```

#### 6. `search(key)` / `contains(key)` — Find element

```
search(9)
Output → 2   (returns the index)
```

#### 7. `sort()` — Sort the list

---

## 📚 Quick Recap

- **Data structure** = managing data in **main memory**; **database** = managing data on **disk**.
- **Data warehouse** stores large amounts of historical data; **data mining algorithms** extract insights from it.
- **Big data** refers to data volumes too large for traditional databases to handle.
- **Stack memory** is static — size determined at compile time, managed automatically via activation records (LIFO).
- **Heap memory** is dynamic  accessed via **pointers**, must be manually released with `delete[]` to avoid memory leaks.
- **Physical data structures** (`array`, `linked list`) define *how* data is stored.
- **Logical data structures** (`stack`, `queue`, `tree`, `graph`, `hash table`) define *how* data is operated on.
- **ADT (Abstract Data Type)** hides implementation details — defined only by its data representation and the operations it supports.
- A **List ADT** supports: `add`, `insert`, `remove`, `set`, `get`, `search`, and `sort`.

---
