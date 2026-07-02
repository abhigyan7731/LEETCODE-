class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        const int INF = 1e9;
        vector<vector<int>> dist(m, vector<int>(n, INF));

        // Min-heap: (cost_so_far, x, y)
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][0] = grid[0][0];
        pq.emplace(dist[0][0], 0, 0);

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();
            if (cost > dist[x][y]) continue;
            if (x == m - 1 && y == n - 1) break; // already best for end

            for (auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                int nc = cost + grid[nx][ny];
                if (nc < dist[nx][ny]) {
                    dist[nx][ny] = nc;
                    pq.emplace(nc, nx, ny);
                }
            }
        }

        return dist[m - 1][n - 1] < health;
    }
};