class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = (int)online.size();
        int m = (int)edges.size();
        if (m == 0) return -1;  // no edges → no path

        // Build adjacency list with all edges (we will filter by threshold later)
        struct Edge {
            int to;
            int cost;
        };
        vector<vector<Edge>> adj(n);
        int maxCost = 0;
        for (auto &e : edges) {
            int u = e[0], v = e[1], c = e[2];
            adj[u].push_back({v, c});
            maxCost = max(maxCost, c);
        }

        // Check if there exists a valid path with min-edge >= thresh and total cost <= k
        auto can = [&](int thresh) -> bool {
            const long long INF = (long long)4e18;
            vector<long long> dist(n, INF);
            dist[0] = 0;

            using P = pair<long long,int>;
            priority_queue<P, vector<P>, greater<P>> pq;
            pq.push({0, 0});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (d != dist[u]) continue;
                if (d > k) continue;  // no need to expand paths already above k

                // can't go through offline intermediate nodes
                if (u != 0 && u != n-1 && !online[u]) continue;

                for (auto &ed : adj[u]) {
                    int v = ed.to;
                    int c = ed.cost;

                    // edge must satisfy threshold and target node must be online if intermediate
                    if (c < thresh) continue;
                    if (v != 0 && v != n-1 && !online[v]) continue;

                    long long nd = d + c;
                    if (nd < dist[v] && nd <= k) {
                        dist[v] = nd;
                        pq.push({nd, v});
                    }
                }
            }

            return dist[n-1] <= k;
        };

        int lo = 0, hi = maxCost, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (can(mid)) {
                ans = mid;
                lo = mid + 1;  // try bigger minimum edge cost
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};