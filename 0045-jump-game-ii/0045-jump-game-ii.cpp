class Solution {
public:
    int jump(vector<int>& nums) {
        int j = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        for(int i = 0; i<n-1; i++){
            r  = max(r, i+nums[i]);
            if(i==l){
                j++;
                l=r;
            }
        }
        return j;
    }
};