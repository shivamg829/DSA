class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int ans = r;
        while(l<=r){
            int m = l+(r-l)/2;
            long long hr = 0;
            for(int pile : piles){
                hr+=(pile+m-1)/m;
            }
            if(hr<=h){
                ans=m;
                r = m-1;
            }else{
                l = m+1;
            }
        }

        return ans;
    }
};