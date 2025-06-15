#naive solution
class Solution {
public:
    vector<int> printPrimes(int n) {
        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }
        return primes;
    }

private:
    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
};

#Sieve of Eratosthenes code
class Solution {
public:
    vector<int> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = 2 * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }
};

#optimized Sieve of Eratosthenes
class Solution {
public:
    vector<int> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }
};

