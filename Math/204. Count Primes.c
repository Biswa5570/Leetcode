int countPrimes(int n) {
    if (n <= 2) return 0;

    bool* isPrime = (bool*)malloc((n + 1) * sizeof(bool));

    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }

    int count = 0;

    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
            for (int j = i * 2; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    free(isPrime);
    return count;
}
