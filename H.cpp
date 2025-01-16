//
// Created by Layn on 24-11-2.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
    using namespace std;
    const int N = 300005;
struct Edg {
    int u, v, w;
}e[N];
bool cmp(Edg x, Edg y) {
    return x.w < y.w;
}
    int a[N], fa[N], f[N][20], Mx[N][20];
int GetFa(int x) {
    return (fa[x] == x) ? x : (fa[x] = GetFa(fa[x]));
}
int main() {
    int n = 0, m = 0, q = 0;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= n + n; i++)
        fa[i] = i;
    int cnt = n;
    for (int i = 1; i <= m; i++) {
        int x = GetFa(e[i].u);
        int y = GetFa(e[i].v);
        if (x == y) continue;
        cnt++;
        f[x][0] = f[y][0] = fa[x] = fa[y] = cnt;
        a[cnt] += a[x] + a[y];
        Mx[x][0] = e[i].w - a[x];
        Mx[y][0] = e[i].w - a[y];
    }
    for (int j = 1; j <= 19; j++)
        for (int i = 1; i <= cnt; i++) {
            if (f[i][j - 1] == 0) continue;
            f[i][j] = f[f[i][j - 1]][j - 1];
            Mx[i][j] = max(Mx[i][j - 1], Mx[f[i][j - 1]][j - 1]);
        }
    for (int i = 1; i <= q; i++) {
        int x = 0, k = 0;
        scanf("%d%d", &x, &k);
        for (int j = 19; j >= 0; j--) {
            if (f[x][j] == 0) continue;
            if (k < Mx[x][j]) continue;
            x = f[x][j];
        }
        printf("%d\n", a[x] + k);
    }
    return 0;
}