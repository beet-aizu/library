#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
vector<int> totient_table(int n){
  vector<int> ts(n+1);
  iota(ts.begin(),ts.end(),0);
  for(int i=2;i<=n;i++){
    if(ts[i]!=i) continue;
    for(int j=i;j<=n;j+=i) ts[j]=ts[j]/i*(i-1);
  }
  return ts;
}
//END CUT HERE

//INSERT ABOVE HERE
class CatAndMice {
  using ll = long long;
public:
  long long countDirections(int n, int c) {
    if(n==c) return 8;

    auto ts=totient_table(n);

    ll ans=0;
    for(int i=1;i<=n;i++)
      if((n/i)==c) ans+=ts[i];

    return ans*8LL;
  }
};
/*
  verified on 2019/09/25
  https://vjudge.net/problem/TopCoder-15530
*/
