class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefCnt(n + 1, 0);
        vector<int> prefSum(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefCnt[i + 1] = prefCnt[i] + (s[i] != '0');
            prefSum[i + 1] = prefSum[i] + (s[i] - '0');
        }

        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            if (d == 0) pre[i + 1] = pre[i];
            else pre[i + 1] = (pre[i] * 10 + d) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int cntR = prefCnt[r + 1];
            int cntL = prefCnt[l];
            int len = cntR - cntL;

            if (len == 0) {
                ans.push_back(0);
                continue;
            }

            long long x = (pre[r + 1] - pre[l] * pow10[len]) % MOD;
            if (x < 0) x += MOD;

            int sum = prefSum[r + 1] - prefSum[l];
            long long res = (x * sum) % MOD;
            ans.push_back((int)res);
        }

        return ans;
    }
};