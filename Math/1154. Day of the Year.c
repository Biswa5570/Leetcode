int dayOfYear(char* date) {
    int year = 0, month = 0, day = 0;

    sscanf(date, "%d-%d-%d", &year, &month, &day);

    int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    int total = 0;

    for (int i = 0; i < month - 1; i++) {
        total += daysInMonth[i];
    }

    total += day;

    return total;
}
