//
// Created by Layn on 24-12-4.
//
#include <iostream>
#include <cstdio>
#include <cstring>
    using namespace std;
    const int N = 1000005;
    int k = 0, n = 0, p[N];
    long long f[2][N];
int calc(int x, int o) {
    if (o == 0) return (n + 1 - p[x]) % n;
    return (n + k - p[x]) % n;
}
int dis(int x, int y) {
    if (x > y) swap(x, y);
    return min(y - x, n - y + x);
}
long long dfs(int x, int y) {
    if (y == n) return 0;
    if (f[x][y] != -1) return f[x][y];
    //printf("%d %d\n", x, y);
    f[x][y] = 0;
    int s = calc(y, x);
    int ny = y;
    y++;
    while (y <= n) {
        int t = (p[y] + s) % n;
        if (t == 0) t = n;
        if (t <= k) y++;
        else {
            //printf("%d   %d %d %d\n", s, y, dis(s, calc(y, 0)), dis(s, calc(y, 1)));
            f[x][ny] = min(dfs(0, y) + dis(s, calc(y, 0)), dfs(1, y) + dis(s, calc(y, 1)));
            break;
        }
    }
    return f[x][ny];
}
int main() {
    int T = 0;
    scanf("%d", &T);
    for (int G = 1; G <= T; G++) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            int x = 0;
            scanf("%d", &x);
            p[x] = i;
        }
        for (int i = 1; i <= n; i++)
           f[0][i] = f[1][i] = -1;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
            if (p[i] > k) {
                //cout << i << " ---\n";
                //cout << dis(0, calc(i, 0)) << " " << calc(i, 1) << endl;
                ans = min(dfs(0, i) + dis(0, calc(i, 0)), dfs(1, i) + dis(0, calc(i, 1)));
                break;
            }
        printf("%lld\n", ans);
    }
    return 0;
}