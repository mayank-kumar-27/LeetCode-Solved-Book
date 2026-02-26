int numSteps(char* s) {
    int r = 0, c = 0;
    for (int i = strlen(s) - 1; i > 0; i--) { int b = s[i] & 1; r += 1 + (b ^ c); c |= b; }
    return r + c;
}