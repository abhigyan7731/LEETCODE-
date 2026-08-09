class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int m) {
        if (i >= n) return 0;

        // Current player can take every remaining pile.
        if (i + 2 * m >= n) return suffix[i];

        int &ans = dp[i][m];
        if (ans != -1) return ans;

        ans = 0;

        // Opponent gets solve(i + x, max(m, x)).
        // So current player gets remaining sum minus opponent's best score.
        for (int x = 1; x <= 2 * m; x++) {
            ans = max(ans, suffix[i] - solve(i + x, max(m, x)));
        }

        return ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffix.assign(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        dp.assign(n, vector<int>(n + 1, -1));
        return solve(0, 1);
    }
};