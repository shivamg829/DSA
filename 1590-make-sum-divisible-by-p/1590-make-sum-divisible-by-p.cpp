class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        for (int num : nums)
            totalSum += num;
        int target = totalSum % p;
        if (target == 0)
            return 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        long long prefixSum = 0;
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int currRem = prefixSum % p;
            int need = (currRem - target + p) % p;
            if (mp.find(need) != mp.end()) {
                ans = min(ans, i - mp[need]);
            }
            mp[currRem] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};