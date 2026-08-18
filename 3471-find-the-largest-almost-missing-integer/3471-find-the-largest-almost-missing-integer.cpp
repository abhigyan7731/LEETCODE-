class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(51, 0);

        for (int x : nums) {
            freq[x]++;
        }

        // Only one subarray: nums itself.
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Each element is its own subarray.
        if (k == 1) {
            int ans = -1;
            for (int x : nums) {
                if (freq[x] == 1) {
                    ans = max(ans, x);
                }
            }
            return ans;
        }

        // For 1 < k < n, only first and last elements
        // can occur in exactly one size-k subarray.
        int ans = -1;

        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};