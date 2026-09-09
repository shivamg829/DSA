class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer>first = new HashSet<>();
        HashSet<Integer>res = new HashSet<>();
        for(int num: nums1){
            first.add(num);
        }
        for(int num: nums2){
            if(first.contains(num)){
                res.add(num);
            }
        }
        int [] ans = new int[res.size()];
        int i = 0;
        for(int num : res){
            ans[i]=num;
            i++;
        }
        return ans;
    }
}