class Solution {
public:
    int maxLen(int i, vector<int>&nums, vector<int>&dp){
        if(i==0) return nums[i];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int p = nums[i] + maxLen(i-2, nums, dp);
        int np = 0 + maxLen(i-1, nums, dp);
        return dp[i] = max(p , np);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return maxLen(n-1, nums, dp);
    }
};