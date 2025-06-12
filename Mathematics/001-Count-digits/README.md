# 🧮 Count Digits

## Problem Statement

Given a number `N`, the task is to return the count of digits in this number.

---

## 🔍 Example

```
Input:  N = 3456  
Output: 4
```

---

## 🧠 Approach: Simple Iterative Solution

The integer entered by the user is stored in the variable `n`. The while loop is executed until `n != 0`. In each iteration, `n` is divided by 10 and a counter is incremented.

For example, given `n = 3456`:

* After 1st iteration: `n = 345`, `count = 1`
* After 2nd iteration: `n = 34`, `count = 2`
* After 3rd iteration: `n = 3`, `count = 3`
* After 4th iteration: `n = 0`, `count = 4`

Now the condition `n != 0` becomes false, so the loop ends, and we return the final count.

---

## 🧾 Code (C++)

```cpp
// Iterative C++ program to count number of digits in a number
#include <bits/stdc++.h>
using namespace std;

int countDigit(long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}

// Driver code
int main(void)
{
    long long n = 345289467;
    cout << "Number of digits : " << countDigit(n);
    return 0;
}
```

---

## 📤 Output

```
Number of digits : 9
```

---

## ⏱️ Time & Space Complexity

* **Time Complexity**: `O(log₁₀(n))` or `θ(number of digits)`
* **Auxiliary Space**: `O(1)` (constant space)

---

