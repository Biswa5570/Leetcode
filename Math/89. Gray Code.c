int* grayCode(int n, int* returnSize) {
    int total_numbers = 1 << n;
    *returnSize = total_numbers;

    int* result = (int*)malloc(total_numbers * sizeof(int));

    for (int i = 0; i < total_numbers; i++) {
        result[i] = i ^ (i >> 1);
    }

    return result;
}
