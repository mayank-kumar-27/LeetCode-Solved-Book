/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* g_pos;
int cmp(const void* a, const void* b) { return g_pos[*(int*)a] - g_pos[*(int*)b]; }
int* survivedRobotsHealths(int* positions, int positionsSize, int* healths, int healthsSize, char* directions, int* returnSize) {
    int n = positionsSize;
    int* o = malloc(n * sizeof(int));
    int* h = malloc(n * sizeof(int));
    int* a = malloc(n * sizeof(int));
    int* s = malloc(n * sizeof(int));
    int top = 0;

    for (int i = 0; i < n; i++) o[i] = i, h[i] = healths[i], a[i] = 1;
    g_pos = positions;
    qsort(o, n, sizeof(int), cmp);
    for (int x = 0; x < n; x++) {
        int i = o[x];
        if (directions[i] == 'R') s[top++] = i;
        else {
            while (top) {
                int t = s[top - 1];
                if (h[t] == h[i]) { a[t] = a[i] = 0; top--; break; } 
                else if (h[t] > h[i]) { a[i] = 0; h[t]--; break; } 
                else { a[t] = 0; top--; h[i]--; }
            }
        }
    }
    int* res = malloc(n * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < n; i++) if (a[i]) res[(*returnSize)++] = h[i];

    free(o); free(h); free(a); free(s);
    return res;
}