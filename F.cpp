//
// Created by Layn on 24-12-4.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
    using namespace std;
    const int N = 500005;
    int res[N];
    priority_queue<pair<long long, int> > q;
int main() {
    int n = 0;
    long long sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x = 0;
        scanf("%d", &x);
        sum += x;
        q.push(make_pair(x, i));
    }
    if (sum > (long long)n * (n - 2)) {
        printf("Recurrent");
        return 0;
    }
    long long w = 0;
    for (int i = 1; i <= n; i++) {
        long long s = q.top().first + w;
        int num = q.top().second;
        if (s < n - 1) break;
        w += s / (n - 1);
        q.pop();
        q.push(make_pair(s % (n - 1) - w, num));
    }
    if (q.top().first + w >= n - 1) {
        printf("Recurrent");
        return 0;
    }
    while (!q.empty()) {
        res[q.top().second] = q.top().first + w;
        q.pop();
    }
    for (int i = 1; i <= n; i++) {
        printf("%d", res[i]);
        if (i < n) printf(" ");
    }
    return 0;
}