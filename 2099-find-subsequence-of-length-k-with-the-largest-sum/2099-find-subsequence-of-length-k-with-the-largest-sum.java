class Solution {
    public int[] maxSubsequence(int[] a, int k) {
        PriorityQueue<Integer> q = new PriorityQueue<>((i,j)->a[i]-a[j]);
        for(int i=0;i<a.length;i++){
            q.add(i);
            if(q.size()>k) q.poll();
        }
        int[] r=new int[k];
        for(int i=0;i<k;i++) r[i]=q.poll();
        Arrays.sort(r);
        for(int i=0;i<k;i++) r[i]=a[r[i]];
        return r;
    }
}