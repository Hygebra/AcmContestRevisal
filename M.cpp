#include<bits/stdc++.h>
using namespace std;
const int S=100005;
int n,m,mxid;
long long a[S],res,su;
using pii = pair<int,int>;
set<int> L,R;
inline int read() {
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}
set<int>::iterator it,jt,kt;
int LR() {
    if (L.empty()) return 0;
    it = L.end();
    --it;
    return *it;
}
int RL() {
    if (R.empty()) return n+1;
    it = R.begin();
    return *it;
}
vector<int> ve;
void work(int x,int v) {
    if (a[x]+v>=a[mxid]) {
      //  if (x!=mxid)
            {
            if (x<mxid) {
                int la = mxid,o;
                L.erase(mxid);
                while (!L.empty()) {
                    o = LR();
                    res-=(la-o)*a[o];
                    if (o < x) break;
                    la = o;L.erase(o);
                }
            } else {
                int la = mxid,o;
                R.erase(mxid);
                while (!R.empty()) {
                    o=RL();
                    res -= (o-la)*a[o];
                    if (o>x) break;
                    la=o;R.erase(o);
                }
            }
            int o;
            o=LR();res+=(x-o)*a[o];L.insert(x);
            o=RL();res+=(o-x)*a[o];R.insert(x);
            mxid=x;
        }
    } else {
        ve.clear();
        if (x<mxid) {
            auto pos=L.upper_bound(x);
            int pre = 0;
            if (pos!=L.begin()) {
                it = pos;--it;
                pre = *it;
            }
            if (a[x]+v<=a[pre]) goto end;
            else res-=(*pos-pre)*a[pre];
            while (a[x]+v>a[*pos]) {
                ve.push_back(*pos);
                ++pos;
            }
            int las = *pos;
            ve.push_back(las);
            for (int j=0,sz=ve.size();j<sz-1;++j) {
                res-=(ve[j+1]-ve[j])*a[ve[j]];
                L.erase(ve[j]);
            }
            if (pre != x) {
                res+=(x-pre)*a[pre];
                L.insert(x);
            }
            res+=(las-x)*(a[x]+v);
        } else if (x>mxid) {
            auto pos=R.lower_bound(x);
            int pre = n+1;
            if (pos!=R.end()) {
                it = pos;--pos;
                pre = *it;
            } else --pos;
            if (a[x]+v<=a[pre]) goto end;
            else res-=(pre-*pos)*a[pre];
            while (a[x]+v>a[*pos]) {
                ve.push_back(*pos);
                --pos;
            }
            int las = *pos;
            ve.push_back(las);
            for (int j=0,sz=ve.size();j<sz-1;++j) {
                res-=(ve[j]-ve[j+1])*a[ve[j]];
                R.erase(ve[j]);
            }
            if (pre != x) {
                res+=(pre-x)*a[pre];
                R.insert(x);
            }
            res+=(x-las)*(a[x]+v);
        }
    }
    end:
    a[x]+=v;
    su+=v;
}
void prL() {
    for (int o: L) printf("%d ",o);
    puts("L");
}
void prR() {
    for (int o:R) printf("%d ",o);
    puts("R");
}
int main() {
    int T;T=read();
    while(T--) {
        n=read();
        mxid=1;
        L.clear();
        R.clear();
        res=0;
        su=0;
        for (int i=1;i<=n;++i) {
            a[i]=0;
        }
        a[0]=a[n+1]=0;
        a[1]=read();su=a[1];
        L.insert(1);R.insert(1);
        for(int i=2;i<=n;i++) {
            work(i,read());
            //prL();prR();
        //printf("%lld %lld\n",res+a[mxid],su);
        }
        //puts("c");
        m=read();
        int x,v;
        while (m--) {
            scanf("%d%d",&x,&v);
            work(x,v);
            //prL();prR();
            printf("%lld\n",res+a[mxid]-su);
        }
        //puts("end");
    }
    return 0;
}