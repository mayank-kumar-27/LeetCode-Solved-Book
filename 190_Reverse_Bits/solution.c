int reverseBits(int n) {
    int r = 0;
    for (int i = 0; i < 32; i++) { r = (r << 1) | (n & 1); n = n >> 1; }
    return r;
}