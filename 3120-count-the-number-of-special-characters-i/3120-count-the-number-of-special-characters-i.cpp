class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        bool lowerFound[26] = {false};
        bool upperFound[26] = {false};
        
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            if (islower(c)) {
                lowerFound[c - 'a'] = true;
            } else if (isupper(c)) {
                upperFound[tolower(c) - 'a'] = true;
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (lowerFound[i] && upperFound[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};