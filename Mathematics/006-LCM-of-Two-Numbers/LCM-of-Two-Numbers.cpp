#Brute-Force 

class Solution {
public:
    int lcm(int a, int b) {
        int res = std::max(a, b);
        while (true) {
            if (res % a == 0 && res % b == 0)
                return res;
            res++;
        }
    }
};


# optimzed

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
};

