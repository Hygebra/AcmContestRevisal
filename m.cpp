//
// Created by Layn on 24-10-27.
//
#include <bits/stdc++.h>
using namespace std;
const int S=2003;
int n;
struct node {
    int x,y;
    node operator+(node a) const {return (node){x+a.x,y+a.y};}
    node operator-(node a) const {return (node){x-a.x,y-a.y};}
}a[S];
inline int dot(node a,node b) {
    return a.x*b.y-a.y*b.x;
}
inline int inl(node a,node b,node c) {
    return dot(c-b,c-a)==0;
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        scanf("%d%d",&a[i].x,&a[i].y);
        if (i>=3 && inl(a[i-2],a[i-1],a[i])) {
            a[i-1] = a[i];
            --i;--n;
        }
    }
    int res=0;
    if (n>3 && inl(a[1],a[n],a[n-1])) {
        --n;
    }
    if (n>3 && inl(a[2],a[1],a[n])) {
        for (int i=1;i<n;++i)
            a[i]=a[i+1];
        --n;
    }
    a[0]=a[n];a[n+1]=a[1];
    for (int i=1;i<=n;++i) {
        if (a[i].y==a[i+1].y) {
            continue;
        }
        if ((a[i].y==a[i-1].y && a[(i-2)>=0?i-2:i-2+n].y>a[i-1].y && a[i+1].y>a[i].y)
            ||
            (a[i-1].y>a[i].y && a[i+1].y>a[i].y)) {
            int s=0;
            for (int j=1;j<=n;++j) {
                if (a[j].x==a[i].x && a[j].y<a[i].y) {
                    if ((a[j-1].x-a[j].x)*(a[j+1].x-a[j].x)<0) {
                        ++s;
                    }
                }
                if (j<n && a[j].x==a[j+1].x && a[j].x==a[i].x && max(a[j].y,a[j+1].y)<a[i].y) {
                    if ((a[j-1].x-a[j].x)*(a[j+2].x-a[j+1].x)<0) {
                        ++s;
                    }
                }
            }
            if (a[n].x == a[1].x && a[1].x==a[i].x && max(a[1].y,a[n].y)<a[i].y
                && (a[2].x-a[1].x)*(a[n-1].x-a[n].x)<0) {
                ++s;
            }
            for (int j=1;j<=n;++j) {
                node ta=a[j],tb=a[j+1];
                if (ta.x>tb.x) swap(ta,tb);
                if (ta.x<a[i].x && a[i].x<tb.x && dot(tb-ta,a[i]-ta)>0) {
                        ++s;
                }
            }
            if (s%2==0) ++res;
        }
    }
    printf("%d\n",res);
    return 0;
}