class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = n * n;

        vector<int> freq(m + 1, 0);

        for (auto &row : grid) {
            for (int num : row) {
                freq[num]++;
            }
        }

        int repeated = -1, missing = -1;

        for (int i = 1; i <= m; i++) {
            if (freq[i] == 2) repeated = i;
            else if (freq[i] == 0) missing = i;
        }

        return {repeated, missing};
    }
};