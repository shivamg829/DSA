class Solution {
public:


    vector<int> gcdValues(vector<int>& nums, vector<long long>& q) {
        int mx = *max_element(nums.begin(), nums.end()); 
        vector<int> freq(mx + 1, 0); // freq of each element 
        for(int x: nums) freq[x]++; 

        // Now since max is mx gcd(a, b) <= max(a, b) so max gcd = mx 
        vector<long long> gcd(mx + 1, 0); // I have to store here how many ele are multiples of i present in cnt
        for(int i = 1; i <= mx; i++) {
            gcd[i] = freq[i]; 
            for(int j = 2 * i; j <= mx; j += i) {
                gcd[i] += freq[j]; 
            }
        }

        // Now tell me one thing, How many pairs do I have? what does it mean? 
        // say I have gcd = g, then waht is the total no of pairs I can form? if cnt = gcd[g], then pairs = cnt * (cnt - 1) / 2; 

        for(int i = 1; i <= mx; i++) {
            gcd[i] = gcd[i] * (gcd[i] - 1) / 2; 
        }

        // Now what, see the pairs which has 2*j, 4*j, ... all these I haev to remove right? 
        for(int i = mx; i >= 1; i--) {
            for(int j = 2 * i; j <= mx; j+=i) {
                gcd[i] -= gcd[j]; 
            }
        }

        // Now we can have a sorted gcd prefix 
        vector<long long> pref(mx + 1, 0); 
        for(int i = 1; i <= mx; i++) {
            pref[i] += pref[i -1] + gcd[i]; 
        }

        // Now on this we will apply bs 
        vector<int> ans; 
        for(int i = 0; i < q.size(); i++) {
            long long qu = q[i]; 
            ans.push_back(lower_bound(pref.begin(), pref.end(), qu + 1) - pref.begin()); 
        }
        return ans; 
    }
};