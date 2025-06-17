# 🧮 Modular Arithmetic

Modular arithmetic deals with operations involving the **modulus operator (%)**. It plays a key role in number theory, cryptography, competitive programming, and algorithm design.

---

## 📘 Quotient Remainder Theorem

> For any integers `a` and `b` (where `b > 0`),
> there exist **unique integers** `q` (quotient) and `r` (remainder) such that:
> **a = b × q + r**, where `0 ≤ r < b`

### ✅ Example:

```
a = 20, b = 6 → q = 3, r = 2
=> 20 = 6 × 3 + 2
```

---

## ➕ Modular Addition

### Formula:

```cpp
(a + b) % m = ((a % m) + (b % m)) % m
```

### ✅ Example:

```
(15 + 17) % 7 = ((15 % 7) + (17 % 7)) % 7
              = (1 + 3) % 7 = 4
```

---

## ➖ Modular Subtraction

Same idea as addition.

### Formula:

```cpp
(a - b) % m = ((a % m) - (b % m) + m) % m
```

*(Adding `+m` ensures non-negative results.)*

---

## ✖️ Modular Multiplication

### Formula:

```cpp
(a * b) % m = ((a % m) * (b % m)) % m
```

### ✅ Example:

```
(12 * 13) % 5 = ((12 % 5) * (13 % 5)) % 5
              = (2 * 3) % 5 = 6 % 5 = 1
```

---

## ➗ Modular Division

Modular division is **not direct**. It requires the **modular inverse**.

### ❌ Incorrect:

```cpp
(a / b) % m ≠ ((a % m) / (b % m)) % m
```

### ✅ Correct:

```cpp
(a / b) % m = (a * inverse(b, m)) % m
```

---

## 🔄 Modular Inverse

The **modular inverse** of `a` modulo `m` is an integer `x` such that:

```cpp
(a * x) % m = 1
```

It exists **only if `gcd(a, m) = 1`** (i.e., `a` and `m` are coprime).

### ✅ Example:

```
a = 5, m = 7 → 5 * 3 % 7 = 1 → inverse = 3
```

To find inverse when `m` is prime, use **Fermat's Little Theorem**:

```
a^(-1) ≡ a^(m-2) mod m
```

---

## 🚀 Modular Exponentiation (Efficient xⁿ % m)

### Goal:

Compute `(x^n) % m` in **O(log n)** time.

### 🔧 C++ Implementation:

```cpp
#include <bits/stdc++.h>
using namespace std;

int modpower(int x, int n, int m) {
    if (n == 0)
        return 1 % m;
    
    long long u = modpower(x, n / 2, m);
    u = (u * u) % m;
    
    if (n % 2 == 1)
        u = (u * x) % m;
    
    return u;
}

int main() {
    cout << modpower(5, 2, 7) << endl; // Output: 4
    return 0;
}
```

### ⏱ Time Complexity:

```
O(log n) – due to halving the exponent at each step
```

---

## 🧠 Fermat’s Little Theorem

> If `m` is **prime** and `x` is **not divisible by m**, then:

```cpp
x^(m-1) ≡ 1 (mod m)
```

Hence,

```cpp
x^k % m = x^(k % (m - 1)) % m
```

> This is often used in **competitive programming** and **modular inverse calculations**.

---

## ✅ Summary Table

| Operation       | Formula                                                | Exists If                      |
| --------------- | ------------------------------------------------------ | ------------------------------ |
| Addition        | `(a + b) % m`                                          | Always                         |
| Subtraction     | `(a - b + m) % m`                                      | Always                         |
| Multiplication  | `(a * b) % m`                                          | Always                         |
| Division        | `(a * inverse(b)) % m`                                 | `gcd(b, m) = 1`                |
| Inverse (mod m) | `b^(m-2) % m` (Fermat's Theorem, only when m is prime) | `gcd(b, m) = 1` and m is prime |
| Power           | `modpower(x, n, m)`                                    | Always                         |

