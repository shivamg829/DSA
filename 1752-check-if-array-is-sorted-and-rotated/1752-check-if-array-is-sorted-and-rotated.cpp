class Solution {
public:
    bool check(vector<int>& nums) {
        int c = 0;
        int n = nums.size();
        for(int i = 1; i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                c++;
            }
        }
        if(nums[n-1]>nums[0]){
            c++;
        }
        return c<=1;
    }
};