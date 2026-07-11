class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        int completeComponents = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;
                vector<int> component;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);
                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
                int size = component.size();
                bool isComplete = true;
                for (int node : component) {
                    if (adj[node].size() != size - 1) {
                        isComplete = false;
                        break;
                    }
                }
                if (isComplete) {
                    completeComponents++;
                }
            }
        }
        
        return completeComponents;
    }
};