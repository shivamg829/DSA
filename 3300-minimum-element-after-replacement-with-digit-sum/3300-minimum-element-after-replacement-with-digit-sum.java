class Solution {
    public int minElement(int[] nums) {
        int n = nums.length;
        int minSum = Integer.MAX_VALUE;
        for(int num : nums){
            int numm = num;
            int sum = 0;
            while(numm>0){
                int r = numm%10;
                sum+=r;
                numm/=10;
            }
            if(minSum>sum){
                minSum=sum;
            }
        }
        return minSum;
    }
}