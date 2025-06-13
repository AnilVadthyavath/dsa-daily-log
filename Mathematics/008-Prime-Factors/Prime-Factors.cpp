# Naive Prime Factorization Code:
void primeFactors(int n) {
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            int x = i;
            while (n % x == 0) {
                print(i);
                x = x * i;
            }
        }
    }
}

#Efficient Prime Factorization (C++):
class Solution {
public:
    vector<int> primeFactors(int n) {
        vector<int> result;
        if (n <= 1) return result;

        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                result.push_back(i);
                n /= i;
            }
        }

        // If n is a prime number > sqrt(original n)
        if (n > 1) {
            result.push_back(n);
        }

        return result;
    }
};


# More Efficient Code
class Solution {
public:
    vector<int> primeFactors(int n) {
        vector<int> result;

        if (n <= 1) return result;

        // Handle 2 separately
        while (n % 2 == 0) {
            result.push_back(2);
            n /= 2;
        }

        // Handle 3 separately
        while (n % 3 == 0) {
            result.push_back(3);
            n /= 3;
        }

        // Use 6k ± 1 optimization
        for (int i = 5; i * i <= n; i += 6) {
            while (n % i == 0) {
                result.push_back(i);
                n /= i;
            }
            while (n % (i + 2) == 0) {
                result.push_back(i + 2);
                n /= (i + 2);
            }
        }

        // If n is a prime number greater than 3
        if (n > 3) {
            result.push_back(n);
        }

        return result;
    }
};

