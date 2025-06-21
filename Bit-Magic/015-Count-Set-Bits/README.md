# 🔢 Count Set Bits

### 📌 Problem Statement

Write an efficient program to count the number of `1s` (set bits) in the binary representation of a given integer.

---

### 📥 Examples

```txt
Input  : n = 6
Output : 2
// Binary: 110 → Two set bits

Input  : n = 13
Output : 3
// Binary: 1101 → Three set bits
```

---

## ✅ Method 1: Simple Bitwise Loop

Loop through each bit of the number, and increment a counter if the bit is set (`1`).

### 🧠 Logic:

* Use `n & 1` to check if the last bit is `1`
* Right-shift `n` until it becomes `0`

### 💻 Code:

```cpp
#include <bits/stdc++.h>
using namespace std;

unsigned int countSetBits(unsigned int n) {
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    int i = 9;
    cout << countSetBits(i);  // Output: 2
    return 0;
}
```

### ⏱️ Time Complexity:

* `O(log n)`, where `n` is the input number
* Auxiliary Space: `O(1)`

---

## ⚡ Method 2: Brian Kernighan’s Algorithm

A more optimized approach than simple bit-checking.

### 🧠 Logic:

Each time we perform `n = n & (n-1)`, we unset the rightmost set bit.
Repeat until `n` becomes `0`.

### 🔁 Example:

```txt
n = 9 → 1001
Step 1: n = 1001 & 1000 = 1000 (count = 1)
Step 2: n = 1000 & 0111 = 0000 (count = 2)
```

### 💻 Code:

```cpp
#include <iostream>
using namespace std;

class GFG {
public:
    unsigned int countSetBits(int n) {
        unsigned int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};

int main() {
    GFG g;
    int i = 9;
    cout << g.countSetBits(i);  // Output: 2
    return 0;
}
```

### ⏱️ Time Complexity:

* `O(number of set bits)`
* Auxiliary Space: `O(1)`

---

## 🚀 Method 3: Lookup Table (Optimized for Multiple Calls)

Best for situations where multiple queries are made for bit counts.

### 🧠 Logic:

Precompute the number of set bits for all 8-bit numbers (0–255), then use it to compute set bits in 32-bit integer using 4 lookups.

### 💻 Code:

```cpp
#include <bits/stdc++.h>
using namespace std;

int BitsSetTable256[256];

// Initialize lookup table
void initialize() {
    BitsSetTable256[0] = 0;
    for (int i = 1; i < 256; i++)
        BitsSetTable256[i] = (i & 1) + BitsSetTable256[i / 2];
}

int countSetBits(int n) {
    return BitsSetTable256[n & 0xff] +
           BitsSetTable256[(n >> 8) & 0xff] +
           BitsSetTable256[(n >> 16) & 0xff] +
           BitsSetTable256[(n >> 24)];
}

int main() {
    initialize();
    int n = 9;
    cout << countSetBits(n);  // Output: 2
    return 0;
}
```

### ⏱️ Time Complexity:

* `O(1)` (constant time)
* Auxiliary Space: `O(1)` after table is initialized

---

## 📚 Summary Table

| Method                 | Time Complexity | Notes                             |
| ---------------------- | --------------- | --------------------------------- |
| Simple Bitwise Loop    | O(log n)        | Basic and easy to understand      |
| Brian Kernighan’s Algo | O(set bits)     | More efficient, less iterations   |
| Lookup Table           | O(1)            | Fastest for repeated bit counting |

---
