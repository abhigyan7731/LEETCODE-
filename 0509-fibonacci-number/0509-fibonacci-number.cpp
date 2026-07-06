class Solution {
public:
    int fib(int n) {
        // base cases
        if (n == 0 || n == 1) {
            return n;
        }

        // recursive step: F(n) = F(n-1) + F(n-2)
        return fib(n - 1) + fib(n - 2);
    }
};