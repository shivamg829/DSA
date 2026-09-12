class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses, 0);
        for(int i = 0; i<prerequisites.size(); i++){
            int src = prerequisites[i][0];
            int des = prerequisites[i][1];
            adj[src].push_back(des);
            indegree[des]++;
        }
        queue<int>q;
        for(int i= 0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int processed = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            processed++;
            for(int neigh : adj[node]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        return processed == numCourses;
    }
};