class Solution {
    public int maxNumberOfFamilies(int n, int[][] a) {
        HashMap<Integer, Integer> m = new HashMap<>();
        for (int[] x : a) if (x[1] >= 2 && x[1] <= 9) m.put(x[0], m.getOrDefault(x[0], 0) | (1 << x[1]));
        int r = (n - m.size()) * 2;
        for (int x : m.values()) {
            boolean l = (x & 0b000000111100) == 0, q = (x & 0b001111000000) == 0, c = (x & 0b000011110000) == 0;
            if (l && q) r += 2;
            else if (l || q || c) r++;
        } return r;
    }
}