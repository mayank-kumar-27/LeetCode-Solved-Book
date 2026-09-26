class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        Map<String, String> m = new HashMap<>();
        for (List<String> x : knowledge) m.put(x.get(0), x.get(1));

        StringBuilder a = new StringBuilder(), k = new StringBuilder();
        boolean f = false;
        for (char c : s.toCharArray()) {
            if (c == '(') f = true;
            else if (c == ')') {
                a.append(m.getOrDefault(k.toString(), "?"));
                k.setLength(0); f = false;
            } else if (f) k.append(c);
            else a.append(c);
        } return a.toString();
    }
}