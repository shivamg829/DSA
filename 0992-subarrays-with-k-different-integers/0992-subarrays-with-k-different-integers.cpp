class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int n = nums.size();
        int l = 0;
        int ans = 0;
        int i = 0;
        while(i<n){
            mp[nums[i]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            ans+=i-l+1;
            i++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};