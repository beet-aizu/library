#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../geometry/argsort.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  using ll = long long;
  struct Point{ll x,y;};
  vector<Point> ps(n);
  for(int i=0;i<n;i++) cin>>ps[i].x>>ps[i].y;

  argsort(ps);

  for(int i=0;i<n;i++) cout<<ps[i].x<<" "<<ps[i].y<<"\n";
  cout<<flush;
  return 0;
}
