class Solution {
public:
    static constexpr long long MOD = 1000000007LL;
    int n;
    vector<long long> sum, sq, lazy;

    void build(int node, int l, int r) {
        sum[node] = sq[node] = lazy[node] = 0;
        if (l == r) return;

        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
    }

    void apply(int node, int l, int r, long long c) {
        long long len = r - l + 1;

        sq[node] = (sq[node] + 2 * c % MOD * sum[node] + c * c % MOD * len) % MOD;
        sum[node] = (sum[node] + c * len) % MOD;
        lazy[node] = (lazy[node] + c) % MOD;
    }

    void push(int node, int l, int r) {
        if (lazy[node] == 0) return;

        int mid = (l + r) / 2;
        apply(2 * node, l, mid, lazy[node]);
        apply(2 * node + 1, mid + 1, r, lazy[node]);

        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr);
        update(2 * node + 1, mid + 1, r, ql, qr);

        sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;
        sq[node] = (sq[2 * node] + sq[2 * node + 1]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        build(1, 0, n - 1);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int x = nums[r];
            int start = last[x] + 1;

            update(1, 0, n - 1, start, r);
            last[x] = r;

            ans = (ans + sq[1]) % MOD;
        }

        return (int)ans;
    }
};