class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        const long long LIMIT = INT_MAX;

        vector<long long> dp(m + 1, 0);

        dp[0] = 1;

        for (int i=0; i < n; i++){
            for(int j = min(i, m-1); j >=0; j--){
                if (s[i] == t[j])  {
                    dp[j + 1] = min(LIMIT, dp[j + 1] + dp[j]);
                }
            }
        }
        return dp[m];
        

    }
};