//
// Created by Layn on 24-11-2.
//
#include <iostream>
#include <cstdio>
#include <cstring>
    using namespace std;
    const int N = 2601;
    const long long INF = 1e16;
    int n = 0, k = 0, v[105], t[105];
    bool vis[101][101][N + N + 5];
    long long f[101][101][N + N + 5];
long long dfs(int x, int y, int z) {
    if (x > n) {
        if (z == N) return 0;
        return -INF;
    }
    if (vis[x][y][z]) return f[x][y][z];
    vis[x][y][z] = true;
    long long w1 = -INF, w2 = -INF;
    if (y < k) {
        long long a = dfs(x + 1, y + 1, z - 2 * t[x]);
        long long b = dfs(x + 1, y + 1, z + 2 * t[x]);
        if (a != -INF) w1 = max(w1, a + v[x]);
        if (b != -INF) w1 = max(w1, b + v[x]);
    }
    long long a = dfs(x + 1, y, z - t[x]);
    long long b = dfs(x + 1, y, z + t[x]);
    if (a != -INF) w2 = max(w2, a + v[x]);
    if (b != -INF) w2 = max(w2, b + v[x]);
    f[x][y][z] = max(max(w1, w2), dfs(x + 1, y, z));
    return f[x][y][z];
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &v[i], &t[i]);
    printf("%lld\n", max(0ll, dfs(1, 0, N)));
    return 0;
}