class Solution {
    public List<Integer> targetIndices(int[] arr, int t) {
        Arrays.sort(arr);
        ArrayList<Integer> r = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) if (arr[i] == t) r.add(i);
        return r;
    }
}