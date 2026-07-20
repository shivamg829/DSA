class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int l = 0;
        long long pro = 1;
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            pro*=nums[i];
            while(pro>=k){
                pro/=nums[l];
                l++;
            }
            cnt += i-l+1;
        }
        return cnt;
    }
};