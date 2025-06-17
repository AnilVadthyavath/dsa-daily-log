//  Naive Implementation (Limited by int overflow):

class Solution {
public:
    int countTrailingZeros(int n) {
        int fact = 1;
        for (int i = 2; i <= n; i++)
            fact = fact * i;

        int count = 0;
        while (fact % 10 == 0) {
            fact = fact / 10;
            count++;
        }

        return count;
    }
};

// optimized solution:

class Solution {
public:
    int countTrailingZeros(int n) {
        int count = 0;
        for (int i = 5; i <= n; i *= 5)
            count += n / i;
        return count;
    }
};

# example = 100
#count = 100/5 + 100/25 + 100/125
#     = 20 + 4 + 0
#     = 24

