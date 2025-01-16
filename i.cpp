//
// Created by Layn on 24-10-27.
//
#include <cstdio>
const int S=100005;
int n,t[30];
char a[S];
int main() {
    int T;scanf("%d",&T);
    while (T--) {
        scanf("%s",a);
        for (int i=0;i<26;++i) t[i]=0;
        n=0;
        for (int i=0;a[i];++i) {
            t[a[i]-'a']++;
            ++n;
        }
        int res=n;
        for (int i=0;i<26;++i)
            if (n-t[i]<res) res=n-t[i];
        printf("%d\n",res);
    }
    return 0;
}