#define N 100003

typedef struct { long long k; } E;
E ht[N];
int used[N];

long long key(int x, int y) { return (long long)(x + 30001) * 70001 + (y + 30001); }

int hget(long long k) {
    int i = (unsigned long long)k % N;
    while (used[i] && ht[i].k != k) i = (i + 1) % N;
    return used[i] && ht[i].k == k;
}

void hset(long long k) {
    int i = (unsigned long long)k % N;
    while (used[i] && ht[i].k != k) i = (i + 1) % N;
    ht[i].k = k;
    used[i] = 1;
}

int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize) {
    memset(used, 0, sizeof(used));
    for (int i = 0; i < obstaclesSize; i++) hset(key(obstacles[i][0], obstacles[i][1]));

    int D[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int d = 0, x = 0, y = 0, r = 0;

    for (int i = 0; i < commandsSize; i++) {
        int c = commands[i];
        if (c == -1) d = (d + 1) % 4;
        else if (c == -2) d = (d + 3) % 4;
        else {
            int a = D[d][0], b = D[d][1];
            for (int s = 0; s < c; s++) {
                if (hget(key(x + a, y + b))) break;
                x += a;
                y += b;
                int v = x * x + y * y;
                if (v > r) r = v;
            }
        }
    }
    return r;
}
