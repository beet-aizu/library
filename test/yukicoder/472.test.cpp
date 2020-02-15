#define PROBLEM "https://yukicoder.me/problems/472"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../math/totient.cpp"
#include "../../mod/tetration.cpp"
#undef call_from_test

signed main(){
  int a,n,m;
  cin>>a>>n>>m;
  cout<<tetration(a,n,m)<<endl;
  return 0;
}
