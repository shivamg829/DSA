class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==1) return 1;
        vector<int>dp(n, 1);
        int maxIn = 0;
        for(int i = 1; i<n; i++){ 
            for(int j = 0; j<i; j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            maxIn = max(maxIn, dp[i]);
        }
        return maxIn;
    }
};