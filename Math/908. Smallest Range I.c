int smallestRangeI(int* nums, int numsSize, int k) {
    int mx = nums[0];
    int mn = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > mx) mx = nums[i];
        if (nums[i] < mn) mn = nums[i];
    }

    int diff = (mx - k) - (mn + k);

    if (diff > 0)
        return diff;
    return 0;
}
