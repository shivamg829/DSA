class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s1 = "";
        for(int i = 0; i<words.size(); i++){
            string s = words[i];
            int sum = 0;
            for(int k = 0; k<s.size(); k++){
                int letterIndex = s[k] - 'a';  
                sum += weights[letterIndex];    
            }
            int c = sum % 26;
            char ch = 'z' - c;  
            s1 += ch;
        }
        return s1;
    }
};