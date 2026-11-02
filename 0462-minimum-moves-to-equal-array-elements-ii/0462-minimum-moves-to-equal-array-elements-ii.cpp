class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int med = nums[n/2];
        int cnt = 0;
        for(int i = 0; i<n; i++){
            cnt+=abs(nums[i]-med);
        }
        return cnt;
    }
};