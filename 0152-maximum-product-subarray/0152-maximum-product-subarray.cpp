class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int maxPro = nums[0];
        int minPro = nums[0];
        for(int i = 1; i<n; i++){
            int preMax = maxPro;
            maxPro = max(nums[i], max(preMax*nums[i], minPro*nums[i]));
            minPro = min(nums[i], min(preMax*nums[i], minPro*nums[i]));
            ans = max(maxPro, ans);
        }
        return ans;
    }
};