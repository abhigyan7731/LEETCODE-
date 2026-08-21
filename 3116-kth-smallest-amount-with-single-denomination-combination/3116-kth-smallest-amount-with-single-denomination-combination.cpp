class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        // Count how many valid amounts <= x
        auto count = [&](long long x) {
            long long ans = 0;

            // Iterate over all non-empty subsets
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                int bits = 0;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        l = lcm(l, (long long)coins[i]);

                        // No multiple of this LCM can be <= x
                        if (l > x) break;
                    }
                }

                if (l > x) continue;

                // Inclusion-Exclusion
                if (bits % 2 == 1)
                    ans += x / l;
                else
                    ans -= x / l;
            }

            return ans;
        };

        // Maximum answer is k * smallest coin
        long long low = 1;
        long long high = 1LL * k * (*min_element(coins.begin(),
                                                  coins.end()));

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};