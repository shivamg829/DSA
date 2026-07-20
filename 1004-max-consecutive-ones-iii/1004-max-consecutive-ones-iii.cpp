class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int maxWindow = 0;
        int maxFreq = 0;
        int n = nums.size();
        int zeros = 0;
        for(int r = 0; r<n; r++){
            if(nums[r]==0){
                zeros++;
            }
            while(zeros>k){
                if(nums[l]==0){
                    zeros--;
                }
                l++;
            }
            if(zeros<=k){
                maxWindow = max(maxWindow, r-l+1);
            }
            
        }
        return maxWindow;
    }
};