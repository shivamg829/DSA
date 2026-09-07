class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer, Integer>mp = new HashMap<>();
        mp.put(0, 1);
        int n = nums.length;
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
            int diff = sum-k;
            if(mp.containsKey(diff)){
                cnt+=mp.get(diff);
            }
            mp.put(sum, mp.getOrDefault(sum, 0) + 1);
        }
        return cnt;
    }
}