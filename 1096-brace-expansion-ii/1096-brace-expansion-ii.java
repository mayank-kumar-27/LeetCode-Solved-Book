class Solution {
    String s;
    int i;

    public List<String> braceExpansionII(String e) {
        s = e;
        i = 0;
        return new ArrayList<>(f());
    }

    private Set<String> a() {
        Set<String> r = new TreeSet<>();

        if (s.charAt(i) == '{') {
            i++;
            r = f();
        } else {
            r.add("" + s.charAt(i));
        }

        i++;
        return r;
    }

    private Set<String> b() {
        Set<String> r = new TreeSet<>();
        r.add("");

        while (i < s.length() &&
              (s.charAt(i) == '{' || Character.isLetter(s.charAt(i)))) {

            Set<String> x = a();
            Set<String> t = new TreeSet<>();

            for (String p : r)
                for (String q : x)
                    t.add(p + q);

            r = t;
        }

        return r;
    }

    private Set<String> f() {
        Set<String> r = new TreeSet<>();

        while (true) {
            r.addAll(b());

            if (i < s.length() && s.charAt(i) == ',')
                i++;
            else
                break;
        }

        return r;
    }
}