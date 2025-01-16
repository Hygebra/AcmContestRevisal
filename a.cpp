//
// Created by Layn on 24-11-13.
//
#include <bits/stdc++.h>
using namespace std;
const int S=300005;
int root[S],n,m,q,rnd[S],tot,ch[S][2],L[S],R[S],id[S],fa[S];
map<pair<int,int>, int> mp;
vector<int> ve[S];
void upd(int x) {
    if (ch[x][0]) fa[ch[x][0]]=x;
    if (ch[x][1]) fa[ch[x][1]]=x;
}
int merge(int x,int y) {
    if (!x || !y) return x|y;
    if (rnd[x]<rnd[y]) {
        ch[x][1] = merge(ch[x][1],y);
        upd(x);
        return x;
    } else {
        ch[y][0] = merge(x,ch[y][0]);
        upd(y);
        return y;
    }
}
void split(int rt,int &x,int &y, int k) {
    if (!rt) {x=y=0;}
    else {
        if (L[rt]<k) {
            x = rt;
            split(ch[rt][1],ch[x][1], y, k);
        } else {
            y = rt;
            split(ch[rt][0], x,ch[y][0], k);
        }
        upd(rt);
    }
}
struct wenti {
    int o,a,b;
}b[S];
inline bool cmp(const int &p,const int &q) {
    return b[p].b<b[q].b;
}
int find_right_node(int x) {
    while (fa[x]) x = fa[x];
    while (ch[x][1]) x = ch[x][1];
    return id[x];
}
void dfs(int x) {
    if (!x) return;
    dfs(ch[x][0]);
    printf("%d ",x);
    dfs(ch[x][1]);
}
int main() {
    srand(233);
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=q;++i) {
        scanf("%d%d",&b[i].o,&b[i].a);
        if (b[i].o==1) {
            scanf("%d",&b[i].b);
            ve[b[i].a].push_back(b[i].b);
            ve[b[i].a+1].push_back(b[i].b);
        } else {
            b[i].b=0;
            ve[b[i].a].push_back(0);
        }
    }
    for (int i=1;i<=n;++i)
        sort(ve[i].begin(), ve[i].end());
    for (int i=1;i<=n;++i) {
        for (int j=0,sz=ve[i].size();j<sz;++j) {
            if (j==sz-1) {
                mp[make_pair(i, ve[i][j])] = ++tot;
                //printf("%d(%d) ",ve[i][j],tot);
                L[tot] = ve[i][j];
                R[tot] = m+1;
            } else {
                if (ve[i][j]==0 && ve[i][j+1] == 0) continue;
                mp[make_pair(i, ve[i][j])] = ++tot;
                //printf("%d(%d) ",ve[i][j],tot);
                L[tot] = ve[i][j];
                R[tot] = ve[i][j+1]-1;
            }
            rnd[tot] = rand();
            id[tot] = i;
            root[i] = merge(root[i], tot);
        }
        //puts("");
    }
    for (int i=1;i<=q;++i) {
        //for (int i=1;i<=3;++i)
        //    dfs(root[i]),puts(" tree");
        int id1 = mp[make_pair(b[i].a, b[i].b)];
        //printf("%d %d : id1 = %d\n",b[i].a,b[i].b,id1);
        if (b[i].o==1) {
            int id2 = mp[make_pair(b[i].a+1, b[i].b)];
            int r1 = find_right_node(id1);
            int r2 = find_right_node(id2);
            //printf("%d %d %d %d\n",id1,id2,r1,r2);
            int ta1,tb1,ta2,tb2;
            split(root[r1], ta1,tb1, b[i].b);
            split(root[r2], ta2,tb2, b[i].b);
            fa[root[r1] = merge(ta2, tb1)] = 0;
            fa[root[r2] = merge(ta1, tb2)] = 0;
            //printf("%d %d\n",find_right_node(mp[make_pair(b[i].a,0)]), find_right_node(mp[make_pair(b[i].a+1,0)]));
        } else {
            printf("%d\n",find_right_node(id1));
        }
    }
    return 0;
}