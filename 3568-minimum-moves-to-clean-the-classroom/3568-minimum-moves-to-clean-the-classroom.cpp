class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx, sy;
        vector<pair<int, int>> litter;

        // Find starting position and all litter positions
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        if (k == 0)
            return 0;

        // Give every litter cell a bit
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }

        int fullMask = (1 << k) - 1;

        // best[x][y][mask] = maximum energy we've had
        // at (x,y) after collecting mask
        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(
                   n, vector<int>(1 << k, -1)
               )
        );

        struct State {
            int x, y;
            int mask;
            int energy;
            int dist;
        };

        queue<State> q;

        best[sx][sy][0] = energy;
        q.push({sx, sy, 0, energy, 0});

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int x = cur.x;
            int y = cur.y;
            int mask = cur.mask;
            int e = cur.energy;
            int dist = cur.dist;

            if (mask == fullMask)
                return dist;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                // Outside grid
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                // Wall
                if (classroom[nx][ny] == 'X')
                    continue;

                // Moving costs 1 energy
                int ne = e - 1;

                if (ne < 0)
                    continue;

                // Recharge at R
                if (classroom[nx][ny] == 'R') {
                    ne = energy;
                }

                int nmask = mask;

                // Collect litter
                if (classroom[nx][ny] == 'L') {
                    int bit = id[nx][ny];
                    nmask |= (1 << bit);
                }

                // If we've already reached this state with
                // equal or more energy, this state is useless.
                if (best[nx][ny][nmask] >= ne)
                    continue;

                best[nx][ny][nmask] = ne;

                q.push({
                    nx, ny, nmask, ne, dist + 1
                });
            }
        }

        return -1;
    }
};