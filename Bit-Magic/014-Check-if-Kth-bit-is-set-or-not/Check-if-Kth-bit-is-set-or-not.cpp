//naive solution
class Solution {
public:
    string isKthBitSet(int n, int k) {
        int x = 1;
        for (int i = 0; i < (k - 1); i++) {
            x = x * 2;
        }

        if ((n & x) != 0)
            return "Yes";
        else
            return "No";
    }
};

//efficient solution (Method I) 
class Solution {
public:
    string isKthBitSet(int n, int k) {
        int x = (1 << (k - 1)); // equivalent to 2^(k-1)
        if ((n & x) != 0)
            return "Yes";
        else
            return "No";
    }
};


//Efficient Method II (using the right shift operator)
class Solution {
public:
    string isKthBitSet(int n, int k) {
        int x = (n >> (k - 1)); // Right shift to bring k-th bit to LSB
        if ((x & 1) != 0)
            return "Yes";
        else
            return "No";
    }
};

