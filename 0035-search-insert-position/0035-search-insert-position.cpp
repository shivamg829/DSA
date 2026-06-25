class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0; 
        int h = nums.size()-1;
        int n = nums.size();
        int ans = 0;
        if(nums[h]<target) return n;
        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m]>=target){
                ans = m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};