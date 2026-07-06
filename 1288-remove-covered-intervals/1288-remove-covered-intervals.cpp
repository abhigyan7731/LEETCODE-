class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Sort by start asc, and if tie, by end desc
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) return a[1] > b[1];
                 return a[0] < b[0];
             });

        int count = 0;
        int prevEnd = -1;  // smallest possible value based on constraints

        for (const auto& iv : intervals) {
            int l = iv[0];
            int r = iv[1];

            // If current end is greater than any previous end, it's not covered
            if (r > prevEnd) {
                ++count;
                prevEnd = r;
            }
            // else r <= prevEnd: current interval [l, r] is covered and skipped
        }

        return count;
    }
};