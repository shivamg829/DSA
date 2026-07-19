class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int>freq(26, 0);
        int maxwindow = 0;
        int maxFreq = 0;
        int l = 0;
        for(int i = 0; i<n; i++){
            freq[s[i]-'A']++;
            maxFreq = max(maxFreq, freq[s[i]-'A']);
            if((i-l+1)-maxFreq>k){
                freq[s[l]-'A']--;
                l++;
            }
            maxwindow = max(maxwindow, i-l+1);
        }
        return maxwindow;
    }
};