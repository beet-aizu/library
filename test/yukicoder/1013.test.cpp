// verification-helper: PROBLEM https://yukicoder.me/problems/1013

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
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
  for(int i=0;i<m;i++){
    string c;
    cin>>c;
    aho.add(c,i);
  }
  aho.build();
  cout<<aho.match(s)<<endl;
  return 0;
}
