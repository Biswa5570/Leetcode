int* distributeCandies(int candies, int num_people, int* returnSize) {
    int* res = (int*)calloc(num_people, sizeof(int));
    *returnSize = num_people;

    int give = 1, i = 0;

    while (candies > 0) {
        int idx = i % num_people;

        int toGive = (give < candies) ? give : candies;

        res[idx] += toGive;
        candies -= toGive;

        give++;
        i++;
    }

    return res;
}
