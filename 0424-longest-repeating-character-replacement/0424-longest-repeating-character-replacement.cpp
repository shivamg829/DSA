class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int maxfreq = INT_MIN;
        int ans = 0;
        vector<int>freq(26, 0);
        for(int i = 0; i<n; i++){
            freq[s[i]-'A']++;
            maxfreq = max(maxfreq, freq[s[i]-'A']);
            while((i-l+1)-maxfreq>k){
                freq[s[l]-'A']--;
                l++;
            }
            ans = max(ans, i-l+1);
        }
        return ans;
    }
};