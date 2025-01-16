//
// Created by Layn on 24-10-13.
//
#include <bits/stdc++.h>
using namespace std;
//#define long long __int128
__int128 ksm128(__int128 a,__int128 x) {
    __int128 s=1;
    while (x) {
        if (x&1) s=s*a;
        a=a*a;
        x>>=1;
    }
    return s;
}
inline long long gcd(long long a,long long b) {
    if (!b) return a;
    return gcd(b,a%b);
}
inline long long ksm(long long a,long long x,long long mod) {
    long long s=1;
    while (x) {
        if (x&1) s=(__int128)s*a%mod;
        a=(__int128)a*a%mod;
        x>>=1;
    }
    return s;
}
inline long long ksm(long long a,long long x) {
    long long s=1;
    while (x) {
        if (x&1) s=s*a;
        a=a*a;
        x>>=1;
    }
    return s;
}
inline bool miller_rabin(long long x,long long b) {
    long long k=x-1;
    while (k) {
        long long cur = ksm(b,k,x);
        if (cur!=1 && cur!=x-1) return false;
        if ((k&1) == 1 || cur==x-1) return true;
        k>>=1;
    }
    return true;
}
inline bool prime(long long x) {
    if (x<2) return false;
    if (x==46856248255981ll) return false;
    if (x==2 || x==3 || x==7 || x==61 || x==24251) return true;
    return miller_rabin(x,2) && miller_rabin(x,61);
}
long long rho(long long n) {
    long long x,y,p=1,c=rand()%(n-1)+1;
    x=y=rand()%(n-1)+1;
    for (int i=1,k=1;;++i) {
        x=(__int128(x)*x%n+c)%n;
        p=__int128(p)*((x-y+n)%n)%n;
        if (x==y || !p) return n;
        if ((i>>7)==i || i==k) {
            p = gcd(p,n);
            if (1<p) return p;
            if (i==k) k<<=1,y=x;
        }
    }
    p = gcd(p,n);
    if (1<p && p<n) return p;
    return n;
}
long long n;
int k,res;
int top=0,tot;
long long st[1003];
int s[1003];
void pollard_rho(long long x) {
    if (x==1 || prime(x)) {
        //printf("%d\n",x);
        if (x>1) st[++top] = x;
        return;
    }
    long long u;
    while (u=rho(x),!(u>1 && u<x));
    while (x%u==0) x/=u;
    pollard_rho(u);
    pollard_rho(x);
}
void dfs(int step,long long su) {
    if (step>tot) {
        long long ret = n/su;
        if (su>sqrt(ret)+5 || su*su>=ret) {
            return;
        }
        ret = ret - su*su;
        if (ret%3) return;
        ret/=3;//ret = ab, su = a-b
        /*
         * b^2 + su*b - ret = 0;
         * delta = su^2 + 4 * ret
         */
        long long delta = su*su+4*ret,b,a;
        delta = sqrt(delta);
        bool flag = false;
        for (long long d = delta-2;d<=delta+2;++d) {
            if (d*d==su*su+4*ret) {
                flag = true;
                delta = d;
            }
        }
        if (!flag) return;
        if ((-su + delta)%2) b=-1;
        else b = (-su+delta)/2;
        a = su + b;
        if (a*a+a*b+b*b==n/su) {
            //printf("%lld %lld\n",a,b);
            ++res;
        }
        return;
    }
    for (int i=0;i<=s[step];++i) {
        dfs(step+1,su);
        su*=st[step];
    }
}
__int128 buf[1000003];
int tt;
long long lim[100];
map<__int128,bool> mp[70];
bool bf(__int128 x) {
    int l=1,r=tt,mid;
    while (l<=r) {
        mid=(l+r)>>1;
        if (buf[mid]==x) return true;
        if (buf[mid]>x) r=mid-1;
        else l=mid+1;
    }
    return false;
}
void solve() {
    if (k>3) {
        for (__int128 o = lim[k],ok,oo;o>=1;--o) {
            //printf("%lld\n",o);
            if (k==4) {
                ok = o*o*o*o;
                if (ok<=n) continue;
                if (bf(ok-n)) {
                    ++res;
                }
            } else {
                ok = ksm128(o,k);
                if (ok <= n) continue;
                if (mp[k][ok-n]) {
                    ++res;
                }
            }
        }
    } else {
        top=0;
        pollard_rho(n);
        sort(st+1,st+1+top);
        tot=0;
        long long nn = n;
        for (int i=1;i<=top;++i) {
            if (st[i]!=st[tot]) {
                ++tot;
                st[tot]=st[i];
                s[tot]=0;
                while (nn%st[i]==0)
                    ++s[tot],nn/=st[i];
            }
        }
        //for (int i=1;i<=tot;++i)
        //    printf("%lld %d\n",st[i],s[i]);
        dfs(1,1);
    }
}
int main() {
    //freopen("a.txt","r",stdin);
    srand(233);
    for (int i=4;i<=64;++i) {
        __int128 s=1,p,la=0;
        while ((p=ksm128(s,i)) - la <= 1.000001e18) {
            if (i>4) mp[i][p]=true;
            else buf[++tt] = p;
            //printf("%d\n",i);
            la=p;++s;
        }
        //printf("%d\n",i);
        lim[i] = s;
    }
    //printf("%lld\n",lim[5]);
    int T;scanf("%d",&T);//puts("c");
    long long nin;
    while (T--) {
        scanf("%lld%d",&n,&k);
        //puts("c");
        res=0;solve();
        printf("%lld\n",res);
    }
    return 0;
}