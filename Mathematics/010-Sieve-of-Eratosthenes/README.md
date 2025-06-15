# 🧮 Sieve of Eratosthenes

## 📌 Problem Statement

Given a number `n`, print all **prime numbers ≤ n**.

---

## 🔍 Examples

| Input | Output                    |
| ----- | ------------------------- |
| 10    | 2 3 5 7                   |
| 20    | 2 3 5 7 11 13 17 19       |
| 30    | 2 3 5 7 11 13 17 19 23 29 |

---

## 💡 Why Sieve?

The **Sieve of Eratosthenes** is one of the most efficient ways to find all primes ≤ `n` when `n` is ≤ 10⁷.

---

## 🧠 Algorithm Overview

1. Create a boolean array `prime[0..n]`, initialized as `true`.
2. Set `prime[0]` and `prime[1]` to `false` (0 and 1 are not prime).
3. For every number `p` from 2 to √n:

   * If `prime[p]` is `true`, mark all multiples of `p` from `p*p` to `n` as `false`.
4. All numbers still marked `true` in the array are **prime**.

---

## 🎯 Key Insight

For each prime `p`, we start marking from `p*p` because all smaller multiples of `p` would have been marked already by smaller primes.

---

## 🧾 C++ Code Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n) {
    // Step 1: Initialize the prime array
    vector<bool> prime(n + 1, true);

    prime[0] = prime[1] = false; // 0 and 1 are not prime

    // Step 2: Mark non-primes using sieve logic
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            // Mark all multiples of p starting from p*p
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Step 3: Print all prime numbers
    for (int i = 2; i <= n; i++) {
        if (prime[i])
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n = 30;
    cout << "Prime numbers up to " << n << ":\n";
    SieveOfEratosthenes(n);
    return 0;
}
```

---

## ✅ Output

```
Prime numbers up to 30:
2 3 5 7 11 13 17 19 23 29
```

---

## 📈 Time & Space Complexity

| Metric           | Complexity          |
| ---------------- | ------------------- |
| Time Complexity  | `O(n * log(log n))` |
| Space Complexity | `O(n)`              |

---

## 📌 Summary Table

| Step           | Description                                        |
| -------------- | -------------------------------------------------- |
| Initialization | Set all `prime[i] = true` for `i ∈ [2, n]`         |
| Sieve Step     | Mark multiples of each prime starting from `p*p`   |
| Result         | All indices `i` where `prime[i] == true` are prime |

