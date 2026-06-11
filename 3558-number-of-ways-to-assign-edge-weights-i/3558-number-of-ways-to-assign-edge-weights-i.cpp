class Solution {
public:
    static const int MOD = 1e9 + 7;

    int maxdepth(unordered_map<int, vector<int>>& adj, int node, int parent) {
        int d = 0;

        for (int ngbr : adj[node]) {
            if (ngbr == parent) continue;

            d = max(d, 1 + maxdepth(adj, ngbr, node));
        }

        return d;
    }

    long long power(long long base, long long exp) {
        long long res = 1;

        while (exp > 0) {
            if (exp & 1)
                res = (res * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int d = maxdepth(adj, 1, -1);

        if (d == 0) return 1;

        return (int)power(2, d - 1);
    }
};