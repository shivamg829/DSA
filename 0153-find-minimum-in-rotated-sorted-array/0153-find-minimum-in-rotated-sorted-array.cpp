class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        int ans= INT_MAX;
        while(l<=h){
            int m = l+(h-l)/2;
            if(nums[l]<=nums[h]){
                if(nums[l]<ans){
                    ans = nums[l];
                }
                break;
            }
            if(nums[l]<=nums[m]){
                if(nums[l]<ans){
                    ans = nums[l];
                }
                l = m+1;
            }
            else{
                if(nums[m]<ans){
                    ans = nums[m];
                }
                h = m-1;
            }
        }
        return ans;
    }
};