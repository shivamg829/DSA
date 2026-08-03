class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = INT_MIN;
        int r = height.size()-1;
        int l = 0;
        while(l<r){
            int h = min(height[l], height[r]);
            int w = r-l;
            int area = w*h;
            maxi = max(maxi, area);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxi;
    }
};