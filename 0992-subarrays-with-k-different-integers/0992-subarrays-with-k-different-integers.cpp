class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int l = 0;
        int cnt  = 0;
        unordered_map<int, int>mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            cnt += i-l+1;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};