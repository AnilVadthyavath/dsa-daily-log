class Solution {
public:
    int power(int x, int n) {
        int result = 1;
        while (n > 0) {
            if (n % 2 != 0)
                result *= x;
            x *= x;
            n /= 2;
        }
        return result;
    }
};


