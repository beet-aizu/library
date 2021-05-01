#define PROBLEM "https://yukicoder.me/problems/5061"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../vector/fusion.cpp"
#include "../../vector/compress.cpp"
#include "../../datastructure/slope.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int m,n;
  cin>>m>>n;
  auto as=read(m);
  auto bs=read(n);

  auto cs=compress(fusion(as,bs));
  auto dc=dict(cs);
  for(int &a:as) a=dc[a];
  for(int &b:bs) b=dc[b];

  const int sz = cs.size();
  vector<int> num(sz,0);
  for(int a:as) num[a]--;

  using ll = long long;
  for(int k=1;k<=m;k++){
    for(int b:bs) num[b]++;

    int pos=0;
    Slope<ll> S;
    S.add_a_minus_x(pos,1e9);
    for(int i=0;i<sz;i++){
      if(num[i]==0) continue;
      S.add_a_minus_x(0,cs[i]-pos);
      S.add_x_minus_a(0,cs[i]-pos);
      pos=cs[i];
      S.shift(num[i]);
      S.apply_cumulative_min();
    }

    cout<<S.get_val(0)<<'\n';
  }
  return 0;
}
