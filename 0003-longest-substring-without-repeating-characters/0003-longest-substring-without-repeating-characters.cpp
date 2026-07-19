class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int l = 0;
        int len  = 0;
        int n = s.size();
        for(int i = 0; i<n; i++){
            char ch = s[i];
            if(mp.find(ch)!=mp.end() && mp[ch]>=l){
                l = mp[ch]+1;
            }
            len = max(len, i-l+1);
            mp[ch]=i;
        }
        return len;
    }
};