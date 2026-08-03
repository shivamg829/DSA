class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int ans = 0;
        int maxl = 0;
        int maxr = 0;
        while(l<=r){
            maxl = max(maxl, height[l]);
            maxr = max(maxr, height[r]);
            if(maxl<maxr){
                ans+=(maxl-height[l]);
                l++;
            }else{
                ans+=(maxr-height[r]);
                r--;
            }  
        }
        return ans;
    }
};