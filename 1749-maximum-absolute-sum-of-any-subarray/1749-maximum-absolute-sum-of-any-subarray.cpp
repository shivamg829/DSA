class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;
        int minSum = 0;
        int minEnd = 0;
        int maxEnd = 0;
        for(int i = 0; i < n; i++){
            maxEnd = max(nums[i], maxEnd+nums[i]);
            maxSum = max(maxEnd, maxSum);
            minEnd = min(nums[i], minEnd+nums[i]);
            minSum = min(minEnd, minSum);
        }
        return max(maxSum, abs(minSum));
    }
};