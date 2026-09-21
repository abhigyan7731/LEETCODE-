class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> next(k, 0);
            int value = num % k;

            // Start a new subarray containing only num.
            next[value]++;

            // Extend every subarray that ended at the previous index.
            for (int rem = 0; rem < k; rem++) {
                int newRem = (rem * value) % k;
                next[newRem] += dp[rem];
            }

            // All subarrays ending here contribute to the answer.
            for (int rem = 0; rem < k; rem++) {
                ans[rem] += next[rem];
            }

            dp = next;
        }

        return ans;
    }
};