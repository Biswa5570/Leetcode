bool isHappy(int n) {
    int seen[1000] = {0};

    while (n != 1) {
        int sum = 0;
        int temp = n;

        while (temp != 0) {
            int digit = temp % 10;
            sum += digit * digit;
            temp /= 10;
        }

        n = sum;

        if (seen[n]) return false;
        seen[n] = 1;
    }

    return true;
}
