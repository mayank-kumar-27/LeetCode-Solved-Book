class Solution {
    public int numberOfSteps(int n) {
        int s = 0;
        while (n > 0) {
            n = (n & 1) == 0 ? n >> 1 : n - 1;
            s++;
        } return s;
    }
}