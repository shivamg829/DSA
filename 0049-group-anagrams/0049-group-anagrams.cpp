class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>ans;
        for(string& s : strs){
            string key = s;
            sort(key.begin(), key.end());
            ans[key].push_back(s);
        }
        vector<vector<string>>res;
        for(auto & s : ans){
            res.push_back(s.second);
        }
        return res;
    }
};