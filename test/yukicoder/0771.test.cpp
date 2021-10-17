// verification-helper: PROBLEM https://yukicoder.me/problems/771

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../convexhulltrick/convexhulltrick.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using D = double;
  D c,d;
  cin>>c>>d;
  vector<D> as{{3.0/4.0,1.0/4.0}};
  vector<D> bs{{2.0/7.0,5.0/7.0}};
  vector<D> cs{{c,d}};
  D ans=solve_lp_max<D>(1000,2000,as,bs,cs);
  cout<<fixed<<setprecision(12)<<ans<<endl;
  return 0;
}
