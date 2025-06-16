# ⚡ Computing Power – `x^n`

## 🧠 Problem Statement

Given two integers `x` and `n`, compute `xⁿ`.
Assume `x` and `n` are small enough to avoid overflow.

---

## 🧪 Examples

| x | n | Output |
| - | - | ------ |
| 2 | 3 | 8      |
| 7 | 2 | 49     |

---

## 🔹 Naive Approach – Iterative Multiplication

Multiply `x` exactly `n` times using a loop.

### 🧾 C++ Code (Naive)

```cpp
#include <bits/stdc++.h>
using namespace std;

long long power(int x, unsigned n) {
    long long result = 1;
    for (int i = 0; i < n; i++)
        result *= x;
    return result;
}

int main() {
    int x = 2;
    unsigned n = 3;
    cout << power(x, n) << endl;
    return 0;
}
```

### ✅ Output

```
8
```

### ⏱ Time & Space

| Metric          | Complexity |
| --------------- | ---------- |
| Time Complexity | O(n)       |
| Auxiliary Space | O(1)       |

---

## 🔸 Optimized Approach – Divide and Conquer (Exponentiation by Squaring)

### Key Idea:

Use the formula:

* If `n % 2 == 0`:
  `power(x, n) = power(x, n/2) * power(x, n/2)`
* If `n % 2 != 0`:
  `power(x, n) = x * power(x, n/2) * power(x, n/2)`

To **avoid repeated subproblem calculation**, store `power(x, n/2)` once.

---

### 🧾 C++ Code (Optimized Recursive)

```cpp
#include <bits/stdc++.h>
using namespace std;

int power(int x, unsigned int n) {
    if (n == 0)
        return 1;

    int temp = power(x, n / 2);

    if (n % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

int main() {
    int x = 2;
    unsigned int n = 3;
    cout << power(x, n) << endl;
    return 0;
}
```

### ✅ Output

```
8
```

---

## 🧮 Time & Space Complexity

| Metric          | Complexity                  |
| --------------- | --------------------------- |
| Time Complexity | O(log n)                    |
| Auxiliary Space | O(log n) – due to recursion |

---

## 📌 Summary Table

| Method    | Time     | Space    | Notes                            |
| --------- | -------- | -------- | -------------------------------- |
| Naive     | O(n)     | O(1)     | Easy but inefficient for large n |
| Optimized | O(log n) | O(log n) | Efficient; uses Divide & Conquer |

