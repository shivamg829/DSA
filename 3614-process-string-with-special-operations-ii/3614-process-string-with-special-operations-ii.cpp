class Solution {
public:
    char processStr(string s, long long k) {
        const long long INF = 4e18;
        int n = s.size();

        vector<long long> len(n);
        long long cur = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') {
                cur++;
            } 
            else if (ch == '*') {
                if (cur > 0) cur--;
            } 
            else if (ch == '#') {
                cur = min(INF, cur * 2);
            } 

            len[i] = cur;
        }

        if (k < 0 || k >= cur) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            long long before = (i == 0 ? 0 : len[i - 1]);

            if (ch >= 'a' && ch <= 'z') {
                if (k == before) return ch;
            } 
            else if (ch == '#') {
                if (before > 0) {
                    k %= before;
                }
            } 
            else if (ch == '%') {
                k = before - 1 - k;
            }
        }

        return '.';
    }
};