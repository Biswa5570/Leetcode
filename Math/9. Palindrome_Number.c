bool isPalindrome(int x) {
if (x < 0) {
        return false;
    }

    int original = x;
    long long reversed_num = 0; 

    while (x > 0) {
        int digit = x % 10;
        reversed_num = reversed_num * 10 + digit;

        if (reversed_num > 2147483647) {
            return false;
        }

        x /= 10;
    }

    return original == reversed_num;
}
