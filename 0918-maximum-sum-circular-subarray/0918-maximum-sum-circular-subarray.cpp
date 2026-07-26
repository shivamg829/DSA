class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currMax = 0;
        int n = nums.size();
        int minSum = INT_MAX;
        int currMin = 0;
        int total = 0;
        for(int i = 0; i<n; i++){
            currMax = max(nums[i], nums[i]+currMax);
            maxSum = max(maxSum, currMax);
            currMin = min(nums[i], currMin+nums[i]);
            minSum = min(minSum, currMin);
            total+=nums[i];
        }
        if(maxSum < 0) return maxSum;
        return max(maxSum , total-minSum);
        
    }
};