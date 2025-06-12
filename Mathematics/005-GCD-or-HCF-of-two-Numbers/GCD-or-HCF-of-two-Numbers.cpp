# Brute force:

class Solution {
public:
    int gcd(int a, int b) {
        int res = std::min(a, b);
        while (res > 0) {
            if (a % res == 0 && b % res == 0) {
                break;
            }
            res--;
        }
        return res;
    }
};

# Euclidean Algorithm (More Efficient):

class Solution {
public:
    int gcd(int a, int b) {
        while (a != b) {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        }
        return a;
    }
};

# optimized
class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }
};
