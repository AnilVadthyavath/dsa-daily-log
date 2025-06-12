# 🔁 LCM (Least Common Multiple) of Two Numbers

## 📌 Problem Statement

The **LCM (Least Common Multiple)** of two numbers is the **smallest positive integer** that is **divisible by both** numbers.

### 🔢 Examples

* **Input:** `a = 6`, `b = 9`
  **Output:** `18`
  **Explanation:**
  Multiples of 6 → `6, 12, 18, 24, ...`
  Multiples of 9 → `9, 18, 27, 36, ...`
  → Smallest common multiple = **18**

---

## 🧠 Approach

### 📌 Key Concepts:

* LCM is always ≥ `max(a, b)`
* LCM of `a` and `b` can be calculated using:

  $$
  \text{LCM}(a, b) = \frac{a \times b}{\text{GCD}(a, b)}
  $$

### ✅ Why GCD-based Method?

* Efficient
* Avoids brute-force iterations
* Safe for large values (with proper overflow handling)

---

## 🧾 Code (C++)

```cpp
#include <iostream>
using namespace std;

// Function to calculate GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM using GCD
int lcm(int a, int b) {
    if (a == 0 || b == 0)
        return 0; // LCM of 0 with any number is 0

    return (a * b) / gcd(a, b);
}

int main() {
    int a = 6, b = 9;
    cout << "LCM of " << a << " and " << b << " is " << lcm(a, b) << endl;
    return 0;
}
```

---

## 📤 Output

```
LCM of 6 and 9 is 18
```

---

## 🧮 Dry Run

**Input:** `a = 6`, `b = 9`

* Step 1: `gcd(6, 9)` → 3
* Step 2: `lcm = (6 * 9) / 3 = 54 / 3 = 18`
  → ✅ Final LCM = **18**

---

## ⏱️ Complexity

* **Time Complexity:** `O(log(min(a, b)))` (for GCD)
* **Auxiliary Space:** `O(1)`

---

## 🧾 Edge Case: Zero Handling

If either number is zero, LCM is **0**, because:

> Any number × 0 = 0, and 0 divided by anything is 0.

---
