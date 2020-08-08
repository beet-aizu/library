#define PROBLEM "https://yukicoder.me/problems/4569"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../mod/rint.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int p,n;
  cin>>p>>n;
  auto as=read(n);
  string s;
  cin>>s;

  using R = Rint<int>;
  R::set_mod(p);
  R ans(as[0]);
  for(int i=1;i<n;i++){
    if(s[i-1]=='+') ans+=R(as[i]);
    if(s[i-1]=='-') ans-=R(as[i]);
    if(s[i-1]=='*') ans*=R(as[i]);
    if(s[i-1]=='/') ans/=R(as[i]);
  }

  cout<<ans<<endl;
  return 0;
}
