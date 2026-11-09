class Solution {
    public List<Integer> busiestServers(int k, int[] arr, int[] load) {
        int[] cnt = new int[k];
        int max = 0;
        TreeSet<Integer> free = new TreeSet<>();
        for (int i = 0; i < k; i++) free.add(i);
        PriorityQueue<int[]> busy = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));

        for (int i = 0; i < arr.length; i++) {
            int t = arr[i];
            while (!busy.isEmpty() && busy.peek()[0] <= t) {
                free.add(busy.poll()[1]);
            }
            if (free.isEmpty()) continue;
            Integer s = free.ceiling(i % k);
            if (s == null) s = free.first();
            free.remove(s);
            busy.offer(new int[]{t + load[i], s});
            max = Math.max(max, ++cnt[s]);
        }

        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            if (cnt[i] == max) res.add(i);
        }
        return res;
    }
}