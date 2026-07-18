class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        while (r < n && nums[r] < 0) {
            r++;
        }
        
        int l = r - 1;  
        vector<int> ans;
        while (l >= 0 && r < n) {
            int neg = nums[l] * nums[l];
            int pos = nums[r] * nums[r];
            
            if (neg > pos) {
                ans.push_back(pos);
                r++;
            } else {
                ans.push_back(neg);
                l--;
            }
        }
        while (l >= 0) {
            ans.push_back(nums[l] * nums[l]);
            l--;
        }
        
        while (r < n) {
            ans.push_back(nums[r] * nums[r]);
            r++;
        }
        
        return ans;
    }
};