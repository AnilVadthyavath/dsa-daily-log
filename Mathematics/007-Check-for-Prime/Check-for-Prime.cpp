// naive

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;

        for (int i = 2; i < n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};

//Efficient Prime Check Code:

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
};

// Highly Efficient Prime Check Code:

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
};


