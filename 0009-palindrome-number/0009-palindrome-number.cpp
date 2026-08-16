class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int orignal = x;
        long long reversed = 0;

        while (x > 0){
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return orignal == reversed;

        
    }
};