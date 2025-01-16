//
// Created by Layn on 24-12-15.
//
#include<bits/stdc++.h>
    using namespace std;
const int N=5e5+10;
int T,n,a[N];
int main() {
    int T = 0;
    scanf("%d", &T);
    for (int G = 1; G <= T; G++) {
        int n = 0, d = 0,sum=0;
        scanf("%d%d", &n, &d);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
        if(d==1) {
            printf("%lld\n",1ll*sum*(sum-1)/2);
            continue;
        }
        if(d==2) {
            long long ans=0;
            for(int i=1;i<=n;i++)ans+=1ll*(sum-a[i])*a[i];
            printf("%lld\n",ans/2);
            continue;
        }
        sort(a+1,a+n+1);
        long long ans=0;
        for(int i=n;i>=1;i--)ans+=(1ll*(a[i]-a[i-1])*1ll*(n-i+1)*(n-i)/2);
        printf("%lld\n",ans);
    }
    return 0;
}