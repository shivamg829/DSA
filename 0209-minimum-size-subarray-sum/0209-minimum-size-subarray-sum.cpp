class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int len = INT_MAX;
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
            while(sum>=target){
                len = min(len, i-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return len<INT_MAX ? len : 0;
    }
};