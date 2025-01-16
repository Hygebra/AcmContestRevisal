#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
	using namespace std;
struct dt{
	int y, x1, x2;
}s[100005];
bool cmp(dt a, dt b) {
	if (a.y != b.y) return a.y < b.y;
	return a.x1 < b.x1;
}
	int y[100005];
	vector<pair<int, int> > d[100005];
int main() {
	int n = 0, m = 0, k = 0;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d", &s[i].x1, &s[i].x2, &s[i].y);
	}
	if (n == 1 || m == 1) {
		printf("YES\n");
		return 0;
	}
	sort(s + 1, s + k + 1, cmp);
	int tot = 0, lst = n;
	if (s[1].y > 1) {
		tot++; y[tot] = 1;
		d[tot].push_back(make_pair(1, n));
		lst = n;
	}
	for (int i = 1; i <= k; i++) {
		if (i == 1 || s[i].y != s[i - 1].y) {
			if (lst < n)
				d[tot].push_back(make_pair(lst + 1, n));
			tot++; y[tot] = s[i].y; lst = 0;
		}
		if (lst < s[i].x1 - 1)
			d[tot].push_back(make_pair(lst + 1, s[i].x1 - 1));
		lst = s[i].x2;
	}
	if (lst < n) 
		d[tot].push_back(make_pair(lst + 1, n));
	if (y[tot] < m) {
		tot++; y[tot] = m;
		d[tot].push_back(make_pair(1, n));
	}
	bool flag = false;
	long long nd = 0, eg = 0;
	for (int i = 1; i <= tot; i++) {
		if (i < tot && y[i + 1] - y[i] - 1 >= 2) {
			flag = true; break;
		}
		if (y[i - 1] + 1 < y[i]) {
			int siz = d[i].size();
			for (int j = 0; j < siz; j++)
				eg += (d[i][j].second - d[i][j].first + 1);
		}
		if (i < tot && y[i] + 1 < y[i + 1]) {
			int siz = d[i].size();
			for (int j = 0; j < siz; j++)
				eg += (d[i][j].second - d[i][j].first + 1);
			continue;
		}
		if (i == tot) break;
		int siz1 = d[i].size(), siz2 = d[i + 1].size();
		int p = 0;
		for (int j = 0; j < siz1; j++) {
			while (p < siz2 && d[i + 1][p].second < d[i][j].first)
				p++;
			while (p < siz2 && d[i + 1][p].first <= d[i][j].second) {
				int w = min(d[i][j].second, d[i + 1][p].second) - max(d[i][j].first, d[i + 1][p].first) + 1;
				eg += w; p++;
			}
			if (p > 0) p--;
		}
	}
	if (flag) {
		printf("NO\n");
		return 0;
	}
	for (int i = 1; i <= tot; i++) {
		int siz = d[i].size();
		for (int j = 0; j < siz; j++) {
			nd += (d[i][j].second - d[i][j].first + 1);
			eg += (d[i][j].second - d[i][j].first);
		}
		if (i < tot) {
			nd += (long long)(y[i + 1] - y[i] - 1) * n;
			eg += (long long)(y[i + 1] - y[i] - 1) * (n - 1);
		}
	}
	if (eg + 1 == nd) printf("YES\n");
	else printf("NO\n");
	return 0;
}