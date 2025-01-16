#include<bits/stdc++.h>
using namespace std;
const int N=1010;
const double inf=1e18;
int n,m,p;
double f[N][N];
double sq(double x){return x*x;}
int main() {
    scanf("%d%d%d",&n,&m,&p);
    f[n][m]=0;
    for(int i=0;i<=n;i++)f[i][0]=f[i][m+1]=inf;
    for(int i=0;i<=m;i++)f[0][i]=f[n+1][i]=inf;
    for(int i=n;i>=1;i--)for(int j=m;j>=1;j--) {
        if(i==n&&j==m)continue;
        double x=f[i+1][j],y=f[i][j+1];
        if(x>y+p)f[i][j]+=0.5*(y+p*0.5);
        else if(x<y)f[i][j]+=0.5*x;
        else f[i][j]+=0.5*(x-0.5*sq(x-y)/p);
        swap(x,y);
        if(x>y+p)f[i][j]+=0.5*(y+p*0.5);
        else if(x<y)f[i][j]+=0.5*x;
        else f[i][j]+=0.5*(x-0.5*sq(x-y)/p);
    }
    printf("%.10lf",f[1][1]);
}