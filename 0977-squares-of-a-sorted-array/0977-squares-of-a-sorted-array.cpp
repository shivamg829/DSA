class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        while(l<n && nums[l]<0){
            l++;
        }
        int r = l;
        l--;
        vector<int>ans;
        while(l>=0 && r<n){
            int neSq = nums[l]*nums[l];
            int poSq = nums[r]*nums[r];
            if(poSq>=neSq){
                ans.push_back(neSq);
                l--;
            }else{
                ans.push_back(poSq);
                r++;
            }
        }
        while(l>=0){
            ans.push_back(nums[l]*nums[l]);
            l--;
        }
        while(r<n){
            ans.push_back(nums[r]*nums[r]);
            r++;
        }
        return ans;
    }
};