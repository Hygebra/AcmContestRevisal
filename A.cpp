//
// Created by Layn on 24-10-27.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
    using namespace std;
    const int N = 2505;
    int c[N][N];
    char s[N * N];
int main() {
    int T = 0;
    scanf("%d", &T);
    for (int G = 1; G <= T; G++) {
        int n = 0, m = 0, k = 0;
        scanf("%d%d%d", &n, &m, &k);
        scanf("%s", s + 1);
        int px = 0, py = 0;
        int MxU = 0, MnD = n;
        int MxL = 0, MnR = m;
        int len = strlen(s + 1);
        for (int i = 1; i <= len; i++) {
            if (s[i] == 'U') px++;
            else if (s[i] == 'D') px--;
            else if (s[i] == 'L') py++;
            else py--;
            MxU = max(MxU, px), MnD = min(MnD, n + px);
            MxL = max(MxL, py), MnR = min(MnR, m + py);
        }
        //printf("%d %d %d %d\n", MxU, MnD, MxL, MnR);
        if (MxU >= n || MnD <= 0 || MxL >= m || MnR <= 0 || MxU >= MnD || MxL >= MnR) {
            if (k == 0) printf("%d\n", n * m);
            else printf("0\n");
            continue;
        }
        px = 0, py = 0;
        for (int i = 0; i <= n + n; i++)
            for (int j = 0; j <= m + m; j++)
                c[i][j] = 0;
        c[n + px][m + py] = 1;
        for (int i = 1; i <= len; i++) {
            if (s[i] == 'U') px++;
            else if (s[i] == 'D') px--;
            else if (s[i] == 'L') py++;
            else py--;
            c[n + px][m + py] = 1;
        }
        /*for (int i = 1; i <= n + n; i++) {
           for (int j = 1; j <= m + m; j++) printf("%d", c[i][j]);
            printf("\n");
        }*/
        for (int i = 1; i <= n + n; i++)
            for (int j = 1; j <= m + m; j++)
                c[i][j] += c[i][j - 1] + c[i - 1][j] - c[i - 1][j - 1];
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                int l = m + (MxL - (j - 1));
                int r = m + (MnR - (j - 1) - 1);
                int u = n + (MxU - (i - 1));
                int d = n + (MnD - (i - 1) - 1);
                int res = 0;
                //if (i == 3 && j == 4) printf("%d %d %d %d\n", l, r, u, d);
                if (l > m + m || u > n + n) res = 0;
                else {
                    r = min(r, m + m), d = min(d, n + n);
                    res = c[d][r] - c[d][l - 1] - c[u - 1][r] + c[u - 1][l - 1];
                   //if (i == 4 && j == 3) printf("%d---\n", res);
                }
                if ((MnR - MxL) * (MnD - MxU) - res == k)
                    ans++;//, printf("%d %d %d  %d ---\n", i, j, (MnR - MxL) * (MnD - MxU), k);
            }
        //printf("%d\n", (MnR - MxL) * (MnD - MxU));
        printf("%d\n", ans);
    }
    return 0;
}