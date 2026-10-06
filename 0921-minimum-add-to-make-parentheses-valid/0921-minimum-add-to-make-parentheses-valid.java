class Solution {
    public int minAddToMakeValid(String s) {
        int o = 0, c = 0;
        for (char x : s.toCharArray()) {
            if (x == '(')  o++;
            else if (o > 0)  o--;
            else c++;
        } return o + c;
    }
}