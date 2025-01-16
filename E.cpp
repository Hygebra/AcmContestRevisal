#include<bits/stdc++.h>
#define pb push_back
#define poly vector<long long>
using namespace std;
const int BLK=300,N=2e6+10,M=610;
int n,m,p[N],cnt,Len[N],rev[N];
long long Res[M][M];
bool vis[N];
poly b,c;
vector<long long>res[500];
struct comp {
    long double r,i;
    comp(long double _r=0,long double _i=0){r=_r;i=_i;}
    comp operator+(const comp x){return comp(r+x.r,i+x.i);}
    comp operator-(const comp x){return comp(r-x.r,i-x.i);}
    comp operator*(const comp x){return comp(r*x.r-i*x.i,r*x.i+i*x.r);}
}A[N],B[N],W[N];
const long double pi=acos(-1.0);
void FFT(comp a[],int lim) {
    for(int i=0;i<lim;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
    for(int mid=1,o=lim>>1;mid<lim;mid<<=1,o>>=1)
        for(int i=0;i<lim;i+=(mid<<1)) for(int j=0;j<mid;j++) {
            comp &A=a[i+j+mid],&B=a[i+j],t=W[j*o]*A;
            A=B-t,B=B+t;
        }
}
poly poly_mul(poly a,poly b) {
    int n=a.size(),m=b.size(),lim=1,d=-1;
    while(lim<n+m-1)lim<<=1,d++;rev[0]=0;
    for(int i=0;i<lim;i++) {
        rev[i]=(rev[i>>1]>>1)|((i&1)<<d);
        long double o=2*pi*i/lim;
        W[i]=comp(cos(o),sin(o));
    }
    for(int i=0;i<n;i++)A[i]=comp(a[i],0);
    for(int i=0;i<m;i++)B[i]=comp(b[i],0);
    FFT(A,lim),FFT(B,lim);
    for(int i=0;i<lim;i++)A[i]=A[i]*B[i],W[i].i*=-1;
    FFT(A,lim);
    poly c;c.clear();
    for(int i=0;i<n+m-1;i++)c.pb((long long)(A[i].r/lim+0.5));
    for(int i=0;i<lim;i++)A[i]=B[i]=comp(0,0);
    return c;
}
void dfs(int u) {
    vis[u]=1,b.push_back(u);
    if(!vis[p[u]])dfs(p[u]);
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1,x;i<=n;i++)scanf("%d",&x),p[x]=i;
    for(int u=1;u<=n;u++)if(!vis[u]){
        b.clear(),dfs(u),c.clear();
        int len=b.size();
        for(int i=0;i<len;i++)c.pb(b[i]);
        for(int i=0;i<len;i++)c.pb(b[i]);
        for(int i=0;i<len/2;i++)swap(b[i],b[len-i-1]);
        poly d=poly_mul(b,c);
        if(len>=BLK) {
            ++cnt;
            Len[cnt]=len;
            for(int i=0;i<len;i++)res[cnt].pb(d[len+i-1]);
        }else {
            for(int i=0;i<len;i++)Res[len][i]+=d[len+i-1];
        }
    }
    for(int k;m;m--) {
        scanf("%d",&k);
        long long ans=0;
        for(int i=1;i<=cnt;i++)ans+=res[i][k%Len[i]];
        for(int i=1;i<=BLK;i++)ans+=Res[i][k%i];
        printf("%lld\n",ans);
    }
}
// 4 4
// 2 4 1 3