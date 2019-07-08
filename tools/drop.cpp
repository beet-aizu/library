#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
//END CUT HERE
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
