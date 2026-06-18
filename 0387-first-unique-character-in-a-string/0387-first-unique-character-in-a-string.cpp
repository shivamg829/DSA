class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int>cnt(26, 0);
        for(int i = 0; i<n; i++){
            int ch = s[i]-'a';
            cnt[ch]++;
        }
        for(int i = 0; i<n; i++){
            int ch = s[i]-'a';
            if(cnt[ch]==1) return i;
        }
        return -1;
    }
};