class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int ans = 0;
        if(nums[r]<target) return n;
        while(l<=r){
            int m = l + (r-l)/2;
            if(nums[m]>=target){
                ans = m;
                r = m-1;;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};