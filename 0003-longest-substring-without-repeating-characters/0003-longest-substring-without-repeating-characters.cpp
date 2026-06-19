class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int l = 0;
        int r = 0;
        int n = s.size();
        if(n==0) return 0;
        vector<int>cnt(256 , -1);
        while(r<n){
            if(cnt[s[r]]!=-1){
                if(cnt[s[r]]>=l){
                    l=cnt[s[r]]+1;
                }
            }
            int len = r-l+1;
            maxLen = max(maxLen,len);
            cnt[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};