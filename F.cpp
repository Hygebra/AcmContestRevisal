//
// Created by Layn on 24-11-13.
//
#include <iostream>
#include <cstdio>
#include <cstring>
    using namespace std;
    char s[10005][15];
int main() {
    int n = 0, c1 = 0, c2 = 0;
    scanf("%d%d%d", &n, &c1, &c2);
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i][1] == s[i][2] || s[i][1] == s[i][3] || s[i][2] == s[i][3])
            ans += min(min(c1 + c2, c2 + c2), min(3 * c1, 3 * c2));
        else ans += min(3 * c1, 3 * c2);
    }
    printf("%d\n", ans);
    return 0;
}