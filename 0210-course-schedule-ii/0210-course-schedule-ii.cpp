class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        vector<int>indegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);
        for(int i = 0; i<prerequisites.size(); i++){
            int src = prerequisites[i][0];
            int des = prerequisites[i][1];
            adj[src].push_back(des);
            indegree[des]++;
        }
        queue<int>q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int neigh : adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};