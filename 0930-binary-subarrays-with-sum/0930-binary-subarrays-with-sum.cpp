class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int cnt = 0;
        int sum = 0;
        int l = 0;
        int n = nums.size();
        unordered_map<int, int>mp;
        mp[0] = 1;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
            if(mp.find(sum-goal)!=mp.end()){
                cnt+=mp[sum-goal];
            }
            mp[sum]++;
        }
        return cnt;
    }
};