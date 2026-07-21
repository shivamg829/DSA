class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cntone = count(begin(s), end(s), '1');
        vector<int> inactive;
        
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0') i++;
                inactive.push_back(i - start);
            } else {
                i++;
            }
        }
        
        if (inactive.size() < 2) return cntone;
        
        int maxSum = 0;
        for (int i = 1; i < inactive.size(); i++) {
            maxSum = max(maxSum, inactive[i] + inactive[i-1]);
        }
        
        return cntone + maxSum;
    }
};