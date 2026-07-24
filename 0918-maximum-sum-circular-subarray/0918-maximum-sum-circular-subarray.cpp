class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int total = 0;
        int currMax = 0;
        int currMin = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            total+=nums[i];
            currMax = max(currMax+nums[i], nums[i]);
            maxSum = max(maxSum, currMax);
            currMin = min(currMin+nums[i], nums[i]);
            minSum = min(minSum, currMin);
        }
        if (maxSum < 0){
            return maxSum;
        }
        return max(maxSum, total-minSum);
    }
};