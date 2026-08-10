class Solution {
public:
    int noDay(vector<int>& weights, int cap){
        int day = 1;
        int load = 0;
        for(int i = 0; i<weights.size(); i++){
            if(weights[i]+load>cap){
                day++;
                load = weights[i];
            }else{
                load+=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int h = accumulate(weights.begin(), weights.end(), 0);
        while(l<=h){
            int m = l+(h-l)/2;
            int noday = noDay(weights, m);
            if(noday>days){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return l;
    }
};