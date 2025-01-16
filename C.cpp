#include<bits/stdc++.h>
using namespace std;
int A,B,C,T;
int main() {
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&A,&B,&C);
        long long ans=LLONG_MAX,res=0;
        bool flag=0;
        for(int i=0;i<=30;i++){
            ans=min(ans,1ll*B*(C>>i)+res+flag*B);
            res+=A;
            if((C>>i)&1)flag=1;
        }
        printf("%lld\n",ans);
    }
}