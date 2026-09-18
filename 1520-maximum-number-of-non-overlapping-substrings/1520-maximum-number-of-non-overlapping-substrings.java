class Solution {
    public List<String> maxNumOfSubstrings(String s) {
        int[] l = new int[26], r = new int[26];
        Arrays.fill(l, -1);

        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - 'a';
            if (l[c] == -1) l[c] = i;
            r[c] = i;
        }

        List<int[]> a = new ArrayList<>();

        for (int c = 0; c < 26; c++) {
            if (l[c] == -1) continue;

            int x = l[c], y = r[c];
            boolean ok = true;

            for (int i = x; i <= y; i++) {
                int z = s.charAt(i) - 'a';
                if (l[z] < x) {
                    ok = false;
                    break;
                }
                y = Math.max(y, r[z]);
            }

            if (ok) a.add(new int[]{x, y});
        }

        a.sort((x, y) -> x[1] - y[1]);

        List<String> ans = new ArrayList<>();
        int e = -1;

        for (int[] x : a) {
            if (x[0] > e) {
                ans.add(s.substring(x[0], x[1] + 1));
                e = x[1];
            }
        }

        return ans;
    }
}