//
// Created by Layn on 24-11-2.
//
#include <iostream>
#include <cstdio>
#include <cstring>
    using namespace std;
    const int INF = 1e9;
    int n = 0, m = 0, tu = 0, td = 0;
    int f[10][505][505], cnt[505];
    char s[15][15];
bool calc(int x, int u, int d, int sta) {
    tu = u, td = d;
    for (int i = 1; i <= m; i++) {
        if ((d >> (i - 1)) & 1) {
            if (s[x][i] == '1')
                return false;
            if (((sta >> (i - 1)) & 1) || ((u >> (i - 1)) & 1))
                td ^= (1 << (i - 1));
        }
        if ((sta >> (i - 1)) & 1) {
            if (s[x][i] == '1')
                return false;
            tu |= (1 << (i - 1));
        }
        if ((u >> (i - 1)) & 1) {
            if (s[x][i] == '1')
                tu ^= (1 << (i - 1));
        }
    }
    int p = 0;
    bool flag = false;
    for (int i = 0; i < m; i++) {
        if (s[x][i + 1] == '1') {
            flag = false; continue;
        }
        if ((sta >> i) & 1) flag = true;
        if (flag) p |= (1 << i);
        if (((u >> i) & 1) || ((d >> i) & 1))
            p |= (1 << i);
    }
    flag = false;
    for (int i = m - 1; i >= 0; i--) {
        if (s[x][i + 1] == '1') {
            flag = false; continue;
        }
        if ((sta >> i) & 1) flag  = true;
        if (flag) p |= (1 << i);
    }
    for (int i = 0; i <= m - 1; i++) {
        if ((p >> i) & 1) continue;
        if (s[x][i + 1] == '0')
            td |= (1 << i);
    }
    return true;
}
int dfs(int x, int u, int d) {
    if (x > n) {
        if (d == 0) return 0;
        return INF;
    }
    if (f[x][u][d] != -1)
        return f[x][u][d];
    f[x][u][d] = INF;
    for (int i = 0; i <= (1 << m) - 1; i++) {
        if (calc(x, u, d, i) == false)
            continue;
        int w = dfs(x + 1, tu, td);
        if (w != INF)
            f[x][u][d] = min(f[x][u][d], w + cnt[i]);
    }
    return f[x][u][d];
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    for (int i = 0; i <= (1 << m) - 1; i++)
        for (int j = 0; j < m; j++)
            if ((i >> j) & 1) cnt[i]++;
    memset(f, -1, sizeof(f));
    printf("%d\n", dfs(1, 0 , 0));
    return 0;
}