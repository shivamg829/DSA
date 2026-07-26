class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int len = 0;
        int cntZero = 0;
        for(int i = 0; i<n; i++){
            if(nums[i]==0){
                cntZero++;
            }
            while(cntZero>k){
                if(nums[l]==0){
                    cntZero--;
                }
                l++;
            }
            len = max(len, i-l+1);
        }
        return len;
    }
};