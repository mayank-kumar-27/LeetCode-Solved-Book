int gd(int p, int q) { return abs(p/6 - q/6) + abs(p%6 - q%6); }
int minimumDistance(char* w) {
    int n = strlen(w);
    int dp[n][26][26];
    for (int i=0;i<n;i++) for (int j=0;j<26;j++) for (int k=0;k<26;k++)
    dp[i][j][k] = INT_MAX/2;
    for (int i=0;i<26;i++) dp[0][i][w[0]-'A'] = dp[0][w[0]-'A'][i] = 0;
    for (int i=1;i<n;i++) {
        int c=w[i]-'A', p=w[i-1]-'A', d=gd(p,c);
        for (int j=0;j<26;j++) {
            dp[i][c][j] = fmin(dp[i][c][j], dp[i-1][p][j]+d);
            dp[i][j][c] = fmin(dp[i][j][c], dp[i-1][j][p]+d);
            if (p==j) for (int k=0;k<26;k++) {
                int d0=gd(k,c);
                dp[i][c][j] = fmin(dp[i][c][j], dp[i-1][k][j]+d0);
                dp[i][j][c] = fmin(dp[i][j][c], dp[i-1][j][k]+d0);
            }
        }
    }
    int ans=INT_MAX/2;
    for (int i=0;i<26;i++) for (int j=0;j<26;j++) if (dp[n-1][i][j]<ans) ans=dp[n-1][i][j];
    return ans;
}
