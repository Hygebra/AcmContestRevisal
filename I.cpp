//
// Created by Layn on 24-10-16.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
    using namespace std;
    const int N = 100005;
    pair<int, int> s[N];
int main() {
    int T = 0;
    scanf("%d", &T);
    for (int G = 1;  G <= T; G++) {
        int n = 0, m = 0;
        scanf("%d%d", &n, &m);
        s[0] = make_pair(0, 0);
        for (int i = 1; i <= m; i++)
            scanf("%d%d", &s[i].first, &s[i].second);
        sort(s + 1, s + m + 1);
        bool flag = true;
        for (int i = 1; i <= m; i++) {
            if (s[i].first == s[i - 1].first && s[i].second != s[i - 1].second) {
                flag = false;
                break;
            }
            if (s[i].second >= s[i - 1].second && s[i].second - s[i - 1].second == s[i].first - s[i - 1].first)
                continue;
            if (s[i].first - s[i - 1].first - 1 < s[i].second) {
                flag = false;
                break;
            }
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}