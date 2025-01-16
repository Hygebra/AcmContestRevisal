//
// Created by Layn on 24-10-1.
//
#include <iostream>
#include <cstdio>
#include <cstring>
    using namespace std;
    const long long INF = 1e18;
    int w[305], c[305];
    bool d[305][305];
    long long g[305][305], f[305][305], ff[305][305];
int main() {
    int T = 0;
    scanf("%d", &T);
    for (int G = 1; G <= T; G++) {
        int n = 0, m = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &c[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &w[i]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                g[i][j] = ((i == j) ? 0 : INF);
                f[i][j] = ((i == j) ? w[i] : INF);
                ff[i][j] = ((i == j) ? 0 : INF);
                d[i][j] = false;
            }
        for (int i = 1; i <= m; i++) {
            int u = 0, v = 0;
            scanf("%d%d", &u, &v);
            d[u][v] = d[v][u] = true;
            if (c[u] == c[v]) {
                g[u][v] = w[v];
                g[v][u] = w[u];
            }
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

        //cout <<w[1] + g[1][3] <<"--" << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (c[i] != c[j]) continue;
                for (int k = 1; k <= n; k++) {
                    if (!d[j][k] || c[j] == c[k]) continue;
                    f[i][k] = min(f[i][k], w[i] + g[i][j] + w[k]);
                    //printf("fffff\n");
                }
            }
        }
        /*for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                printf("%lld ", f[i][j]);
            printf("\n");
        }*/
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    f[i][j] = min(f[i][j], max(f[i][k], f[k][j]));

        //printf("%lld---\n", f[1][3]);
        //printf("%lld------\n", g[2][3]);
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= n; i++)
                for (int k = 1; k <= n; k++) {
                    if (c[j] != c[k]) continue;
                    ff[i][k] = min(ff[i][k], max(f[i][j], w[j] + g[j][k]));
                    /*if (i == 1 && k == 3) {
                        printf("%d %d\n", j, f[1][3]);
                    }*/
                }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                //f[i][j] = min(f[i][j], w[i] + g[i][j]);
                printf("%lld ", ff[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
/*
1
4 4
1 1 1 1
1 2 4 5
1 2
2 3
3 4
1 4
*/