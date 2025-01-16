//
// Created by Layn on 24-10-9.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
    using namespace std;
    const int mod = 1000000007;
    long long n = 0, m = 0, k = 0;
    map<pair<int, pair<long long, int> >, int> vis;
    map<pair<int, pair<long long, int> >, int> f;
    int C[205][205];
int dfs(int x, long long w, int y) {
    if (w < 0) return 0;
    if (w - k / 2 * (k - k / 2) * ((1ll << (x + 1)) - 1) > 0)
        return 0;
    if (x < 0) return 1;
    pair<int, pair<long long, int> > st = make_pair(x, make_pair(w, y));
    if (vis[st]) return f[st];
    vis[st] = true;
    int res = 0;
    long long val = (1ll << x);
    for (int i = 0; i <= k; i++) {
        // i: 0 , k - i: 1
        long long d = i * (k - i) * val;
        if (w - d < 0) continue;
        if ((m >> x) & 1) {
            for (int j = 0; j <= min((long long)y, k - i); j++)
                res = (res + (long long)dfs(x - 1, w - d, j) * C[y][j] % mod * C[k - y][k - i - j] % mod) % mod;
        } else {
            if (k - i > k - y) continue;
            res = (res + (long long)dfs(x - 1, w - d, y) * C[k - y][k - i]) % mod;
        }
    }
        //return vis[make_pair(x, w)] = true;
    f[st] = res;
    return res;
}
int main() {
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 0; i <= k; i++) C[i][0] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    int t = 0;
    for (t = 0; (1ll << t) <= m; t++);
    t--;
    printf("%d\n", dfs(t, n, k));
    return 0;
}
// 10000000000000 1000000000000 18