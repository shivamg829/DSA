class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int>f1(26, 0);
        vector<int>f2(26, 0);
        vector<int>ans;
        if(n<m) return {};
        for(int i = 0; i<m; i++){
            f1[s[i]-'a']++;
            f2[p[i]-'a']++;
        }
        if(f1==f2) ans.push_back(0);
        for(int i = m; i<n; i++){
            f1[s[i]-'a']++;
            f1[s[i-m]-'a']--;
            if(f1==f2) ans.push_back(i-m+1);
        }
        return ans;
    }
};