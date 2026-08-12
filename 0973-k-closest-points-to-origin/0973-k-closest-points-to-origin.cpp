class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        // store distance and idx
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int dis = x*x+y*y;
            pq.push({dis, i});
        }
        while(k-- && !pq.empty()){
            int idx = pq.top().second;
            ans.push_back(points[idx]);
            pq.pop();
        }
        return ans;
    }
};