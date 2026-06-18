class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.size();
        if(n==0) return true;
        for(int i = 0; i<n; i++){
            char ch = s[i];
            if(ch=='(' || ch == '{' || ch == '['){
                st.push(ch);
            }else{
                if(st.empty()) return false;
                if(st.top()=='[' && ch!=']' || st.top()=='(' && ch!=')' || st.top()=='{' && ch!='}' ){
                    return false;
                }else{
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};