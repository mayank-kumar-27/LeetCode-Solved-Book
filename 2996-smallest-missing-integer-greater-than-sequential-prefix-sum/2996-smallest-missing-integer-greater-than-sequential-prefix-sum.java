class Solution {
    public int missingInteger(int[] a) {
        int s = a[0];
        for (int i = 1; i < a.length && a[i] == a[i - 1] + 1; i++)
            s += a[i];
        while (true) {
            boolean f = false;
            for (int x : a)
                if (x == s) {
                    f = true;
                    break;
                }
            if (!f) return s;
            s++;
        }
    }
}