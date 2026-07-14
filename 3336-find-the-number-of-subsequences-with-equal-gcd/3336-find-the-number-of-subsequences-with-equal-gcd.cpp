class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int n;
    vector<int> nums;
    vector<vector<vector<int>>> memo;

    int dfs(int i, int g1, int g2) {
        if (i == n)
            return (g1 == g2 && g1 != 0);

        int &res = memo[i][g1][g2];
        if (res != -1) return res;

        long long ans = 0;

        // Skip
        ans += dfs(i + 1, g1, g2);

        // Put in first subsequence
        ans += dfs(i + 1, std::gcd(g1, nums[i]), g2);

        // Put in second subsequence
        ans += dfs(i + 1, g1, std::gcd(g2, nums[i]));

        return res = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());
        memo.assign(n,
                    vector<vector<int>>(mx + 1,
                    vector<int>(mx + 1, -1)));

        return dfs(0, 0, 0);
    }
};