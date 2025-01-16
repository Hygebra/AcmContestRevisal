//
// Created by Layn on 24-10-9.
//
#include <iostream>
#include <cstdio>
#include <cstring>
    using namespace std;
    const int N = 200005;
    const int mod = 998244353;
    int fac[N], ifac[N];
int fpow(int x, int k) {
    int res = 1;
    while (k) {
        if (k & 1) res = (long long)res * x % mod;
        x = (long long)x * x % mod; k >>= 1;
    }
    return res;
}
int C(int n, int m) {
    return (long long)fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}
int main() {
    fac[0] = 1;
    for (int i = 1; i <= N - 5; i++)
        fac[i] = (long long)fac[i - 1] * i % mod;
    for (int i = 0; i <= N - 5; i++)
        ifac[i] = fpow(fac[i], mod - 2);
    int T = 0;
    scanf("%d", &T);
    for (int G = 1; G <= T; G++) {
        int n = 0, m = 0;
        scanf("%d%d", &n, &m);
        printf("%lld\n", (long long)C(n - 1, m - 1) * fac[n] % mod);
    }
    return 0;
}