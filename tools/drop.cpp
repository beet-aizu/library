#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  int a,b,c,d,e,k;
  cin>>a>>b>>c>>d>>e>>k;
  vector<int> vs({a,b,c,d,e});
  for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
      if(abs(vs[i]-vs[j])>k) drop(":(");
  drop("Yay!"s);
  return 0;
}
/*
  verified on 2019/07/08
  https://atcoder.jp/contests/abc123/tasks/abc123_a
*/
#endif
