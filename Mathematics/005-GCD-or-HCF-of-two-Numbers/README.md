# 🤝 GCD or HCF of Two Numbers

## 🧩 Problem Statement

**GCD (Greatest Common Divisor)** or **HCF (Highest Common Factor)** of two numbers is the **largest number** that divides both of them without leaving a remainder.

> **Examples:**

* GCD of 20 and 28 → `4`
* GCD of 98 and 56 → `14`

---

## ⚙️ Approach 1: Euclidean Algorithm (By Subtraction)

This is one of the oldest methods to compute GCD using **repeated subtraction**.

### 🔁 Concept:

* Keep subtracting the smaller number from the larger one.
* Continue until both numbers become equal.
* That value is the **GCD**.

### 🧾 Pseudocode:

```python
def gcd(a, b):
    if a == b:
        return a
    if a > b:
        return gcd(a - b, b)
    else:
        return gcd(a, b - a)
```

### 💡 Example:

```
a = 98, b = 56
→ a = 98 - 56 = 42
→ b = 56
→ b = 56 - 42 = 14
→ a = 42
→ a = 42 - 14 = 28
→ a = 28 - 14 = 14
Now a == b → GCD = 14
```

---

### 🧾 Code (C++: Subtraction Method)

```cpp
#include <iostream>
using namespace std;

// Recursive function to return gcd using subtraction
int gcd(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}

int main()
{
    int a = 98, b = 56;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b);
    return 0;
}
```

### 📤 Output

```
GCD of 98 and 56 is 14
```

### ⏱️ Complexity

* **Time Complexity:** `O(max(a, b))`
* **Auxiliary Space:** `O(max(a, b))` (recursive stack)

---

## ⚙️ Approach 2: Efficient Euclidean Algorithm (Modulo Method)

This approach avoids subtraction and uses the **modulo (`%`) operator**.

### 🔁 Concept:

* `gcd(a, b) = gcd(b, a % b)`
* Repeat until `b == 0`, then `a` is the GCD.

---

### 🧾 Code (C++: Modulo Method)

```cpp
#include <iostream>
using namespace std;

// Recursive function to return gcd using modulo
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int a = 98, b = 56;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b);
    return 0;
}
```

### 📤 Output

```
GCD of 98 and 56 is 14
```

---

## ⏱️ Time & Space Complexity

* **Time Complexity:** `O(log(min(a, b)))`
* **Auxiliary Space:** `O(log(min(a, b)))`

### 📈 Why `O(log(min(a, b)))`?

Worst case occurs with consecutive Fibonacci numbers like `(21, 13), (13, 8), (8, 5)...`, since:

* `gcd(fib(n), fib(n+1))` → takes `n` steps
* Fibonacci grows exponentially, so GCD steps grow **logarithmically**
* Related to the **Golden Ratio (ϕ ≈ 1.618...)**

---

✅ Use the **modulo method** in practice — it's concise, efficient, and handles large inputs gracefully.

---
