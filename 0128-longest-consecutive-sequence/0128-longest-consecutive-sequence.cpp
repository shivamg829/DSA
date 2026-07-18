class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int>st(nums.begin(), nums.end());
       int longest = 0;
       for(int num : st){
            int len = 0;
            if(st.find(num-1)==st.end()){
                int currNum = num;
                int len = 1;
                while(st.find(currNum+1)!=st.end()){
                    len++;
                    currNum++;
                }
                longest = max(longest, len);
            }
       }
       return longest;
    }
};