class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = 0;
        int el2 = 0;
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==el1){
                cnt1++;
            }else if(nums[i]==el2){
                cnt2++;
            }else if(cnt1==0 && nums[i]!=el2){
                el1 = nums[i];
                cnt1++;
            }else if(cnt2==0 && nums[i]!=el1){
                el2 = nums[i];
                cnt2++;
            }else{
                cnt2--;
                cnt1--;
            }
        }

        int cntt1 = 0;
        int cntt2 = 0;
        vector<int>ans;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==el1){
                cntt1++;
            }
            else if(nums[i]==el2){
                cntt2++;
            }
        }
        if(cntt1>n/3){
            ans.push_back(el1);
        }
        if(cntt2>n/3){
            ans.push_back(el2);
        }
        return ans;
    }
};