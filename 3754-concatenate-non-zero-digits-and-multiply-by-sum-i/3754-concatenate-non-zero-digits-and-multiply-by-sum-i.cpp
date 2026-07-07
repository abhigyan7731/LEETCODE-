class Solution {
public:
    long long sumAndMultiply(int n) {
        // First pass: extract non-zero digits and build reversed x
        long long revX = 0;
        long long sum = 0;
        
        if (n == 0) {
            // No non-zero digits, x = 0 → answer = 0 * 0 = 0
            return 0;
        }
        
        while (n > 0) {
            int d = n % 10;
            if (d != 0) {
                revX = revX * 10 + d; // build reversed x
                sum += d;
            }
            n /= 10;
        }
        
        // Second pass: reverse revX to get x in original order
        long long x = 0;
        while (revX > 0) {
            int d = revX % 10;
            x = x * 10 + d;
            revX /= 10;
        }
        
        return x * sum;
    }
};