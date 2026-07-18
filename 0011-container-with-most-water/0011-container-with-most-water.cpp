class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int n = height.size();
        int r = n-1;
        int maxArea = 0;
        while(l<r){
            int h = min(height[l], height[r]);
            int w = r-l;
            maxArea = max(maxArea, h*w);
            if(height[l]>height[r]){
                r--;
            }else{
                l++;
            }
        }
        return maxArea;
    }
};