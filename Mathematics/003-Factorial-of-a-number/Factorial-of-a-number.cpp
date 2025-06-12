# native solution

class Solution {
public:
    int factorial(int n) {
        int res = 1;
        for (int i = 2; i <= n; i++)
            res = res * i;
        return res;
    }
};

# optimized solution

class Solution {
public:
    int factorial(int n) {
        if (n == 0)
            return 1;
        return n * factorial(n - 1);
    }
};
