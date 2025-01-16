//
// Created by Layn on 24-11-13.
//
#include<bits/stdc++.h>
using namespace std;
long long l,r,i3[51];
inline int wei(long long x) {
    if (!x) return 1;
    int s=0;
    while (x) {
        ++s;
        x/=3;
    }
    return s;
}
inline int f(long long x) {
    if (!x) return 1;
    int s=0;
    while (x) {
        s+=x%3+1;
        x/=3;
    }
    return s;
}
int main() {
    i3[0]=1;
    for (int i=1;i<51;++i) i3[i]=3ll*i3[i-1];
    int T;scanf("%d",&T);
    while (T--) {
        scanf("%lld%lld",&l,&r);
        int wl=0,wr=0;
        wl = wei(l);
        wr = wei(r);
        int res=max(f(r),f(l));
        if (wl==wr) {
            bool flag = true;
            for (int i=wr-1,s=0;i>=0;--i) {
                int p = r/i3[i]%3;
                int q = l/i3[i]%3;
                if (flag) {
                    if (p!=q) {
                        flag = false;
                    }
                }
                if (!flag) {
                    if (p>0) res = max(res, s + p + i*2 + i);
                }
                s+=p+1;
            }
        }else {
            long long o = 2;
            for (int i=1;i<wr;++i) {
                o=o*3+2;
            }
            res = max(res, (wr-1)*3);
            for (int i=wr-1,s=0;i>=0;--i) {
                int p = r/i3[i]%3;
                if (i==wr-1) {
                    if (p==2) {
                        res=max(res,2+i*2+i);
                    }
                } else {
                    if (p>=1) {
                        res = max(res, s + p + i*2 + i);
                    }
                }
                s+=p+1;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}