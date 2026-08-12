class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count Freq
        unordered_map<int, int>mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        // insert in max heap
        priority_queue<pair<int, int>>pq;
        for( auto & [num, count] : mp){
            pq.push({count, num});
        }
        // ans
        vector<int>ans;
        while(k-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};