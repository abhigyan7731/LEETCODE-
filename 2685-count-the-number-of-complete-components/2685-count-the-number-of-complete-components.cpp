class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> vis;

    void dfs(int node, int &nodes, int &degreeSum) {
        vis[node] = true;
        nodes++;
        degreeSum += graph[node].size();

        for (int nei : graph[node]) {
            if (!vis[nei])
                dfs(nei, nodes, degreeSum);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        graph.assign(n, {});
        vis.assign(n, false);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0;
                int degreeSum = 0;

                dfs(i, nodes, degreeSum);

                if (degreeSum == nodes * (nodes - 1))
                    ans++;
            }
        }

        return ans;
    }
};