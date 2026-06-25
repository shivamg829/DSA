class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tsum = 0;
        for(int i = 0 ; i<nums.size(); i++){
            tsum+=nums[i];
        }
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            int rsum = tsum-sum-nums[i];
            if(rsum==sum){
                return i;
            }
            sum+=nums[i];
        }
        return -1;
    }
};