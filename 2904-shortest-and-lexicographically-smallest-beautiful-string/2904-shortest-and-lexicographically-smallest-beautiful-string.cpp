class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int len = INT_MAX;
        int l = 0;
        int cnt = 0;
        int n = s.size();
        string result = "";
        
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                cnt++;
            }
            while(cnt >= k){
                if(cnt == k){
                    int currLen = i - l + 1;
                    if(currLen < len){
                        len = currLen;
                        result = s.substr(l, currLen);
                    }
                    else if(currLen == len){
                        string curr = s.substr(l, currLen);
                        if(curr < result){
                            result = curr;
                        }
                    }
                }
                if(s[l] == '1'){
                    cnt--;
                }
                l++;
            }
        }
        
        return result;
    }
};