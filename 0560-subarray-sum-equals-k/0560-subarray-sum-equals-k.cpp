class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int sum = 0;
        mp[0] = 1;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
            int diff = sum-k;
            if(mp.find(diff)!=mp.end()){
                cnt+=mp[diff];
            }
            mp[sum]++;
        }
        return cnt;
    }
};