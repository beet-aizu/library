#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2286"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../math/totient_table.cpp"
#undef call_from_test

signed main(){
  const int MAX = 1e6;
  auto ts=totient_table(MAX);
  vector<long long> sm(ts.begin(),ts.end());
  for(int i=0;i<MAX;i++) sm[i+1]+=sm[i];

  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    int n;
    cin>>n;
    cout<<sm[n]+1<<"\n";
  }
  cout<<flush;
  return 0;
}
