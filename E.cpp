//
// Created by Layn on 24-10-1.
//
#include <iostream>
#include <cstdio>
#include <cstring>
    using namespace std;
    int a[1000005];
int main() {
    int n = 0, k = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = n + 1; ; i++) {
        if (a[i - 1] >= a[i - 2]) {
            puts("Python will never be faster than C++");
            break;
        }
        a[i] = max(0, 2 * a[i - 1] - a[i - 2]);
        if (a[i] < k) {
            printf("Python 3.%d will be faster than C++\n", i);
            break;
        }
    }
    return 0;
}