class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        // dp[0] = false: player with no stones loses

        for (int stones = 1; stones <= n; ++stones) {
            for (int x = 1; x * x <= stones; ++x) {
                if (!dp[stones - x * x]) {
                    dp[stones] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};