#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0424"

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../flow/hopcroft_karp.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<string> ss(n);
  for(int i=0;i<n;i++) cin>>ss[i];

  int L=0,R=0;
  map<string, int> mp;
  for(int i=0;i<n;i++){
    if(ss[i].size()&1){
      mp[ss[i]]=L++;
    }else{
      mp[ss[i]]=R++;
    }
  }

  BiMatch G(L,R);
  for(int i=0;i<n;i++){
    int m=ss[i].size();
    for(int j=0;j<m;j++){
      string t(ss[i]);
      t.erase(t.begin()+j);
      if(!mp.count(t)) continue;
      int u=mp[ss[i]],v=mp[t];
      if(t.size()&1) swap(u,v);
      G.add_edge(u,v);
    }
  }

  cout<<G.build()<<endl;
  return 0;
}
