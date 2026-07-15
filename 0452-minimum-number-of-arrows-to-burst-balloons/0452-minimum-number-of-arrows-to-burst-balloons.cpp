class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int cnt  = 1;
        int n = points.size();
        vector<int>temp = points[0];
        for(int i = 1; i<n; i++){
            vector<int>curr = points[i];
            if(curr[0]<=temp[1]){
                temp[1] = min(temp[1], curr[1]);
            }else{
                cnt++;
                temp = curr;
            }
        }
        return cnt;
    }
};