class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);

        for (int i = 0; i < n; i++)
            diff[i] = abs((long long)nums1[i] - nums2[i]);

        long long k = (long long)k1 + k2;
        long long lo = 0, hi = *max_element(diff.begin(), diff.end());

        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            long long need = 0;

            for (long long d : diff)
                if (d > mid) need += d - mid;

            if (need <= k) hi = mid;
            else lo = mid + 1;
        }

        long long limit = lo;
        long long ans = 0, cnt = 0;

        for (long long &d : diff) {
            if (d > limit) {
                k -= d - limit;
                d = limit;
            }
            if (d == limit) cnt++;
            ans += d * d;
        }

        if (k > 0 && limit > 0) {
            long long full = k / cnt;
            long long rem = k % cnt;

            long long high = max(0LL, limit - full);
            long long low = max(0LL, high - 1);

            ans -= cnt * limit * limit;
            ans += (cnt - rem) * high * high;
            ans += rem * low * low;
        }

        return ans;
    }
};