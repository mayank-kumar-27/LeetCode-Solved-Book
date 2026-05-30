/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int* seg;
    int size;
} SegmentTree;

void initSegTree(SegmentTree* st, int size) {
    st->size = size;
    st->seg = (int*)g_malloc0(sizeof(int) * (size << 2));
}

void freeSegTree(SegmentTree* st) { g_free(st->seg); }

void update(SegmentTree* st, int idx, int val, int p, int l, int r) {
    if (l == r) { st->seg[p] = val; return; }
    int mid = (l + r) >> 1;
    if (idx <= mid) update(st, idx, val, p << 1, l, mid);
    else update(st, idx, val, p << 1 | 1, mid + 1, r); 
    st->seg[p] = fmax(st->seg[p << 1], st->seg[p << 1 | 1]);
}

int query(SegmentTree* st, int L, int R, int p, int l, int r) {
    if (L <= l && r <= R) return st->seg[p];
    int mid = (l + r) >> 1;
    int res = 0;
    if (L <= mid) res = fmax(res, query(st, L, R, p << 1, l, mid)); 
    if (R > mid) res = fmax(res, query(st, L, R, p << 1 | 1, mid + 1, r));
    return res;
}

gint compare_ints(gconstpointer a, gconstpointer b) {
    int ia = GPOINTER_TO_INT(a), ib = GPOINTER_TO_INT(b);
    return ia - ib;
}

static GTreeNode* tree_floor(GTree* tree, int key) {
    GTreeNode* node = g_tree_lower_bound(tree, GINT_TO_POINTER(key));
    if (!node) return g_tree_node_last(tree);
    int k = GPOINTER_TO_INT(g_tree_node_key(node));
    return k > key ? g_tree_node_previous(node) : node;
}

static GTreeNode* tree_ceil(GTree* tree, int key) {
    GTreeNode* node = g_tree_upper_bound(tree, GINT_TO_POINTER(key));
    if (!node) return NULL;
    int k = GPOINTER_TO_INT(g_tree_node_key(node));
    return k > key ? node : g_tree_node_next(node);
}

bool* getResults(int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    const int mx = 50000;
    SegmentTree st;

    initSegTree(&st, mx);
    GTree* tree = g_tree_new((GCompareFunc)compare_ints);
    g_tree_insert(tree, GINT_TO_POINTER(0), NULL);
    g_tree_insert(tree, GINT_TO_POINTER(mx), NULL);
    update(&st, mx, mx, 1, 0, mx);

    *returnSize = 0;
    bool* ans = (bool*)g_malloc(sizeof(bool) * queriesSize);
    for (int i = 0; i < queriesSize; i++) {
        int* q = queries[i];
        if (q[0] == 1) {
            int x = q[1];
            GTreeNode* ceil_node = tree_ceil(tree, x);
            GTreeNode* floor_node = tree_floor(tree, x);
            int r = ceil_node ? GPOINTER_TO_INT(g_tree_node_key(ceil_node)) : mx;
            int l = floor_node ? GPOINTER_TO_INT(g_tree_node_key(floor_node)) : 0;
            update(&st, x, x - l, 1, 0, mx);
            update(&st, r, r - x, 1, 0, mx);
            g_tree_insert(tree, GINT_TO_POINTER(x), NULL);
        } else {
            int x = q[1], sz = q[2];
            GTreeNode* floor_node = tree_floor(tree, x);
            int pre = floor_node ? GPOINTER_TO_INT(g_tree_node_key(floor_node)) : 0;
            int maxSpace = query(&st, 0, pre, 1, 0, mx);
            maxSpace = fmax(maxSpace, x - pre);
            ans[(*returnSize)++] = (maxSpace >= sz);
        }
    }
    freeSegTree(&st);
    g_tree_destroy(tree);
    return ans;
}
