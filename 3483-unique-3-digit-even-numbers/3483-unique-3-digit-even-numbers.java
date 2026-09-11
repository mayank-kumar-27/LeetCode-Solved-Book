class Solution {
    public int totalNumbers(int[] d) {
        int[] c = new int[10];
        for (int x : d) c[x]++;
        int r = 0;
        for (int a = 1; a <= 9; a++) {
            if (c[a] == 0) continue;
            c[a]--;
            for (int b = 0; b <= 9; b++) {
                if (c[b] == 0) continue;
                c[b]--;
                for (int e = 0; e <= 8; e += 2) {
                    if (c[e] > 0) r++;
                } c[b]++;
            } c[a]++;
        } return r;
    }
}