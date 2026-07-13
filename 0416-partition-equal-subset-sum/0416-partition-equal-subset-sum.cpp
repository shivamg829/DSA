class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums){
            sum+=num;
        }
        if(sum%2!=0) return false;
        int halfSum = sum/2;
        vector<bool>dp(halfSum+1, false);
        dp[0] = true;
        for(int num: nums){
            for(int i = halfSum; i>=num; i--){
                if(dp[i-num]){
                    dp[i]=true;
                }
            }
        }
        return dp[halfSum];
    }
};