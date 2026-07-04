class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Build adjacency list: city -> list of (neighbor, distance)
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto &r : roads) {
            int a = r[0], b = r[1], d = r[2];
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }

        // BFS from city 1 to find its whole connected component
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (auto &[v, w] : adj[u]) {
                // Every edge reachable from 1 can appear in some path 1..n
                ans = min(ans, w);
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};