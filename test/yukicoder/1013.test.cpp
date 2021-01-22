// verification-helper: PROBLEM https://yukicoder.me/problems/1013

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../string/trie.cpp"
#include "../../string/ahocorasick.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  AhoCorasick<26, false> aho('A');
  string s;
  cin>>s;
  int m;
  cin>>m;
  auto cs=read<string>(m);
  for(auto c:cs) aho.add(c,0);
  aho.build();
  cout<<aho.match(s)<<endl;

  auto res=aho.frequency(s);
  int cnt=0;
  for(auto c:cs) cnt+=res[aho.find(c)];
  assert(cnt==aho.match(s));
  return 0;
}
