class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k %= total;                          // effective shifts

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int oldIndex = i * n + j;    // flatten index
                int newIndex = (oldIndex + k) % total;
                int ni = newIndex / n;       // new row
                int nj = newIndex % n;       // new col
                ans[ni][nj] = grid[i][j];
            }
        }
        return ans;
    }
};