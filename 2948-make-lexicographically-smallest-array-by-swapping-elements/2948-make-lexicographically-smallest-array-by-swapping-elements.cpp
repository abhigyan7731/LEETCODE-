class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> a; // {value, originalIndex}

        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        sort(a.begin(), a.end());

        vector<int> ans(n);

        for (int l = 0; l < n; ) {
            int r = l;

            // A new component starts when the consecutive sorted gap is too large.
            while (r + 1 < n && a[r + 1].first - a[r].first <= limit) {
                r++;
            }

            vector<int> indices;
            vector<int> values;

            for (int i = l; i <= r; i++) {
                indices.push_back(a[i].second);
                values.push_back(a[i].first);
            }

            sort(indices.begin(), indices.end());

            // Put smallest values at smallest original indices.
            for (int i = 0; i < indices.size(); i++) {
                ans[indices[i]] = values[i];
            }

            l = r + 1;
        }

        return ans;
    }
};