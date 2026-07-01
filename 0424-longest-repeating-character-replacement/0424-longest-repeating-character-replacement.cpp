class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxFreq = 0; 
        int maxWindow = 0;
        int l = 0;
        vector<int>freq(26, 0);
        for(int i = 0; i<n; i++){
            freq[s[i]-'A']++;
            maxFreq = max(maxFreq, freq[s[i]-'A']);
            int windowLen = i-l+1;

            if(windowLen-maxFreq>k){
                freq[s[l]-'A']--;
                l++;
            }
            windowLen= i-l+1;
            maxWindow = max(maxWindow, windowLen);
        }
        return maxWindow;
    }
};