bool xorGame(int* nums, int numsSize) {
    int xor_sum = 0;
    
    for (int i = 0; i < numsSize; i++) {
        xor_sum ^= nums[i];
    }

    return xor_sum == 0 || numsSize % 2 == 0;
}
