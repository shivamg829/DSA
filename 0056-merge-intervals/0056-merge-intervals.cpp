class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>>ans;
        vector<int>temp = intervals[0];
        for(int i = 0; i<n; i++){
            vector<int>curr = intervals[i];
            if(curr[0]<=temp[1]){
                temp[1] = max(curr[1], temp[1]);
            }
            else{
                ans.push_back(temp);
                temp=curr;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};