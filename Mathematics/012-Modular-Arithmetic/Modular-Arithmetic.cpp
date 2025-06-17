// 1. Naive Solution
class Solution {
public:
    int power(int x, int n) {
        int res = 1;
        for (int i = 0; i < n; i++) {
            res *= x;
        }
        return res;
    }
};

// 2. Efficient Solution (Binary Exponentiation)
class Solution {
public:
    int power(int x, int n) {
        if (n == 0)
            return 1;

        int tmp = power(x, n / 2);
        tmp = tmp * tmp;

        if (n % 2 == 0)
            return tmp;
        else
            return tmp * x;
    }
};

