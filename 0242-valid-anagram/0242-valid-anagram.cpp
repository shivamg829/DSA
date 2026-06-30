class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int n = s.size();
        unordered_map<char, int>cnt;
        for(int i = 0; i<n; i++){
            cnt[s[i]-'a']++;
        }
        for(int i = 0; i<n; i++){
            cnt[t[i]-'a']--;
            if(cnt[t[i]-'a']<0) return false;
        }
        return true;
    }
};