//
// Created by Layn on 24-10-27.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
    using namespace std;
    const int N = 500005;
    int a[N];
    long long pre[N], suf[N], Mn[N];
    char s[N];
    priority_queue<pair<long long, int> > q;
int main() {
    int T = 0;
    scanf("%d", &T);
    for (int G = 1; G <= T; G++) {
        int n = 0, k = 0;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        scanf("%s", s + 1);
        a[0] = a[n + 1] = 0;
        pre[0] = suf[n + 1] = 0;
        s[0] = s[n + 1] = '0';
        long long ans = 0;
        for (int i = 1; i <= n; i++)
            if (s[i] == '1') ans += a[i];
        while (!q.empty()) q.pop();
        q.push(make_pair(0, 0));
        for (int i = 1; i <= n + 1; i++) {
            while (i - q.top().second > k) q.pop();
            long long w = -q.top().first;
            pre[i] = w + ((s[i] == '1') ? 0 : a[i]);
            q.push(make_pair(-pre[i], i));
        }
        while (!q.empty()) q.pop();
        q.push(make_pair(0, n + 1));
        for (int i = n; i >= 0; i--) {
            while (q.top().second - i > k) q.pop();
            long long w = -q.top().first;
            suf[i] = w + ((s[i] == '1') ? 0 : a[i]);
            q.push(make_pair(-suf[i], i));
        }
        int q0 = 0;
        scanf("%d", &q0);
        for (int i = 1; i <= q0; i++) {
            int p = 0, v = 0;
            scanf("%d%d", &p, &v);

            Mn[p] = 1e18;
            for (int j = p - 1; j >= max(0, p - k); j--)
                Mn[j] = min(Mn[j + 1], pre[j]);
            for (int j = p + 1; j <= min(n + 1, p + k); j++)
                Mn[j] = min(Mn[j - 1], suf[j]);

            long long w1 = 1e18, w2 = 1e18;

            w1 = Mn[max(0, p - k)] + Mn[min(n + 1, p + k)];

            if (s[p] == '0') {
                for (int j = p - 1; j >= max(0, p - k + 1); j--)
                    w2 = min(w2, Mn[j] + Mn[j + k]);
            }
            if (s[p] == '1') w1 = w1 - a[p] + v;
            else w1 = w1 + v;
            printf("%lld\n", ans + min(w1, w2));
        }
    }
    return 0;
}