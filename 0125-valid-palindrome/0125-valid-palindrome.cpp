class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for(int i = 0; i<s.size(); i++){
            char ch = s[i];
            if(ch>='a' && ch<='z'){
                s1+=ch;
            }
            else if(ch>='A' && ch<='Z'){
                s1+=tolower(ch);
            }else if(ch>='0' && ch<='9'){
                s1+=ch;
            }
        }
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        if(s1==s2){
            return true;
        }
        return false;
    }
};