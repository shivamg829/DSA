class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char, int>mp;
        int l = 0;
        int len = 0;
        for(int i = 0; i<n; i++){
            mp[s[i]]++;
            while(mp[s[i]]>2){
                mp[s[l]]--;
                l++;
            }
            len = max(len, i-l+1);
        }
        return len;
    }
};