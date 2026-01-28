/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int key, val;
    UT_hash_handle hh;
} Hash;

int* twoSum(int* nums, int n, int target, int* returnSize) {
    Hash *map = NULL, *e;
    int* res = malloc(2 * sizeof(int));

    for (int i = 0; i < n; i++) {
        int find = target - nums[i];
        HASH_FIND_INT(map, &find, e);
        if (e) {
            res[0] = e->val;
            res[1] = i;
            *returnSize = 2;
            return res;
        }
        e = malloc(sizeof(Hash));
        e->key = nums[i];
        e->val = i;
        HASH_ADD_INT(map, key, e);
    }

    *returnSize = 0;
    return NULL;
}