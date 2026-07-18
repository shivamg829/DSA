class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        int ans = 0;
        for(int i = 0; i<n-2; i++){
            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                int d = abs(target-sum);
                if(sum==target){
                    return target;
                }
                if(diff>d){
                    ans=sum;
                    diff=d;
                }
                if(sum<target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return ans;
    }
};