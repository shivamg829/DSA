class Solution {
public:
    int numofdays(vector<int>& weights, int cap){
        int day = 1;
        int load = 0;
        int n = weights.size();
        for(int i = 0; i<n; i++){
            if(load+weights[i]>cap){
                day++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low<=high){
            int mid = low+(high -low)/2;
            int nodays = numofdays(weights, mid);
            if(nodays<=days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }return low;
    }
};