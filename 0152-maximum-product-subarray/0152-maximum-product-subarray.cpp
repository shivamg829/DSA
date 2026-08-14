class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int maxpro = nums[0];
        int minpro = nums[0];
        for(int i = 1; i<n; i++){
            int premax = maxpro;
            maxpro = max(nums[i], max(minpro*nums[i], premax*nums[i]));
            minpro = min(nums[i], min(minpro*nums[i], premax*nums[i]));
            ans = max(ans, maxpro);
        }
        return ans;
    }
};