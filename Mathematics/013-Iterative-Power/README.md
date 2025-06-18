# ⚡ Iterative Power Function (O(log y) Time)

## 🧠 Problem

Given integers `x` and `y`, compute **xⁿ**:

* Time Complexity: **O(log y)**
* Space Complexity: **O(1)** (no recursion stack)

This is done using the **Exponentiation by Squaring** method, implemented iteratively.

---

## 🛠️ Key Idea

At each step:

* If `y` is odd → `res *= x`
* Then halve `y` → `y = y / 2`
* Square `x` → `x = x * x`

This way, we **reduce y logarithmically**.

---

## ✅ C++ Implementation

```cpp
#include <iostream>
using namespace std;

/* Function to calculate (x^y) in O(log y) time and O(1) space */
int power(int x, unsigned int y) {
    int res = 1; // Initialize result

    while (y > 0) {
        // If y is odd, multiply result with current x
        if (y & 1)
            res = res * x;

        // y must be even now
        y = y >> 1;     // Divide y by 2
        x = x * x;      // Square the base
    }

    return res;
}

// Driver code
int main() {
    int x = 3;
    unsigned int y = 5;

    cout << "Power is " << power(x, y);  // Output: Power is 243
    return 0;
}
```

---

## 📈 Output

```
Power is 243
```

---

## ⏱ Time & Space Complexity

| Metric          | Value    |
| --------------- | -------- |
| Time Complexity | O(log y) |
| Auxiliary Space | O(1)     |

This is **much more efficient** than the naive `O(y)` solution, and more space-friendly than recursive `O(log y)` solutions.

---

## 🔁 Example Trace: x = 3, y = 5

Steps:

* `y = 5 (odd)` → res = 1 \* 3 = 3, y = 2, x = 9
* `y = 2 (even)` → y = 1, x = 81
* `y = 1 (odd)` → res = 3 \* 81 = 243, y = 0

✅ Final result: 243

