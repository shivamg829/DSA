class Solution {
public:
    int noOfDay(vector<int>&weights, int cap){
        int day = 1;
        int load = 0;
        int n = weights.size();
        for(int i = 0; i<n; i++){
            if(load+weights[i]>cap){
                load =weights[i];
                day++;
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
            int noOfD = noOfDay(weights, m);
            if(noOfD>days){
                l=m+1;
            }else{
                h=m-1;
            }
        }
        return l;
    }
};