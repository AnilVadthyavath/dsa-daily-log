# Naive Divisor Function 
class Solution {
public:
    vector<int> printDivisors(int n) {
        vector<int> result;
        
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};

#Efficient Divisor Function
class Solution {
public:
    vector<int> printDivisors(int n) {
        vector<int> result;
        
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                result.push_back(i);
                
                if (i != n / i) {
                    result.push_back(n / i);
                }
            }
        }
        
        return result;
    }
};


# Optimized & Sorted Divisors
class Solution {
public:
    vector<int> printDivisors(int n) {
        vector<int> smallDivisors;
        vector<int> largeDivisors;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                smallDivisors.push_back(i);

                if (i != n / i) {
                    largeDivisors.push_back(n / i);
                }
            }
        }

        // Append large divisors in reverse to get sorted order
        reverse(largeDivisors.begin(), largeDivisors.end());
        smallDivisors.insert(smallDivisors.end(), largeDivisors.begin(), largeDivisors.end());

        return smallDivisors;
    }
};

