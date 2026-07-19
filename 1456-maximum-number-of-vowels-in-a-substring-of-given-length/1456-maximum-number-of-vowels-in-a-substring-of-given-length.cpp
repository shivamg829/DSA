class Solution {
public:
    int maxVowels(string s, int k) {
        int  l = 0; 
        int r = 0;
        int n = s.size();
        int cnt = 0;
        while(r<k){
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u'){
                cnt++;
            }
            r++;
        }
        int maxCnt = cnt;
        while(r<n){
            if(s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u'){
                cnt--;
            }
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u'){
                cnt++;
            }
            r++;
            l++;
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt;
    }
};