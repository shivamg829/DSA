class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int i = 0; i<stones.length; i++){
            pq.add(stones[i]);
        }
        while(pq.size()>=2){
            int f = pq.peek();
            pq.poll();
            int s = pq.peek();
            pq.poll();
            if(s!=f){
                pq.add(f-s);
            }
        }
        return pq.isEmpty() ? 0 : pq.peek();
    }
}