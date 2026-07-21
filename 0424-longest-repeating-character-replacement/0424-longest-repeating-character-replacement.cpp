class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int maxFreq = 0;
        int maxWindow = 0;
        vector<int>freq(256, 0);
        for(int i = 0; i<n; i++){
            freq[s[i]]++;
            maxFreq = max(maxFreq, freq[s[i]]);
            if((i-l+1)-maxFreq>k){
                freq[s[l]]--;
                l++;
            }
            maxWindow = max(maxWindow, i-l+1);
        }
        return maxWindow;
    }
};