class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        int l = 0;
        int cntzero = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==0) cntzero++;
            while(cntzero>1){
                if(nums[l]==0){
                    cntzero--;
                }
                l++;
            }
            len = max(len, i-l);
        }
        return len;
    }
};