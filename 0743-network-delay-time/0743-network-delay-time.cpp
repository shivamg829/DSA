class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& it : times) {
            int src = it[0];
            int des = it[1];
            int w   = it[2];
            adj[src].push_back({des, w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, k});                 // {distance, node}
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (dis[u] < d) continue;   
            for (auto& [v, w] : adj[u]) {
                if (dis[u] + w < dis[v]) {
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});   
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) { 
            if (dis[i] == INT_MAX) return -1;
            res = max(res, dis[i]);
        }
        return res;
    }
};