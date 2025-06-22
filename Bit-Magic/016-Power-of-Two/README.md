# 🔢 Power of Two

## 🧩 Problem Statement

Given a positive integer `n`, write a function to check whether it is a **power of 2**.

### ✅ Examples

```txt
Input: n = 4
Output: Yes
Explanation: 2^2 = 4

Input: n = 32
Output: Yes
Explanation: 2^5 = 32
```

---

## 💡 Approach 1: Logarithmic Method

### 🧠 Idea

Take the logarithm of the number with base 2.
If the result is an integer (i.e., `ceil(log2(n)) == floor(log2(n))`), then the number is a power of 2.

### 🧪 C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to check if n is a power of 2
bool isPowerOfTwo(int n) {
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

// Driver code
int main() {
    isPowerOfTwo(31) ? cout << "Yes" << endl : cout << "No" << endl;
    isPowerOfTwo(64) ? cout << "Yes" << endl : cout << "No" << endl;
    return 0;
}
```

### 🧾 Output

```txt
No
Yes
```

---

## 💡 Approach 2: Brian Kernighan’s Algorithm (Bit Manipulation)

### 🧠 Idea

If `n` is a power of 2, it has **only one set bit** in its binary representation.
So, `n & (n - 1)` will be 0 **only if** `n` is a power of 2.

#### 🔍 Example:

```txt
n = 4 = 100 (binary)
n - 1 = 3 = 011 (binary)
100 & 011 = 000 → Hence, 4 is a power of 2
```

### 🧪 C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Function to check if n is a power of 2
bool isPowerofTwo(long long n) {
    return (n != 0) && ((n & (n - 1)) == 0);
}

// Driver code
int main() {
    isPowerofTwo(30) ? cout << "Yes\n" : cout << "No\n";
    isPowerofTwo(128) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
```

### 🧾 Output

```txt
No
Yes
```

---

## ⏱️ Time & Space Complexity

| Metric          | Value |
| --------------- | ----- |
| Time Complexity | O(1)  |
| Auxiliary Space | O(1)  |

---

## 📚 Summary

| Approach         | Method        | Notes                                         |
| ---------------- | ------------- | --------------------------------------------- |
| Logarithmic      | `log2(n)`     | Needs `math.h` and works well for small ints. |
| Bit Manipulation | `n & (n - 1)` | Fastest and cleanest for checking powers of 2 |

---
