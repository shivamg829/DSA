class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ltseen[3] = {-1, -1 , -1};
        int cnt = 0;
        for(int i = 0; i<n; i++){
            ltseen[s[i]-'a'] = i;
            if(ltseen[0]!=-1 && ltseen[1]!=-1 && ltseen[1]!=-1){
                cnt = cnt+(1+min(ltseen[0], min(ltseen[1], ltseen[2])));
            }
        }
        return cnt;
    }
};