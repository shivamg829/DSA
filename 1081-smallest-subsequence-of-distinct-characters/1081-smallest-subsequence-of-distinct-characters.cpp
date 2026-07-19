class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>vis(26, 0);
        vector<int>lastInd(26, 0);
        string ans;
        int n= s.size();
        for(int i =0; i<n; i++){
            lastInd[s[i]-'a']=i;
        }
        for(int i =0; i<n; i++){
            char ch = s[i];
            int idx = ch - 'a';
            if(vis[idx]==1) continue;
            while(ans.length()>0 && ans.back()>ch && lastInd[ans.back()-'a']>i){
                vis[ans.back()-'a']=0;
                ans.pop_back();
            }
            ans.push_back(ch);
            vis[idx]=1;
        }
        return ans;

    }
};