class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;  
        int curr = 0;
        int cnt = 0;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];
            if(mp.find(curr - k) != mp.end()){
                cnt += mp[curr - k];
            }
            mp[curr]++;
        }
        return cnt;
    }
};