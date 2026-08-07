class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0;
        int r = n-1;
        int maxL = INT_MIN;
        int maxR = INT_MIN;
        while(l<r){
            maxL = max(maxL, height[l]);
            maxR = max(maxR, height[r]);
            if(maxR<maxL){
                ans+=maxR-height[r];
                r--;
            }else{
                ans+=maxL-height[l];
                l++;
            }
        }
        return ans;
    }
};