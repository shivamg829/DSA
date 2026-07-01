class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt = 0;
        int l = 0;
        int n = s.size();
        unordered_map<char , int>mp;
        for(int i = 0; i<n; i++){
            if(mp.find(s[i])!=mp.end() && (mp[s[i]]>=l)){
                l=mp[s[i]]+1;
            }
            cnt = max(cnt, i-l+1);
            mp[s[i]] = i;
        }
        return cnt;
    }
};