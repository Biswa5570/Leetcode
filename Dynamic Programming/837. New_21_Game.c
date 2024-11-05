double new21Game(int n, int k, int maxPts) {
 if (k == 0 || n >= k + maxPts) {
        return 1.0;
    }

    double* dp = (double*)malloc((n + 1) * sizeof(double));
    for (int i = 0; i <= n; i++) {
        dp[i] = 0.0;
    }

    dp[0] = 1.0;
    double currSum = dp[0];

    for (int i = 1; i <= n; i++) {
        dp[i] = currSum / (double)maxPts;

        if (i < k) {
            currSum += dp[i];
        }
        if (i - maxPts >= 0) {
            currSum -= dp[i - maxPts];
        }
    }

    double ans = 0.0;
    for (int i = k; i <= n; i++) {
        ans += dp[i];
    }

    free(dp);

    return ans;   
}
