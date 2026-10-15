class Solution {
    public int sumCounts(List<Integer> nums) {
        int r = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            Set<Integer> s = new HashSet<>();
            for (int j = i; j < n; j++) {
                s.add(nums.get(j));
                r += s.size() * s.size();
            }
        } return r;
    }
}