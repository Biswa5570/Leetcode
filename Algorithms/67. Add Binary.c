char* addBinary(char* a, char* b) {
    int l_a = strlen(a);
    int l_b = strlen(b);
    int M = (l_a > l_b ? l_a : l_b) + 1;

    int* A = (int*)calloc(M, sizeof(int));
    int* B = (int*)calloc(M, sizeof(int));
    char* C = (char*)malloc((M + 1) * sizeof(char));

    C[M] = '\0';

    for (int i = 0; i < l_a; i++)
        A[i] = a[l_a - 1 - i] - '0';

    for (int i = 0; i < l_b; i++)
        B[i] = b[l_b - 1 - i] - '0';

    int carry = 0;

    for (int i = 0; i < M; i++) {
        int tmp = A[i] + B[i] + carry;
        char c;

        switch (tmp) {
            case 0: c = '0'; carry = 0; break;
            case 1: c = '1'; carry = 0; break;
            case 2: c = '0'; carry = 1; break;
            case 3: c = '1'; carry = 1; break;
        }

        C[M - 1 - i] = c;
    }

    free(A);
    free(B);

    if (C[0] == '0') {
        char* result = strdup(C + 1);
        free(C);
        return result;
    } else {
        return C;
    }
}
