char* convertToTitle(int columnNumber) {
    char *result = (char*)malloc(20 * sizeof(char));
    int index = 0;
    
    while (columnNumber > 0) {
        columnNumber--; 
        result[index++] = 'A' + (columnNumber % 26);
        columnNumber /= 26;
    }

    for (int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }

    result[index] = '\0'; 
    return result;
}
