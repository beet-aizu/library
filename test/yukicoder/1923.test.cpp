#define PROBLEM "https://yukicoder.me/problems/1923"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tools/precision.cpp"
#include "../../datastructure/rangeslide.cpp"
#undef call_from_test

#define ERROR "1e-6"

signed main(){
  int n,k;
  cin>>n>>k;
  string s;
  cin>>s;
  vector<int> a(n);
  for(int i=0;i<n;i++) a[i]=s[i]-'0';

  using D = double;
  auto check=
    [&](D x)->int{
      vector<D> b(n);
      for(int i=0;i<n;i++) b[i]=a[i]-x;

      vector<D> sm(n*2+1,0);
      for(int i=0;i<n*2;i++)
        sm[i+1]=sm[i]+b[i%n];

      auto cmp=[](D a,D b){return a<b;};
      RangeSlide<D, decltype(cmp)> rs(sm,cmp);
      for(int i=0;i<n;i++)
        rs.add_range(i,i+n-k+1);

      auto res=rs.build();
      for(int i=0;i<n;i++)
        if(sm[n+i]>sm[res[i]]) return 1;
      return 0;
    };

  D L=0,R=1;
  for(int k=0;k<20;k++){
    D M=(L+R)/2;
    if(check(M)) L=M;
    else R=M;
  }
  cout<<L<<endl;
  return 0;
}
