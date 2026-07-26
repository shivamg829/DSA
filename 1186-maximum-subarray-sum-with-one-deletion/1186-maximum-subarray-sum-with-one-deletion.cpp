class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int withOneDel = 0;         
        int withOutDel = nums[0];     
        for(int i = 1; i < n; i++){
            int oldWithOutDel = withOutDel;
            int oldWithOneDel = withOneDel;
            withOutDel = max(nums[i], oldWithOutDel + nums[i]);
            withOneDel = max(oldWithOutDel, oldWithOneDel + nums[i]); 
            maxSum = max(maxSum, max(withOutDel, withOneDel));
        }
        return maxSum;
    }
};