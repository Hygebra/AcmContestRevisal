//
// Created by Layn on 24-10-13.
//
#include <cstdio>
const int N=303,S=60006;
const int M1 = 131, M2 = 149, mod1 = 19260817, mod2 = 998244353;
int n,q,m,k,m1[S],m2[S];
char a[N][S],b[S];
int h1[N][S];
int h2[N][S];
int h3[S];
int h4[S];
int hash(int h[],int l,int r,int m[],int mod) {
    return (h[r] - h[l-1]*1ll*m[r-l+1]%mod + mod) % mod;
}
bool eq(int h1[],int h2[],int l,int r) {
    return hash(h1,l,r,m1,mod1) == hash(h3,l,r,m1,mod1) &&
        hash(h2,l,r,m2,mod2) == hash(h4,l,r,m2,mod2);
}
int main() {
    scanf("%d%d%d%d",&n,&q,&m,&k);
    m1[0]=m2[0]=1;
    for (int i=1;i<=m;++i) {
        m1[i]=1ll*m1[i-1]*M1%mod1;
        m2[i]=1ll*m2[i-1]*M2%mod2;
    }
    for (int i=1;i<=n;++i) {
        scanf("%s",a[i]+1);
        for (int j=1;j<=m;++j) {
            h1[i][j] = (h1[i][j-1]*1ll*M1 + a[i][j])%mod1;
            h2[i][j] = (h2[i][j-1]*1ll*M2 + a[i][j])%mod2;
        }
    }
    while (q--) {
        scanf("%s",b+1);
        for (int j=1;j<=m;++j) {
            h3[j] = (h3[j-1]*1ll*M1 + b[j])%mod1;
            h4[j] = (h4[j-1]*1ll*M2 + b[j])%mod2;
        }
        int res=0;
        for (int i=1;i<=n;++i) {
            int la = 0;
            int s=0;
            while (s<=k && la<m) {
                int l=la,r=m,mid;
                while (l<r) {
                    mid=(l+r+1)>>1;
                    if (eq(h1[i],h2[i],la+1,mid)) {
                        l=mid;
                    } else r=mid-1;
                }
                la = l+1;
                if (la<=m)
                    ++s;
                //printf("%d %d\n",i,la);
            }
            //printf("%d : s=%d\n",i,s);
            if (s<=k) {
                ++res;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}