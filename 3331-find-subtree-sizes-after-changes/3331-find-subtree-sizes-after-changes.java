class Solution {
    public int[] findSubtreeSizes(int[] parent, String s) {
        int n = parent.length;

        List<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 1; i < n; i++) {
            adj[parent[i]].add(i);
        }

        int[] np = new int[n];
        int[] last = new int[26];
        int[] old = new int[n];

        Arrays.fill(last, -1);

        int[] st = new int[2 * n];
        int top = 0;

        st[top++] = 0;

        while (top > 0) {
            int v = st[--top];

            if (v < 0) {
                v = ~v;
                last[s.charAt(v) - 'a'] = old[v];
                continue;
            }

            int c = s.charAt(v) - 'a';
            old[v] = last[c];

            if (v != 0) {
                np[v] = last[c] == -1 ? parent[v] : last[c];
            }

            last[c] = v;

            st[top++] = ~v;

            for (int x : adj[v]) {
                st[top++] = x;
            }
        }

        List<Integer>[] tree = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }

        for (int i = 1; i < n; i++) {
            tree[np[i]].add(i);
        }

        int[] order = new int[n];
        top = 0;
        int idx = 0;

        st[top++] = 0;

        while (top > 0) {
            int v = st[--top];
            order[idx++] = v;

            for (int x : tree[v]) {
                st[top++] = x;
            }
        }

        int[] ans = new int[n];
        Arrays.fill(ans, 1);

        for (int i = n - 1; i > 0; i--) {
            int v = order[i];
            ans[np[v]] += ans[v];
        }

        return ans;
    }
}
