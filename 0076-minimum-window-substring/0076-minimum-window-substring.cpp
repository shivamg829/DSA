class Solution {
public:
    string minWindow(string s, string t) {
        int n = t.size();
        int m = s.size();
        vector<int>freq(256, 0);
        for(int i = 0; i<n; i++){
            freq[t[i]]++;
        }
        int l = 0;
        int strIdx = -1;
        int mini = INT_MAX;
        int cnt  = 0;
        int r = 0;
        while(r<m){
            freq[s[r]]--;
            if(freq[s[r]]>=0){
                cnt++;
            }
            while(cnt==n){
                if(r-l+1<mini){
                    mini=r-l+1;
                    strIdx = l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return strIdx == -1 ? "" : s.substr(strIdx, mini);
    }
};