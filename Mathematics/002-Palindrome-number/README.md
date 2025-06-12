# 🔁 Palindrome Numbers

## Problem Statement

Given an integer, write a function that returns `true` if the number is a **palindrome**, else `false`.

> A **palindrome number** is a number that reads the same backward as forward.
>
> 📌 Example:
> `Input: 12321 → Output: true`
> `Input: 1451  → Output: false`

---

## 🧠 Approach: Reversing the Number

To check if a number is a palindrome:

* We reverse the digits of the number.
* Then compare the reversed number with the original number.
* If both are equal, the number is a palindrome.

> ⚠️ This approach works for numbers with fewer than `10^18` digits, since it relies on numeric datatypes like `long long int` which have limitations.

---

## 🧾 Code (C++)

```cpp
// C++ program to check if a number is Palindrome
#include <iostream>
using namespace std;

// Function to check Palindrome
bool checkPalindrome(int n)
{
    int reverse = 0;
    int temp = n;
    while (temp != 0) {
        reverse = (reverse * 10) + (temp % 10);
        temp = temp / 10;
    }
    return (reverse == n); // returns true if palindrome
}

int main()
{
    int n = 7007;
    if (checkPalindrome(n)) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    return 0;
}
```

---

## 📤 Output

```
Yes
```

---

## ⏱️ Time & Space Complexity

* **Time Complexity**: `O(log₁₀(n))` or `O(Number of digits)`
* **Auxiliary Space**: `O(1)` (constant space)

---
