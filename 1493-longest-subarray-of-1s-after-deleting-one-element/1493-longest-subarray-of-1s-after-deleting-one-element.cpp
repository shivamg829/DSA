class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int zeros = 0;
        int maxLen = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==0) zeros++;
            while(zeros>1){
                if(nums[l]==0){
                    zeros--;
                }
                l++;
            }
            if(zeros<=1){
                maxLen = max(maxLen, i-l);
            }
        }
        return maxLen;
    }
};