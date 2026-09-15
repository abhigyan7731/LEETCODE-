class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        // dp[i] = maximum palindromes using first i characters
        for (int i = 0; i < n; i++) {
            dp[i + 1] = max(dp[i + 1], dp[i]);

            // Only lengths k and k+1 need checking.
            // Any longer palindrome contains a palindrome of one of these lengths.
            for (int len : {k, k + 1}) {
                int l = i - len + 1;
                if (l < 0) continue;

                int left = l, right = i;
                bool isPal = true;

                while (left < right) {
                    if (s[left] != s[right]) {
                        isPal = false;
                        break;
                    }
                    left++;
                    right--;
                }

                if (isPal) {
                    dp[i + 1] = max(dp[i + 1], dp[l] + 1);
                }
            }
        }

        return dp[n];
    }
};