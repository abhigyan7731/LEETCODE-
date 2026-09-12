class Solution {
public:
    using ll = long long;

    struct State {
        ll score = 0;
        vector<int> picks;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score) return a.score > b.score;
        return a.picks < b.picks; // lexicographically smaller
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {right, left, weight, originalIndex}
        vector<array<ll, 4>> a;
        a.reserve(n);

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][1],
                intervals[i][0],
                intervals[i][2],
                i
            });
        }

        sort(a.begin(), a.end());

        // ends[i] = ending point of interval i after sorting by right endpoint
        vector<ll> ends(n);
        for (int i = 0; i < n; i++) {
            ends[i] = a[i][0];
        }

        // prev[i] = last interval whose right endpoint < a[i]'s left endpoint
        vector<int> prev(n);
        for (int i = 0; i < n; i++) {
            prev[i] = lower_bound(ends.begin(), ends.begin() + i, a[i][1]) 
                      - ends.begin() - 1;
        }

        // dp[k][i]: best state using at most k intervals among first i intervals.
        vector<vector<State>> dp(5, vector<State>(n + 1));

        for (int k = 1; k <= 4; k++) {
            for (int i = 1; i <= n; i++) {
                // Option 1: skip current interval
                dp[k][i] = dp[k][i - 1];

                // Option 2: take current interval
                int cur = i - 1;
                State take = dp[k - 1][prev[cur] + 1];
                take.score += a[cur][2];
                take.picks.push_back((int)a[cur][3]);

                // Returned indices must themselves be lexicographically smallest,
                // so keep every picked-index vector sorted.
                sort(take.picks.begin(), take.picks.end());

                if (better(take, dp[k][i])) {
                    dp[k][i] = take;
                }
            }
        }

        return dp[4][n].picks;
    }
};