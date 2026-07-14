class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<int>f1(26, 0);
        vector<int>f2(26, 0);
        if (m > n) return false;
        for(int i = 0; i<m; i++){
            f1[s1[i]-'a']++;
            f2[s2[i]-'a']++;
        }
        if(f1==f2) return true;
        for(int i = m; i<n; i++){
            f2[s2[i]-'a']++;
            f2[s2[i-m]-'a']--;
            if(f1==f2) return true;
        }
        return false;
    }
};