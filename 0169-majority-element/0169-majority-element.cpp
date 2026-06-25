class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int el = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]==el){
                cnt++;
            }else if(cnt==0){
                el = nums[i];
                cnt++;
            }else{
                cnt--;
            }
        }
        return el;
    }
};