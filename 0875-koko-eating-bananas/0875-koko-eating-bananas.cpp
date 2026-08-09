class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = *max_element(piles.begin(), piles.end());
        int l = 1;
        int r = n;
        while(l<r){
            int m = l+(r-l)/2;
            long long hr = 0;
            for(int pile : piles){
                hr+=(pile+m-1)/m;
            }
            if(hr<=h){
                r=m;
            }else{
                l=m+1;
            }
        }
        return l;
    }
};