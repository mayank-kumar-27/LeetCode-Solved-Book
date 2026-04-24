int furthestDistanceFromOrigin(char* m) {
    int i = -1, l = 0, r = 0, c = 0;
    while (m[++i] != '\0') {
        if (m[i] == 'L') l++;
        else if (m[i] == 'R') r++;
        else c++;
    }
    return abs(l - r) + c;
}