class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int r = n-1;
        int l = 0;
        int maxA = 0;
        while(l<r){
            int h = min(height[l], height[r]);
            int w  = r-l;
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
            int area = w*h;
            maxA = max(maxA, area);
        }
        return maxA;
    }
};