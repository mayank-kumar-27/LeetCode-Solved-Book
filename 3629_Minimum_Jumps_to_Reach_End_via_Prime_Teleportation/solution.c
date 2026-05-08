#define MX 1000001

typedef struct {
    int* data;
    int size;
    int cap;
} Vector;

void vector_push(Vector* v, int val) {
    if (v->size == v->cap) {
        v->cap = v->cap == 0 ? 2 : v->cap * 2;
        v->data = (int*)realloc(v->data, v->cap * sizeof(int));
    }
    v->data[v->size++] = val;
}

typedef struct Node {
    int key;
    Vector values;
    struct Node* next;
} Node;

#define HASH_SIZE 10007
Node* hash_table[HASH_SIZE];

void hash_push(int key, int val) {
    int h = abs(key) % HASH_SIZE;
    Node* cur = hash_table[h];
    while (cur) {
        if (cur->key == key) {
            vector_push(&cur->values, val);
            return;
        }
        cur = cur->next;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    memset(&new_node->values, 0, sizeof(Vector));
    vector_push(&new_node->values, val);
    new_node->next = hash_table[h];
    hash_table[h] = new_node;
}

Vector* hash_get(int key) {
    int h = abs(key) % HASH_SIZE;
    Node* cur = hash_table[h];
    while (cur) {
        if (cur->key == key)
            return &cur->values;
        cur = cur->next;
    }
    return NULL;
}

Vector factors[MX];
bool precomputed = false;

void precompute() {
    if (precomputed)
        return;
    for (int i = 2; i < MX; i++) {
        if (factors[i].size == 0) {
            for (int j = i; j < MX; j += i) {
                vector_push(&factors[j], i);
            }
        }
    }
    precomputed = true;
}

void clear_hash() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* cur = hash_table[i];
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
            free(tmp->values.data);
            free(tmp);
        }
        hash_table[i] = NULL;
    }
}

int minJumps(int* nums, int numsSize) {
    precompute();
    clear_hash();
    int n = numsSize;

    for (int i = 0; i < n; i++) {
        int a = nums[i];
        if (factors[a].size == 1) {
            hash_push(a, i);
        }
    }

    bool* seen = (bool*)calloc(n, sizeof(bool));
    int* q = (int*)malloc(n * sizeof(int));
    int q_start = 0, q_end = 0;

    seen[n - 1] = true;
    q[q_end++] = n - 1;

    int res = 0;
    while (q_start < q_end) {
        int level_size = q_end - q_start;
        for (int k = 0; k < level_size; k++) {
            int i = q[q_start++];
            if (i == 0) {
                free(seen);
                free(q);
                return res;
            }

            if (i > 0 && !seen[i - 1]) {
                seen[i - 1] = true;
                q[q_end++] = i - 1;
            }
            if (i < n - 1 && !seen[i + 1]) {
                seen[i + 1] = true;
                q[q_end++] = i + 1;
            }

            for (int p_idx = 0; p_idx < factors[nums[i]].size; p_idx++) {
                int p = factors[nums[i]].data[p_idx];
                Vector* v = hash_get(p);
                if (v) {
                    for (int j_idx = 0; j_idx < v->size; j_idx++) {
                        int j = v->data[j_idx];
                        if (!seen[j]) {
                            seen[j] = true;
                            q[q_end++] = j;
                        }
                    }
                    v->size = 0;
                }
            }
        }
        res++;
    }
    return -1;
}
