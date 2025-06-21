//1. Basic Division Method

class Solution {
public:
    int countSetBits(int n) {
        int res = 0;
        while (n > 0) {
            if (n % 2 == 1)
                res++;
            n = n / 2;
        }
        return res;
    }
};



//2. Brian Kernighan's Algorithm
  
class Solution {
public:
    int countSetBits(int n) {
        int res = 0;
        while (n > 0) {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};



//3. Lookup Table Method


class Solution {
    int tbl[256];
    
    void initialize() {
        tbl[0] = 0;
        for (int i = 1; i < 256; i++) {
            tbl[i] = tbl[i & (i - 1)] + 1;
        }
    }

public:
    Solution() {
        initialize();
    }

    int countSetBits(int n) {
        return tbl[n & 255] + 
               tbl[(n >> 8) & 255] + 
               tbl[(n >> 16) & 255] + 
               tbl[(n >> 24)];
    }
};
