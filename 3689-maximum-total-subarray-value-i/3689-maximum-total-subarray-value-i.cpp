class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int mini =  INT_MAX;
        int maxi = INT_MIN;
        for(int &num : nums){
            maxi = max(maxi, num);
            mini = min(mini, num);
        }
        return 1L * (maxi - mini) * k;
    }
};