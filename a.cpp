#include <iostream>
#include <string>
#include <map>
using namespace std;
map<string,int> mp;
map<string,int> pos;
int n,m,p[10],t[10];
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i) {
        string name;
        for (int j=1;j<=5;++j) {
            cin>>name;
            pos[name] = j;
        }
    }
    cin>>m;
    string name;
    int x;
    while (m--) {
        cin>>name>>x;
        if (pos[name]>0) {
            t[x]++;
        } else p[x]++;
    }
    int mn=t[1]+p[1],su=t[1];
    for (int i=2;i<=5;++i)
        mn=min(mn,t[i]+p[i]),su+=t[i];
    printf("%d\n",min(su,mn));
    return 0;
}