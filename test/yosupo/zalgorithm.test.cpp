// verification-helper: PROBLEM https://judge.yosupo.jp/problem/zalgorithm

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/space.cpp"
#include "../../string/zalgorithm.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s;
  cin>>s;

  space(zalgorithm(s));
  return 0;
}
