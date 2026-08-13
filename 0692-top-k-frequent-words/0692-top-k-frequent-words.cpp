class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++){
            mp[words[i]]++;
        }
        
        auto comp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);
        
        for(auto & [word, cnt] : mp){
            pq.push({cnt, word});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};