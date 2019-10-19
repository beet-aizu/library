#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;
//END CUT HERE
#ifndef call_from_test
signed main(){
  Int n;
  cin>>n;
  vector<double> a(n);
  for(Int i=0;i<n;i++) cin>>a[i];
  cout<<(a.back()-a.front())/(n-1)<<endl;
  return 0;
}
#endif
