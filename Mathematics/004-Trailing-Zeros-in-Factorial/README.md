# 🔢 Trailing Zeros in Factorial

## 🧩 Problem Statement

In the realm of numbers, some mysteries lie quietly at the end — **Trailing Zeros**.

> **Task**:
> Given a number `n`, count the number of **trailing zeros** in `n!` (factorial of `n`).

### 🧪 Examples

```
Input: 5
Output: 1
// 5! = 120 → 1 trailing zero

Input: 20
Output: 4
// 20! = 2432902008176640000 → 4 trailing zeros

Input: 100
Output: 24
// 100! has 24 trailing zeros
```

---

## 🧠 Approaches

### 1️⃣ Naive Approach (Not Recommended)

* Calculate `n!`
* Divide by 10 repeatedly until the remainder is not 0
* Count how many times this happens

> ❌ This approach is not feasible for large `n` due to **overflow** when computing factorial.

---

### 2️⃣ Efficient Approach (Best)

### 🧠 Trailing Zeros in `n!` — Why We Count 5s

* A trailing zero comes from multiplying `10 = 2 × 5`.
* In `n!`, 2s are always more frequent than 5s.
* So, number of trailing zeros = **number of times 5 is a factor** in `n!`.

---

### ✅ Example: `n = 10`

```
10! = 1×2×3×4×5×6×7×8×9×10 = 3628800
```

Let’s count how many 5s:

* 5 → gives one 5
* 10 → gives another 5
  → **2 total 5s**
  → **2 pairs of (2 × 5)** → ✅ 2 trailing zeroes

No need to count 2s — they're always more than enough.

---

### 🔁 Efficient Code (No Overflow):

```cpp
int count = 0;
for (int i = 5; i <= n; i *= 5)
    count += n / i;
```

✔ Handles large `n`
✔ Avoids factorial calculation
✔ Counts 5s from `5, 25, 125, ...`

A trailing zero is produced by multiplying `2 × 5`.
Since the number of 2s is always greater than 5s in factorials, we only need to **count the number of 5s** in the prime factorization of numbers from `1 to n`.

#### 🔣 Formula:

```
Trailing 0s in n! = ⌊n/5⌋ + ⌊n/25⌋ + ⌊n/125⌋ + ...
```

This sums up all the multiples of 5, 25, 125, etc. in the factorial.

---

## 🧾 Code (C++)

```cpp
// C++ program to count trailing 0s in n!
#include <iostream>
using namespace std;

// Function to return trailing 0s in factorial of n
int findTrailingZeros(int n)
{
    if (n < 0) // Edge case for negative numbers
        return -1;

    int count = 0;

    // Count factors of 5, 25, 125, ...
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;

    return count;
}

// Driver Code
int main()
{
    int n = 100;
    cout << "Count of trailing 0s in " << n << "! is "
         << findTrailingZeros(n);
    return 0;
}
```

---

## 📤 Output

```
Count of trailing 0s in 100! is 24
```

---

## ⏱️ Time & Space Complexity

* **Time Complexity**: `O(log₅(n))`
* **Auxiliary Space**: `O(1)`

---
