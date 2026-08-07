public class Solution {
    public int maxFrequencyElements(int[] arr) {
        int[] f = new int[100];
        for (int n : arr) f[n - 1]++;
        Arrays.sort(f);
        int m = f.length - 1, t = f[m];
        while (m > 0 && f[m] == f[m - 1]) {
            t += f[m]; m--;
        } return t;
    }
}