class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int r = n-1;
        int l = 0;
        int f = -1;
        int la = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]==target){
                f = m;
                r = m-1;
            }else if(nums[m]<target){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        l = 0;
        r = n-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]==target){
                la = m;
                l = m+1;
            }else if(nums[m]<target){
                l = m+1;
            }else{
                r = m-1;
            }
        }
        return {f, la};
    }
};