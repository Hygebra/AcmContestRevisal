//
// Created by Layn on 24-9-29.
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
        bool f1 = false, f2 = false;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] >= 0) f1 = true;
            else f2 = true;
        }
        if (n == 1) {
            printf("%d\n", a[1]);
            continue;
        }
        long long res = 0;
        if (f1 && f2) {
            for (int i = 1; i <= n; i++)
                if (a[i] >= 0) res += a[i];
                else res -= a[i];
        } else if (f1 && !f2) {
            int Mn = 2e9;
            for (int i = 1 ; i <= n; i++) {
                res += a[i];
                Mn = min(Mn, a[i]);
            }
            res -= Mn + Mn;
        } else {
            int Mx = -2e9;
            for (int i = 1; i <= n; i++) {
                res -= a[i];
                Mx = max(Mx, a[i]);
            }
            res += Mx + Mx;
        }
        printf("%lld\n", res);
    }
    return 0;
}