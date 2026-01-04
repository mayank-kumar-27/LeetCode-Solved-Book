int sum(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum;
}

int get_divisors(int n) {
    int* divisors = (int*)malloc(4 * sizeof(int));
    if (divisors == NULL) return 0;
    
    int index = 0;

    int i = 1;
    while (i * i <= n) {
        if (n % i == 0) {
            if (index >= 4) {
                free(divisors);
                return 0;
            }
            divisors[index++] = i;
            
            if (i * i != n) {
                if (index >= 4) {
                    free(divisors);
                    return 0;
                }
                divisors[index++] = n / i;
            }
        }
        i += 1;
    }
    
    int result = (index == 4) ? sum(divisors, index) : 0;
    free(divisors);
    return result;
}

int sumFourDivisors(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) result += get_divisors(nums[i]);
    return result;
}
