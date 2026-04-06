#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxArea(int* height, int heightSize) {
    int l = 0;
    int r = heightSize - 1;
    int maxA = 0;

    while (l < r) {
        int area = min(height[l], height[r]) * (r - l);
        maxA = max(area, maxA);

        if (height[r] < height[l]) {
            r--;
        } else {
            l++;
        }
    }

    return maxA;
}
