# 🧮 Prime Factorization

## 📌 What is a Prime Factor?

A **prime factor** is a factor of a number that is a **prime number**.
It means:

> Find the prime numbers that multiply together to give the original number.

### 🔹 Example:

* Prime factors of **15** → `3 × 5`
* Prime factors of **12** → `2 × 2 × 3`
* Prime factors of **315** → `3 × 3 × 5 × 7`

---

## 🧠 Key Facts About Prime Factorization

* ✅ Every number has a **unique set** of prime factors.
* 🧩 This is called the **Fundamental Theorem of Arithmetic**.
* 🧮 Used in:

  * Divisibility
  * Simplifying fractions
  * Finding common denominators
  * **Cryptography** (e.g., RSA algorithm)

---

## 🚀 Algorithms to Find Prime Factors

### 🔸 Naive Method

**Steps:**

1. While `n` is divisible by 2, print 2 and divide `n`.
2. For `i = 3` to `√n`, do:

   * While `i` divides `n`, print `i` and divide `n`.
3. If `n > 2`, print `n` (it’s a prime itself).

### ✅ C Code (Naive):

```cpp
#include <stdio.h>
#include <math.h>

void primeFactors(int n) {
    while (n % 2 == 0) {
        printf("%d ", 2);
        n /= 2;
    }

    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }

    if (n > 2)
        printf("%d", n);
}

int main() {
    int n = 315;
    primeFactors(n);
    return 0;
}
```

### 🧾 Output:

```
3 3 5 7
```

### 🕒 Time Complexity: `O(√n)`

### 📦 Auxiliary Space: `O(1)`

---

## 🔹 Optimized C++ Approach

**Optimization**:

* Handle 2 and 3 separately.
* Loop from 5 to √n using step size of 6 (`i` and `i + 2`).
* This skips unnecessary checks (like 6, 8, 10… which are divisible by 2 or 3).

### ⚡ C++ Code:

```cpp
#include <iostream>
#include <cmath>
using namespace std;

void printPrimeFactors(int n) {
    if (n <= 1)
        return;

    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    while (n % 3 == 0) {
        cout << 3 << " ";
        n /= 3;
    }

    for (int i = 5; i * i <= n; i += 6) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
        while (n % (i + 2) == 0) {
            cout << (i + 2) << " ";
            n /= (i + 2);
        }
    }

    if (n > 3)
        cout << n;

    cout << endl;
}

int main() {
    int n = 315;
    printPrimeFactors(n);
    return 0;
}
```

### 🧾 Output:

```
3 3 5 7
```

---

## 🔐 Applications in Cryptography

* Prime factorization is **core** to **RSA encryption**.
* **Breaking encryption** relies on the difficulty of factoring large numbers.

---
