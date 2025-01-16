//
// Created by Layn on 24-9-29.
//
#include <iostream>
#include <cstdio>
#include <cstring>
    using namespace std;
    const int N = 100005;
    int n = 0;
    int a[N], val[N], s[N];
    bool vis[N];
int lowbit(int x) {
    return x & (-x);
}
void Add(int x, int w) {
    for (; x <= n; x += lowbit(x))
        val[x] += w;
}
int Ask(int x) {
    int res = 0;
    for (; x; x -= lowbit(x))
        res += val[x];
    return res;
}
int main() {
    int T = 0;
    scanf("%d", &T);
    for (int G = 1; G <= T; G++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            val[i] = 0; s[i] = -1;
            vis[i] = false;
        }
        int cnt = 0;
        long long res = 0;

        Add(a[1], 1), vis[a[1]] = true, cnt++;
        printf("0");
        if (n > 1) putchar(' ');

        for (int i = 2; i <= n; i++) {
            if (a[i] == a[1]) {
                if (s[a[i]] == -1)
                    s[a[i]] = i - 2;
            }
            else if (a[i] > a[1]) {
                if (s[a[1]] == -1)
                    res += 2;
                else res += 1 - s[a[1]] + i - 1;
                if (!vis[a[i]])
                    Add(a[i], 1), vis[a[i]] = true, cnt++;
                swap(a[i], a[1]);

            } else {
                res += cnt - Ask(a[i]);
                if (!vis[a[i]])
                    Add(a[i], 1), vis[a[i]] = true, cnt++;
            }
            printf("%lld", res);
            if (i < n) putchar(' ');
        }
        if (G < T) putchar('\n');
    }
    return 0;
}
/*
1
5
2 3 2 1 5
*/