//
// Created by Layn on 24-12-20.
//
#include <bits/stdc++.h>
using namespace std;
const int S=100005;
int n;
char a[S];
vector<int> ve[S];
int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%s",&n,a+1);
        int res=0;
        for (int i=1;i<=n;++i) {
            int o = i + (i&-i);
            if (o<=n) ve[o].push_back(i);
        }
        for (int i=1;i<=n;++i) {
            int s=0;
            for (int j:ve[i])
                if (a[j]=='1') ++s;
            if (s==0) {
                if (a[i]=='1') {
                    ++res;
                }
            } else if (s==1) {
                if (a[i]=='0') ++res;
            }
        }
        printf("%d\n",res);
        for (int i=1;i<=n;++i)
            ve[i].clear();
    }
    return 0;
}