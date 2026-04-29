class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            queue<int> q;
            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;
            }
            while (!q.empty()) {
                auto node = q.front();
                q.pop();
                for (auto i : graph[node]) {
                    if (color[i] == -1) {
                        color[i] = !color[node];
                        q.push(i);
                    } else if (color[i] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};