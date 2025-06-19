## 🔍 Check if K-th Bit is Set or Not

Given an integer `n`, check whether the **K-th bit** (1-based index) is **SET** (`1`) or **NOT SET** (`0`) in its binary representation.

---

### 🧠 Concept

There are two common approaches to check the K-th bit:

* **Using the Left Shift Operator**
* **Using the Right Shift Operator**

---

### 📌 Approach 1: Using Left Shift Operator

**Idea:**

1. Left shift `1` by `k-1` to get a mask with only the K-th bit set.
2. Use bitwise AND `&` with `n`. If result is non-zero, the K-th bit is set.

**Example:**

```cpp
int temp = 1 << (k - 1);
if (n & temp)
    cout << "SET";
else
    cout << "NOT SET";
```

**Dry Run:**

* Input: `n = 75`, `k = 4`
* `temp = 1 << 3 = 8` → binary: `00001000`
* `n = 75` → binary: `01001011`
* `n & temp = 01001011 & 00001000 = 00001000 ≠ 0`, so **SET**

**Implementation:**

```cpp
#include <bits/stdc++.h>
using namespace std;

void isKthBitSet(int n, int k) {
    if (n & (1 << (k - 1)))
        cout << "SET";
    else
        cout << "NOT SET";
}

int main() {
    int n = 5, k = 1;
    isKthBitSet(n, k);
    return 0;
}
```

**Output:**

```
SET
```

---

### 📌 Approach 2: Using Right Shift Operator

**Idea:**

1. Right shift `n` by `k-1`. This brings the K-th bit to the least significant position.
2. Use `& 1` to check if the least significant bit is set.

**Example:**

```cpp
if ((n >> (k - 1)) & 1)
    cout << "SET";
else
    cout << "NOT SET";
```

**Implementation:**

```cpp
#include <iostream>
using namespace std;

void isKthBitSet(int n, int k) {
    if ((n >> (k - 1)) & 1)
        cout << "SET";
    else
        cout << "NOT SET";
}

int main() {
    int n = 5, k = 1;
    isKthBitSet(n, k);
    return 0;
}
```

**Output:**

```
SET
```

---

### ⏱️ Complexity Analysis

* **Time Complexity:** `O(1)`
* **Auxiliary Space:** `O(1)`

Both approaches are **constant time** and **space-efficient**, making them ideal for performance-critical applications.

