class Solution {
public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> inde(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            inde[p[0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (inde[i] == 0) {
                q.push(i);
            }
        }
        vector<int>topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                inde[it]--;
                if (inde[it] == 0) {
                    q.push(it);
                }
            }
        }
        if (topo.size() == numCourses) {
            return topo;
        }
        return {};
    }
};