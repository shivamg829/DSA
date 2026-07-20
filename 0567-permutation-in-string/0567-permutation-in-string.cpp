class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int>f1(26, 0);
        vector<int>f2(26, 0);
        if(n>m) return false;
        for(int i = 0; i<n; i++){
            f1[s1[i]-'a']++;
            f2[s2[i]-'a']++;
        }
        if(f1==f2) return true;
        for(int j = n; j<m; j++){
            f2[s2[j]-'a']++;
            f2[s2[j-n]-'a']--;
            if(f1==f2) return true;
        }
        return false;
    }
};