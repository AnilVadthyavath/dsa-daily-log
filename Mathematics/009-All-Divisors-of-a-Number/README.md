# 🧮 All Divisors of a Number

## 📌 Problem Statement

Given a natural number `n`, print **all distinct divisors** of it.

---

## 🔍 Example

| Input `n` | Output (All Divisors)   |
| --------- | ----------------------- |
| 10        | 1 2 5 10                |
| 100       | 1 2 4 5 10 20 25 50 100 |
| 125       | 1 5 25 125              |

---

## 🐌 Naive Approach

### 📘 Logic:

Iterate from `1` to `n`, and check if each number divides `n`.

### 🧾 Code:

```cpp
#include <iostream>
using namespace std;

void printDivisors(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            cout << i << " ";
    }
}

int main() {
    cout << "The divisors of 100 are:\n";
    printDivisors(100);
    return 0;
}
```

### ⏱ Time Complexity: `O(n)`

### 📦 Auxiliary Space: `O(1)`

---

## ⚡ Optimized Approach (Using Square Root)

### 📘 Logic:

* Divisors occur in pairs: e.g., for `100`, `(1,100)`, `(2,50)`, `(4,25)`, `(5,20)`, `(10,10)`
* Only loop till `sqrt(n)` and print both divisors `i` and `n/i`
* If `i == n/i`, print it only once (perfect square case)

### 🧾 Code:

```cpp
#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int n) {
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i)
                cout << i << " ";
            else
                cout << i << " " << n / i << " ";
        }
    }
}

int main() {
    cout << "The divisors of 100 are:\n";
    printDivisors(100);
    return 0;
}
```

### 🧾 Output (unordered):

```
1 100 2 50 4 25 5 20 10
```

### ⏱ Time Complexity: `O(√n)`

### 📦 Auxiliary Space: `O(1)`

---

## 🧹 Sorted Output Version

To get divisors in ascending order.

### 🧾 Code:

```cpp
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void printDivisors(int n) {
    vector<int> largeDivisors;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
            if (i != n / i)
                largeDivisors.push_back(n / i);
        }
    }

    for (int i = largeDivisors.size() - 1; i >= 0; i--)
        cout << largeDivisors[i] << " ";
}

int main() {
    cout << "The divisors of 100 in sorted order are:\n";
    printDivisors(100);
    return 0;
}
```

### ✅ Output:

```
1 2 4 5 10 20 25 50 100
```

### ⏱ Time Complexity: `O(√n)`

### 📦 Auxiliary Space: `O(√n)` (for sorting using a vector)

---

## 📌 Summary

| Method      | Time Complexity | Space Complexity | Sorted Output | Notes                         |
| ----------- | --------------- | ---------------- | ------------- | ----------------------------- |
| Naive       | `O(n)`          | `O(1)`           | Yes           | Simple but slow for large `n` |
| Square Root | `O(√n)`         | `O(1)`           | No            | Fast but unsorted             |
| Sorted √n   | `O(√n)`         | `O(√n)`          | Yes           | Best of both worlds           |

