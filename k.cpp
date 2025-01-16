//
// Created by Layn on 24-11-4.
//
#include <bits/stdc++.h>
using namespace std;
const int S=500005;
int n,q,a[S];
multiset<int> po,ne;
long long spo,sne,s[S];
int rnd[S],ch[S][2],b[S],tot=0,sz[S];
int nnd(int x) {
    ++tot;
    b[tot] = x;
    rnd[tot] = rand();
    s[tot] = x;
    sz[tot]=1;
    return tot;
}
void upd(int x) {
    //if (x==0) puts("d");
    s[x]=s[ch[x][0]]+s[ch[x][1]]+b[x];
    sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
}
void split(int rt,int &x,int &y,int k) {
    if (!rt) {
        x=y=0;
        return;
    }
    if (b[rt]<=k) {
        x = rt;
        split(ch[rt][1], ch[x][1], y,k);
    } else {
        y = rt;
        split(ch[rt][0],x,ch[y][0],k);
    }
    upd(rt);
}
void split_2(int rt,int &x,int &y,long long k) {
    if (!rt) {x=y=0;return;}
    if (s[ch[rt][0]]+b[rt]<=k) {
        x = rt;
        split_2(ch[rt][1], ch[x][1], y,k-s[ch[rt][0]]-b[x]);
    } else {
        y=rt;
        split_2(ch[rt][0],x,ch[rt][0],k);
    }
    //if (!rt) puts("ddd");
    upd(rt);
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
void del(int &root,int x) {
    int ta,tb,tc,td;
    split(root,ta,tb,x-1);
    split(tb,tc,td,x);
    //printf("tc = %d %d\n",sz[ch[tc][0]] ,sz[ch[tc][1]]);
    tc = merge(ch[tc][0],ch[tc][1]);
    root = merge(ta, merge(tc,td));
}
int query(int &root,long long k) {
    int ta,tb;
    split_2(root, ta,tb, k);
    int ret = sz[ta];
    root = merge(ta,tb);
    return ret;
}
int root_po,root_ne;
void insert(int &root, int x) {
    int p = nnd(x),ta,tb;
    split(root,ta,tb,x);
    root = merge(ta,merge(p,tb));
}
int main() {
    srand(233);
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;++i) {
        scanf("%d",a+i);
        if (a[i]<=0) ne.insert(a[i]),insert(root_ne,a[i]),sne+=a[i];
        else po.insert(a[i]),insert(root_po, a[i]),spo+=a[i];
    }//printf("%d\n",sz[root_po]);
    int x,v;
    while (q--) {
        scanf("%d%d",&x,&v);//puts("c");
        if (a[x]<=0) del(root_ne, a[x]),sne-=a[x];
        else del(root_po, a[x]),spo-=a[x];
        //puts("e");
        a[x]=v;
        if (a[x]<=0) insert(root_ne, a[x]),sne+=a[x];
        else insert(root_po, a[x]),spo+=a[x];
        //printf("%d %lld\n",sz[root_po],sne);
        int cnt = sz[root_po];
        printf("%d\n",query(root_po,-sne)+1);
    }
    return 0;
}