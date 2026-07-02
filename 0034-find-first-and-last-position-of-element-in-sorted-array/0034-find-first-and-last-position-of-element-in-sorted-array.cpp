class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0; 
        int h = n-1;
        int last = -1;
        int first = -1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m]==target){
                first = m;
                h = m-1;
            }else if(nums[m]>target){
                h = m-1;
            }else{
                l = m+1;
            }
        }
        l = 0;
        h = n-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[m]==target){
                last = m;
                l = m+1;
            }else if(nums[m]>target){
                h = m-1;
            }else{
                l = m+1;
            }
        }
        return {first, last};
    }
};