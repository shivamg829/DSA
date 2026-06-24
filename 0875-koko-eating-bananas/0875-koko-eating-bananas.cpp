class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int t = *max_element(piles.begin(), piles.end());
        int ans = t;
        while(l <= t){
            int m = l + (t - l) / 2;
            long long hr = 0;
            for(int pile : piles){
                hr += (pile + m - 1) / m;
            }
            if(hr <= h){
                ans = m;
                t = m - 1;
            }else{
                l = m + 1;
            }
        }

        return ans;
    }
};