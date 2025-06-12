# 🔍 Prime Number Checker

## 📌 What is a Prime Number?

A **prime number** is a natural number **greater than 1** that has **exactly two distinct positive divisors**:

* `1` and
* the number itself.

### ✅ Examples:

`2, 3, 5, 7, 11, 13, 17, 19...`

> Note:

* `1` is **neither prime nor composite**.
* `2` is the **only even prime number**.

---

## ✨ Key Properties of Prime Numbers

* All prime numbers > 2 are **odd**.
* Every number > 1 is divisible by **at least one prime**.
* Two prime numbers are always **coprime** to each other.
* Any composite number can be expressed as a **product of prime factors** (unique factorization theorem).
* All primes > 3 can be represented as `6n ± 1`.

---

## 🧠 Mathematical Facts and Theorems

* **Wilson's Theorem**:
  A number `p > 1` is prime ⇔ `(p - 1)! ≡ -1 mod p`

* **Fermat’s Little Theorem**:
  If `p` is prime, then for all `1 ≤ a < p`,

  $$
  a^{p-1} \mod p = 1
  $$

* **Goldbach's Conjecture**:
  Every even integer > 2 can be expressed as the sum of two primes.

* **Lemoine's Conjecture**:
  Any odd number > 5 can be written as `odd prime + even semiprime`.

---

## ⚙️ Naive Approach to Check Prime

Check divisibility from 2 to √n.

### ✅ C++ Implementation:

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

int main() {
    isPrime(11) ? cout << "true\n" : cout << "false\n";
    return 0;
}
```

🕒 **Time Complexity**: O(√n)
📦 **Auxiliary Space**: O(1)

---

## ⚡ Optimized Prime Check

To avoid redundant checks:

* Handle 0, 1, 2, 3 separately.
* Skip multiples of 2 and 3.
* Check divisibility from 5 to √n using the pattern: `i` and `i + 2`.

### ⚡ Optimized C++ Code:

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i <= sqrt(n); i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int main() {
    isPrime(11) ? cout << "true\n" : cout << "false\n";
    return 0;
}
```

✅ **Output:**

```
true
```

🕒 **Time Complexity**: O(√n)
📦 **Auxiliary Space**: O(1)

---

## 🤝 Prime vs Co-Prime Numbers

| Feature           | Prime                       | Co-prime                   |
| ----------------- | --------------------------- | -------------------------- |
| Definition        | Only 2 divisors: 1 & itself | No common divisor except 1 |
| Considered as     | Single number               | Pair of numbers            |
| Can be composite? | ❌                           | ✅ (as long as GCD = 1)     |
| Example           | `5` is prime                | `8` and `15` are co-prime  |

---
