class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        // vector<int> lessp;
        // vector<int> grp;
        // vector<int> p;
        // for(int i = 0; i < nums.size(); i++) {
        //     if(nums[i] == pivot) {
        //         p.push_back(nums[i]);  
        //     } else if(nums[i] > pivot) {
        //         grp.push_back(nums[i]); 
        //     } else {
        //         lessp.push_back(nums[i]); 
        //     }
        // }
        // vector<int> result;
        // for(int i = 0; i < lessp.size(); i++) {
        //     result.push_back(lessp[i]);
        // }
        // for(int i = 0; i < p.size(); i++) {
        //     result.push_back(p[i]);
        // }
        // for(int i = 0; i < grp.size(); i++) {
        //     result.push_back(grp[i]);
        // }
        
        int lesscnt = 0;
        int equalcnt = 0;
        for(int &num : nums){
            if(num < pivot){
                lesscnt++;
            }else if(num == pivot){
                equalcnt++;
            }
        }
        
        vector<int> result(n);
        int i = 0;
        int j = lesscnt;
        int k = equalcnt + lesscnt;
        
        for(int &num: nums){
            if(num < pivot){
                result[i] = num;
                i++;
            }else if(num == pivot){
                result[j] = num;
                j++;
            }else{
                result[k] = num;  
                k++;
            }
        }
        return result;
    }
};