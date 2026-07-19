class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size(); 
        int r = 0;
        double sum = 0;
        while(r<k){
            sum+=nums[r];
            r++;
        }
        double maxSum = sum;
        while(r<n){
            sum+=nums[r];
            sum-=nums[l];
            r++;
            l++;
            maxSum = max(maxSum, sum);
        }
        return maxSum/k;
    }
};