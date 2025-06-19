# Bitwise Algorithms Basics

Bitwise algorithms perform operations at the **bit-level**, allowing manipulation of individual bits of data. These operations are extremely **fast** and are often used to optimize the performance of a program.

---

## 📌 Why Use Bitwise Operations?

Bitwise operations are low-level and efficient. For example, checking whether a number is **even or odd** can be done using the bitwise AND (`&`) operator:

```cpp
if (num & 1)
    // num is odd
else
    // num is even
```

The logic here is that **if the least significant bit (LSB) is set**, the number is odd. Otherwise, it's even.

---

## 🔧 Bitwise Operators

| Operator | Name        | Description                                                                                                   | Example                                                                          |     |         |
| -------- | ----------- | ------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------- | --- | ------- |
| `&`      | Bitwise AND | Performs AND operation on each bit. Result is `1` if **both** bits are `1`.                                   | `5 & 3 = 1`                                                                      |     |         |
| \`       | \`          | Bitwise OR                                                                                                    | Performs OR operation on each bit. Result is `1` if **at least one** bit is `1`. | \`5 | 3 = 7\` |
| `^`      | Bitwise XOR | Performs XOR operation on each bit. Result is `1` if bits are **different**.                                  | `5 ^ 3 = 6`                                                                      |     |         |
| `<<`     | Left Shift  | Shifts bits to the **left** by the number of positions specified. Equivalent to multiplying by 2<sup>n</sup>. | `5 << 1 = 10`                                                                    |     |         |
| `>>`     | Right Shift | Shifts bits to the **right** by the number of positions specified. Equivalent to dividing by 2<sup>n</sup>.   | `5 >> 1 = 2`                                                                     |     |         |
| `~`      | Bitwise NOT | Inverts all the bits of the number (1’s complement).                                                          | `~5 = -6`                                                                        |     |         |

---

## 💡 Key Points

* **Shifting:**

  * `x << n` is equivalent to `x * 2^n`
  * `x >> n` is equivalent to `x / 2^n`

* **XOR Operator (`^`)** is widely used in technical interviews and has many unique properties, such as:

  * `a ^ a = 0`
  * `a ^ 0 = a`
  * Used in problems like finding the non-repeating element in an array.

* Bitwise operations **should not** be used as a substitute for logical operators (`&&`, `||`).

* `x & 1` is a quick way to check if `x` is **odd**.

---

## ⏱️ Time and Space Complexity

* **Time Complexity:** `O(1)`
* **Auxiliary Space:** `O(1)`

Bitwise operations are constant-time and do not require additional space, making them excellent tools for low-level optimizations.

---

Feel free to expand this document as you explore more advanced bitwise techniques like:

* Counting set bits
* Swapping numbers without a temporary variable
* Bitmasking for subsets and permissions
* Bit tricks in competitive programming

---

## ⚙️ Bit Algorithms | Important Tactics

Below are some powerful and commonly used **bit manipulation tactics** that make solving certain problems faster and more elegant.

---

### 1. ✅ Setting a Bit at the `n`-th Position

To **set a bit** at the `n`-th position in a number `num`:

```cpp
num = num | (1 << (n - 1));
```

* `1 << (n - 1)` shifts `1` to the left `n-1` times, placing a `1` at the desired bit.
* Using bitwise OR (`|`) ensures the bit is set, regardless of its original state.

---

### 2. ❌ Unsetting (Clearing) a Bit at the `n`-th Position

To **clear** (unset) a bit at the `n`-th position:

```cpp
num = num & ~(1 << (n - 1));
```

* `(1 << (n - 1))` creates a bitmask with `1` at position `n`.
* `~` inverts the bitmask, turning the `1` to `0`.
* Bitwise AND (`&`) clears the bit at the desired position.

---

### 3. 🔁 Toggling a Bit at the `n`-th Position

To **toggle** a bit (flip `1` to `0` or `0` to `1`) at position `n`:

```cpp
num = num ^ (1 << (n - 1));
```

* XOR (`^`) flips bits based on the rule:

  * `1 ^ 1 = 0`, `0 ^ 0 = 0`, `1 ^ 0 = 1`, `0 ^ 1 = 1`

---

### 4. 🔍 Checking if Bit at `n`-th Position is Set

To **check if a bit is set** at the `n`-th position:

```cpp
if (num & (1 << (n - 1))) {
    // Bit is set
} else {
    // Bit is not set
}
```

* The expression yields non-zero if the bit is **set**, zero otherwise.

---

### 5. ➗ Dividing a Number by 2

```cpp
x = x >> 1;
```

* Right shifting (`>>`) by 1 is equivalent to dividing by 2.
* Each bit is halved, moving one position to the right.

**Example:**

```
x = 18 (00010010)
x >> 1 = 9 (00001001)
```

---

### 6. ✖️ Multiplying a Number by 2

```cpp
x = x << 1;
```

* Left shifting (`<<`) by 1 is equivalent to multiplying by 2.
* Each bit moves one place left.

**Example:**

```
x = 18 (00010010)
x << 1 = 36 (00100100)
```

---

### 7. 📊 Log Base 2 of a 32-bit Integer

```cpp
int log2(int x) {
    int res = 0;
    while (x >>= 1) {
        res++;
    }
    return res;
}
```

* This returns the **floor of log base 2** of `x`.
* It repeatedly right shifts `x` until it becomes `0`.

---

### 8. 🔄 Flipping All Bits of a Number

To **flip all bits** of a number `num`:

```cpp
flipped = value - num;
```

* `value` is a number with all bits set (e.g. `2^n - 1`)
* This flips all the bits in `num`.

**Example:**

```
num = 23 (10111)
value = 31 (11111)
flipped = 31 - 23 = 8 (01000)
```

---

### 9. 🔁 Swapping Two Numbers Using XOR

To swap two numbers `a` and `b` without a temporary variable:

```cpp
a = a ^ b;
b = b ^ a;
a = a ^ b;
```

* A clever use of XOR to exchange values.

---

These tactics form the **foundation of many bit manipulation problems** frequently asked in technical interviews and competitive programming.

---
