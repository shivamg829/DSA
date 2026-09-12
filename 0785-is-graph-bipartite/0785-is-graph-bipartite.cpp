class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, int curr, vector<int>& colors) {
        colors[node] = curr;
        for (int neigh : graph[node]) {
            if (colors[neigh] == -1) {
                if (!dfs(graph, neigh, 1 - curr, colors)) {
                    return false;
                }
            } else if (colors[neigh] == curr) {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                if (!dfs(graph, i, 0, colors)) {
                    return false;
                }
            }
        }
        return true;
    }
};