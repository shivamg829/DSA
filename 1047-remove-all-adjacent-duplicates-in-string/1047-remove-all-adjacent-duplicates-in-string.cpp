class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        stack<char>st;
        string ans = "";
        for(int i = 0; i<n; i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(s[i]==st.top()){
                st.pop();
                continue;
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            char c = st.top();
            st.pop();
            ans+=c;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};