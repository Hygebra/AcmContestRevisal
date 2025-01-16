#pragma GCC optimize("Ofast,no−stack−protector")
#include<bits/stdc++.h>
#define mid (l+r>>1)
#define ls l,mid,p<<1
#define rs mid+1,r,p<<1|1
#define mp make_pair
#define rg register
#define il inline
using namespace std;
const int N=500010,inf=1000000000;
int n,m,a[N];
bool flag[N*4];
unsigned long long b[N];
set<pair<int,int> >lft;
struct mat {
    unsigned long long R,S,T;
}E,t[N*4],tag[N*4];
il int read() {
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
il void turn(int p,mat w) {
    t[p].T+=w.S*t[p].R+w.T*t[p].S;
    t[p].S+=w.R*t[p].R;
    tag[p].S+=w.S+w.T*tag[p].R;
    tag[p].R+=w.R;
    tag[p].T+=w.T;
    flag[p]=1;
}
il void pushdown(int p) {turn(p<<1,tag[p]),turn(p<<1|1,tag[p]),tag[p]=E,flag[p]=0;}
 void update(int l,int r,int p,int ql,int qr,unsigned long long w) {
    if(l>=ql&&r<=qr)return turn(p,(mat){w,w,1});
    if(flag[p])pushdown(p);
    if(mid>=ql)update(ls,ql,qr,w);
    if(mid<qr)update(rs,ql,qr,w);
    t[p].S=t[p<<1].S+t[p<<1|1].S,t[p].T=t[p<<1].T+t[p<<1|1].T;
}
 unsigned long long query(int l,int r,int p,int ql,int qr) {
    if(l>=ql&&r<=qr)return t[p].T;
    if(flag[p])pushdown(p);
    unsigned long long res=0;
    if(mid>=ql)res+=query(ls,ql,qr);
    if(mid<qr)res+=query(rs,ql,qr);
    return res;
}
void build(int l,int r,int p) {
    t[p].R=r-l+1;
    if(l==r)return;
    build(ls),build(rs);
}
void out(unsigned long long x) {
    if(x>9)out(x/10);
    putchar(x%10+'0');
}
int main(){
    n=read(),m=read(),build(1,n,1);
    for(rg int i=1;i<=n;i++)a[i]=read();
    for(rg int i=1;i<=n;i++)if(a[i]!=a[i-1])lft.insert(mp(i,a[i]));
    lft.insert(mp(n+1,0));
    for(rg int o,l,r,w,cs=1;cs<=m;cs++) {
        o=read(),l=read(),r=read(),w=read();
        if(o==1) {
            auto L=lft.upper_bound(mp(l,inf));--L;
            auto R=lft.upper_bound(mp(r,inf));
            int tl=L->first,tr=(R->first)-1,wl=L->second,wr;
            --R,wr=R->second,++R;
            //printf("case%d: %d %d %d %d\n",cs,tl,tr,wl,wr);
            for(auto i=L;i!=R;) {
                auto j=i;
                ++i,b[j->second]+=query(1,n,1,j->first,(i->first)-1);
                lft.erase(j);
            }b[w]-=query(1,n,1,l,r),lft.insert(mp(l,w));
            if(l>tl)b[wl]-=query(1,n,1,tl,l-1),lft.insert(mp(tl,wl));
            if(r<tr)b[wr]-=query(1,n,1,r+1,tr),lft.insert(mp(r+1,wr));
            update(1,n,1,1,n,0);
        }
        else {
            update(1,n,1,l,r,w);
            if(l>1)update(1,n,1,1,l-1,0);
            if(r<n)update(1,n,1,r+1,n,0);
        }
    }
    for(auto i=lft.begin();i!=lft.end();) {
        auto j=i;
        ++i;
        b[j->second]+=query(1,n,1,j->first,(i->first)-1);
    }
    for(rg int i=1;i<=n;i++)out(b[i]),printf(" ");
    return 0;
}