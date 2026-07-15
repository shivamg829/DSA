class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int cnt = 0;
        int last = intervals[0][1];
        int n = intervals.size();
        for(int i = 1; i<n; i++){
            if(intervals[i][0]>=last){
                last = intervals[i][1];
            }else{
                cnt++;
                last = min(last, intervals[i][1]);
            }
        
        }
        return cnt;
    }
};