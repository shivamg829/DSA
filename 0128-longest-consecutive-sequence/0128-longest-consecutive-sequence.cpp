class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(), nums.end());
        int longest = 0;
        for(int num : mp){  
            if(mp.find(num - 1) == mp.end()){
                int curnum = num;
                int len = 1;
                while(mp.find(curnum + 1) != mp.end()){
                    curnum++;
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};