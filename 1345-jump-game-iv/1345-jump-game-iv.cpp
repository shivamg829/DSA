class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>>mp;
        vector<bool>vis(n, false);
        for(int i = 0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        int steps = 0;
        vis[0]=true;
        q.push(0);
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int curr = q.front();
                q.pop();
                int l = curr-1;
                int r= curr+1;
                if(curr==n-1){
                    return steps;
                }
                if(l>=0 && !vis[l]){
                    q.push(l);
                    vis[l]=true;
                }
                if(r<=n-1 && !vis[r]){
                    q.push(r);
                    vis[r]=true;
                }
                for(int &ind : mp[arr[curr]]){
                    if(!vis[ind]){
                        q.push(ind);
                        vis[ind]=true;
                    }
                }
                mp.erase(arr[curr]);
            }
            steps++;
        }
        return -1;
    }
};