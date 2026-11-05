class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        int c = 0;
        for (int x : arr1) {
            boolean ok = true;
            for (int y : arr2) ok &= Math.abs(x - y) > d;
            c += ok ? 1 : 0;
        } return c;
    }
}