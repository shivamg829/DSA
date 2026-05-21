class Solution {
public:
    int countt(int n){
        int cnt = 0;
        while(n>0){
            cnt++;
            n/=10;
        }
        return cnt;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>prefixes;
        for(int num: arr1){
            int x = num;
            while(x>0){
                prefixes.insert(x);
                x/=10;
            }
        }
        int ans = 0;
        for(int num: arr2){
            int x = num;
            int len = countt(num);
            while(x>0){
                if(prefixes.count(x)){
                    ans = max(ans, len);
                    break;
                }
                x/=10;
                len--;
            }
        }
        return ans;
    }
};