class Solution {
public:
    int numberSubarrays(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum+=nums[i]%2;
            while(sum>k){
                sum-=nums[l]%2;
                l++;
            }
            cnt += i-l+1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberSubarrays(nums, k) - numberSubarrays(nums, k-1);
    }
};