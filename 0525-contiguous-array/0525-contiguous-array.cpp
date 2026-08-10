class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        mp[0]=-1;
        int presum = 0;
        int len = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==0){
                presum-=1;
            }else{
                presum+=1;
            }
            if(mp.find(presum)!=mp.end()){
                len = max(len, i-mp[presum]);
            }else{
                mp[presum] = i;
            }
        }
        return len;
    }
};