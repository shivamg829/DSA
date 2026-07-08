class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for(int i = nums.size(); i>=0; i--){
            k--;
            if(k==0){
                return nums[i-1];
            }
        }
        return -1;
    }
};