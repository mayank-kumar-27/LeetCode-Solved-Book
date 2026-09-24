class Solution {
    public List<Integer> majorityElement(int[] a) {
        int x = 0, y = 1, cx = 0, cy = 0;
        for (int n : a) {
            if (n == x) cx++;
            else if (n == y) cy++;
            else if (cx == 0) {
                x = n;  cx = 1;
            } else if (cy == 0) {
                y = n; cy = 1;
            } else {
                cx--; cy--;
            }
        }
        cx = cy = 0;
        for (int n : a) {
            if (n == x) cx++;
            else if (n == y) cy++;
        }
        List<Integer> r = new ArrayList<>();
        if (cx > a.length / 3) r.add(x);
        if (cy > a.length / 3) r.add(y);
        return r;
    }
}