class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt = 0;
        int l = 0;
        unordered_map<char, int>mp;
        int n = s.size();
        for(int  i = 0; i<n; i++){
            char c = s[i];
            if(mp.find(c)!=mp.end() && mp[c]>=l){
                l = mp[c]+1;
            }
            cnt = max(cnt, i-l+1);
            mp[s[i]]=i;
        }
        return cnt;
    }
};