class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int ch[26] = {0};
        for(int i = 0; i<s.size(); i++){
            ch[s[i]-'a']++;
        }for(int i = 0; i<t.size(); i++){
            ch[t[i]-'a']--;
            if(ch[t[i]-'a']<0) return false;
        }
        return true;
    }
};