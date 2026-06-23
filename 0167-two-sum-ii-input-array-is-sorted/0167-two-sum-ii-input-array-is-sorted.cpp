class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        if(numbers.size()==2){
            if(numbers[0]+numbers[1]==target){
                return {1, 2};
            }
        }
        while(l<r){
            int sum = numbers[l] + numbers[r];
            if(sum==target){
                return {l+1,r+1};
            }
            else if(sum>target){
                r--;
            }
            else{
                l++;
            }
        }
        return {};
    }
};