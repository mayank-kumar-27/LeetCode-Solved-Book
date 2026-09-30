class Solution {
    public int[] replaceElements(int[] arr) {
        int m = -1;
        for (int i = arr.length - 1; i > -1; i--) {
            int c = arr[i];
            arr[i] = m;
            m = Math.max(m, c);
        } return arr;
    }
}