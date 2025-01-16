#include<bits/stdc++.h>
#define ls l,mid,p<<1
#define rs mid+1,r,p<<1|1
#define rg register
using namespace std;
const int N=5e4+5,mod=1e9+7;
int n,m,q,a[N],L[N],R[N],X[N],ans[N];
bool fl[N*4];
struct qry{int l,r,id,flag;};
struct mat{int m[4][4];}tag[N*4],t[N*4],E,K;
vector<qry>qu[N];
inline int add(int x,int y) {
    int z=x+y;
    if(z<mod)return z;
    return z-mod;
}
inline int mul(int x,int y){return 1ll*x*y%mod;}
inline mat m_mul(mat x,mat y) {
    mat z;
    memset(z.m,0,sizeof(z.m));
    for(rg int i=0;i<4;i++)for(rg int j=i;j<4;j++)for(rg int k=i;k<=j;k++)
        z.m[i][j]=add(z.m[i][j],mul(x.m[i][k],y.m[k][j]));
    return z;
}
inline mat get_m(int k) {
    mat x=E;
    x.m[0][1]=k;
    x.m[0][2]=mul(k,k),x.m[1][2]=add(k,k);
    x.m[0][3]=mul(k,k),x.m[1][3]=add(k,k),x.m[2][3]=1;
    return x;
}
inline void pushup(int p) {
    int lt=p<<1,rt=p<<1|1;
    for(int i=0;i<4;i++)t[p].m[0][i]=add(t[lt].m[0][i],t[rt].m[0][i]);
}
void build(int l,int r,int p) {
    tag[p]=E;
    if(l==r) {
        t[p].m[0][0]=1,t[p].m[0][1]=a[l];
        t[p].m[0][2]=t[p].m[0][3]=mul(a[l],a[l]);
        return;
    }int mid=l+r>>1;
    build(ls),build(rs),pushup(p);
}
inline void pushdown(int p) {
    int lt=p<<1,rt=p<<1|1;
    t[lt]=m_mul(t[lt],tag[p]),tag[lt]=m_mul(tag[lt],tag[p]),fl[lt]=1;
    t[rt]=m_mul(t[rt],tag[p]),tag[rt]=m_mul(tag[rt],tag[p]),fl[rt]=1;
    tag[p]=E,fl[p]=0;
}
inline void update(int l,int r,int p,int ql,int qr) {
    if(l>=ql&&r<=qr)return (void)(t[p]=m_mul(t[p],K),tag[p]=m_mul(tag[p],K),fl[p]=1);
    if(fl[p])pushdown(p);
    int mid=l+r>>1;
    if(mid>=ql)update(ls,ql,qr);
    if(mid<qr)update(rs,ql,qr);
    pushup(p);
}
inline int query(int l,int r,int p,int ql,int qr) {
    if(l>=ql&&r<=qr)return t[p].m[0][3];
    if(fl[p])pushdown(p);
    int mid=l+r>>1;
    if(mid<ql)return query(rs,ql,qr);
    if(mid>=qr)return query(ls,ql,qr);
    return add(query(ls,ql,qr),query(rs,ql,qr));
}
void init() {
    for(int i=0;i<4;i++)E.m[i][i]=1;
}
int main() {
    scanf("%d%d%d",&n,&m,&q),init();
    for(rg int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=add(a[i],mod);
    for(rg int i=1;i<=m;i++)scanf("%d%d%d",&L[i],&R[i],&X[i]),X[i]=add(X[i],mod);
    for(rg int x,y,l,r,i=1;i<=q;i++) {
        scanf("%d%d%d%d",&l,&r,&x,&y);
        qu[y].push_back((qry){l,r,i,1});
        if(x)qu[x-1].push_back((qry{l,r,i,-1}));
    }build(1,n,1);
    for(rg int i=0;i<=m;i++) {
        if(i) {
            K=get_m(X[i]),update(1,n,1,L[i],R[i]);
            if(L[i]>1)K=get_m(0),update(1,n,1,1,L[i]-1);
            if(R[i]<n)K=get_m(0),update(1,n,1,R[i]+1,n);
        }
        for(auto j:qu[i]) {
            ans[j.id]=add(ans[j.id],query(1,n,1,j.l,j.r)*j.flag);
            if(ans[j.id]<0)ans[j.id]+=mod;
            if(ans[j.id]>=mod)ans[j.id]-=mod;
        }
    }
    for(rg int i=1;i<=q;i++)printf("%d\n",ans[i]);
}