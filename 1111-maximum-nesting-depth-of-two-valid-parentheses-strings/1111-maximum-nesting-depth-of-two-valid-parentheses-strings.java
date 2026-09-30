class Solution {
    public int[] maxDepthAfterSplit(String s) {
        int[] a = new int[s.length()];
        int d = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                d++; a[i] = d & 1;
            } else {
                a[i] = d & 1; d--;
            }
        } return a;
    }
}