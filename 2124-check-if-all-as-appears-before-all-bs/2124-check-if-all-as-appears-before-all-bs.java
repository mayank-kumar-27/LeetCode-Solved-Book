class Solution {
    public boolean checkString(String s) {
        boolean b = false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'b') b = true;
            else if (b) return false;
        } return true;
    }
}
