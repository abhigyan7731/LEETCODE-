class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long topSum = 0;
        for (int i=0; i<n; i++){
            topSum += grid[0][i];
        }

            long long bottomSum = 0;
            long long ans = LLONG_MAX;

            for (int i=0; i <n; i++){
                topSum -= grid[0][i];

                long long bestRobot2 = max(topSum, bottomSum);
                ans = min(ans, bestRobot2);
                bottomSum += grid[1][i];
            }
            return ans;
        

        
    }
};