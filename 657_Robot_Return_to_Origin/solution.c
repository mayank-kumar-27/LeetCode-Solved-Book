bool judgeCircle(char* moves) {
    int l = 0, r = 0, u = 0, d = 0, i = -1;
    while (moves[++i] != '\0') { l += moves[i] == 'L'; r += moves[i] == 'R'; u += moves[i] == 'U'; d += moves[i] == 'D'; }
    return l == r && u == d;
}
