class Solution {
public:
    bool isPalindrome(int n) {
        int rev = 0;
        int temp = n;

        while (temp != 0) {
            int last_digit = temp % 10;
            rev = rev * 10 + last_digit;
            temp = temp / 10;
        }

        return (rev == n);
    }
};
