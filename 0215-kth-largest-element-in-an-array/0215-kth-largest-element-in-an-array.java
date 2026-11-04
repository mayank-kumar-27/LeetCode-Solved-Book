class Solution {
    public int findKthLargest(int[] a, int k) {
        PriorityQueue<Integer> q = new PriorityQueue<>(k);
        for (int x : a) {
            q.offer(x);
            if (q.size() > k) q.poll();
        } return q.peek();
    }
}