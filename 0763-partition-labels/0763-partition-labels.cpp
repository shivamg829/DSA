class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> max_id(26,-1);
        for (int i = 0; i < s.size(); i++) {
            max_id[s[i] - 'a'] = i;
        }
        int cur_max = 0;
        int pre_max = 0;
        int i = 0;
        vector<int> ans;
        while (cur_max < s.size()) {
            while (i <= cur_max) {
                cur_max = max(cur_max, max_id[s[i] - 'a']);
                i++;
            }
            ans.push_back(cur_max - pre_max + 1);
            cur_max++;
            pre_max = cur_max;
        }
        return ans;
    }
};