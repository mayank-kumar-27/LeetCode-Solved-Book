class Solution {
    public int maxProfit(int[] prices) {
        int l = 0, r = 1, m = 0;
        while (r < prices.length){
            if (prices[l] < prices[r]) {
                int p = prices[r] - prices[l];
                m = m > p ? m : p;
            } else l = r;
            r++;
        } return m;
    }
}