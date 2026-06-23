class Solution {
public:
    static const int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> up(m + 1), down(m + 1);

        for (int x = 1; x <= m; x++) {
            up[x] = x - 1;
            down[x] = m - x;
        }

        for (int len = 3; len <= n; len++) {
            vector<int> prefUp(m + 1, 0);
            vector<int> prefDown(m + 1, 0);

            for (int i = 1; i <= m; i++) {
                prefUp[i] = (prefUp[i - 1] + up[i]) % MOD;
                prefDown[i] = (prefDown[i - 1] + down[i]) % MOD;
            }

            vector<int> nextUp(m + 1);
            vector<int> nextDown(m + 1);

            for (int x = 1; x <= m; x++) {
                nextUp[x] = prefDown[x - 1];
                nextDown[x] = (prefUp[m] - prefUp[x] + MOD) % MOD;
            }

            up.swap(nextUp);
            down.swap(nextDown);
        }

        if (n == 1) return m;

        if (n == 2)
            return (long long)m * (m - 1) % MOD;

        long long ans = 0;

        for (int x = 1; x <= m; x++) {
            ans += up[x];
            ans += down[x];
            ans %= MOD;
        }

        return (int)ans;
    }
};