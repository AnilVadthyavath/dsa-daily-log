//Naive Power Function 
class Solution {
public:
    int power(int x, int n) {
        int res = 1;
        for (int i = 0; i < n; i++) {
            res = res * x;
        }
        return res;
    }
};


//Efficient Solution
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

