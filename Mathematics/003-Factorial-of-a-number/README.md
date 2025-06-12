# ✖️ Factorial of a Number

## ❓ What is a Factorial?

The **factorial** of a non-negative integer `n` is the product of all positive integers less than or equal to `n`.

> Mathematically,
> `n! = n × (n-1) × (n-2) × ... × 2 × 1`
>
> Example:
> `6! = 6 × 5 × 4 × 3 × 2 × 1 = 720`

The factorial symbol `!` is used widely in **permutations**, **combinations**, and **mathematics**. It was first introduced by French mathematician **Christian Kramp**.

---

## 🧠 Recursive Approach

The factorial can be calculated recursively using:

```
n! = n × (n - 1)!
n! = 1 if n == 0 or n == 1
```

### 🧾 Code (Recursive – C++)

```cpp
// C++ program to find factorial of given number (Recursive)
#include <iostream>
using namespace std;

// Function to find factorial
unsigned int factorial(unsigned int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

// Driver code
int main()
{
    int num = 5;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}
```

### 📤 Output

```
Factorial of 5 is 120
```

### ⏱️ Time & Space Complexity

* **Time Complexity**: `O(n)`
* **Auxiliary Space**: `O(n)` (due to recursion stack)

---

## 🔁 Iterative Approach (Using For Loop)

Recursion can be costly in terms of stack space, so we can use iteration to compute factorial efficiently.

### 🧾 Code (Iterative – C++)

```cpp
// C++ program to find factorial of given number (Iterative)
#include <iostream>
using namespace std;

// Function to find factorial
unsigned int factorial(unsigned int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

// Driver code
int main()
{
    int num = 5;
    cout << "Factorial of " << num << " is " << factorial(num) << endl;
    return 0;
}
```

### 📤 Output

```
Factorial of 5 is 120
```

### ⏱️ Time & Space Complexity

* **Time Complexity**: `O(n)`
* **Auxiliary Space**: `O(1)` (constant)

---
