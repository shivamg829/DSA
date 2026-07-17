class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int n = nums.size();
        int currSum = 0;
        mp[0]=-1;
        for(int i = 0; i<n; i++){
            currSum+=nums[i];
            if(k!=0){
                currSum = currSum%k;
            }
            if(mp.find(currSum)!=mp.end()){
                if(i-mp[currSum]>=2){
                    return true;
                }
            }
            else{
                mp[currSum]=i;
            }
        }
        return false;
    }
};