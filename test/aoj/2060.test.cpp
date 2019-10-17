#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2060"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/tetrahedra.cpp"
#undef call_from_test

signed main(){
  int n;
  while(cin>>n,n){
    vector<double> as(n);
    double ans=0;
    for(int i=0;i<n;i++) cin>>as[i];
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        for(int k=j+1;k<n;k++){
          for(int x=0;x<n;x++){
            if(i==x||j==x||k==x) continue;
            for(int y=0;y<n;y++){
              if(i==y||j==y||k==y||x==y) continue;
              for(int z=0;z<n;z++){
                if(i==z||j==z||k==z||x==z||y==z) continue;
                ans=max(ans,tetrahedra(as[i],as[j],as[k],
                                       as[x],as[y],as[z]));
              }
            }
          }
        }
      }
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
  }
  return 0;
}
