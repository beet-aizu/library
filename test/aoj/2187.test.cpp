#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2187"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../tools/all_permutations.cpp"
#undef call_from_test

#define ERROR "1e-5"

signed solve(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  const int n=9;
  vector<int> as(n),bs(n);
  for(int i=0;i<n;i++) cin>>as[i];
  for(int i=0;i<n;i++) cin>>bs[i];
  int num=0,cnt=0;
  auto f=
    [&](vector<int> vs){
      int x=0,y=0;
      for(int i=0;i<n;i++){
        if(as[vs[i]]<bs[i]) x+=as[vs[i]]+bs[i];
        if(as[vs[i]]>bs[i]) y+=as[vs[i]]+bs[i];
      }
      if(x<y) num++;
      cnt++;
    };
  all_permutations(n,f);

  double A=(double)num/cnt;
  double B=1.0-A;
  cout<<fixed<<setprecision(5);
  cout<<A<<" "<<B<<endl;
  return 0;
}

signed main(){
  int T;
  cin>>T;
  while(T--) solve();
  return 0;
}
