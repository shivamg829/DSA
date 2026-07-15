class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        vector<int>temp = intervals[0];
        int n = intervals.size();
        for(int i = 1; i<n; i++){
            vector<int>&curr = intervals[i];
            if(curr[0]<=temp[1]){
                temp[1] = max(temp[1], curr[1]);
            }else{
                ans.push_back(temp);
                temp = curr;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};