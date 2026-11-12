class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 1;
        int cnt2 = 1;
        int maxi = INT_MIN;
        if(n==1) return 1;
        for(int i = 1; i<n; i++){
            if(nums[i]>nums[i-1]){
                cnt1++;
                cnt2 = 1;
            }else if(nums[i]<nums[i-1]){
                cnt1=1;
                cnt2++;
            }else{
                cnt1=1;
                cnt2=1;
            }
            maxi = max(maxi, max(cnt1, cnt2));
        }
        return maxi;
    }
};