//
// Created by Layn on 24-12-20.
//
#include <iostream>
#include <cstdio>
#include <cstring>
    using namespace std;
    const int N = 1000005;
    int a[N];
int main() {
    int T = 0;
    scanf("%d", &T);
    for (int G = 1; G <= T; G++) {
        int n = 0;
        scanf("%d", &n);
        int A = 0, B = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] <= 1) A++;
            if (a[i] >= 1) B++;
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] < 1) ans += B;
            else if (a[i] > 1) ans += A;
            else ans += n - 1;
        printf("%lld\n", ans / 2);
    }
    return 0;
}