#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../string/zalgorithm.cpp"
#include "../../string/run.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  string ss;
  cin>>ss;
  auto run=Run::enumerate(ss);

  set<Run::P> vis;
  vector<Run::T> ans;
  for(int t=1;t<=(int)ss.size();t++){
    for(auto lr:run[t]){
      if(vis.count(lr)) continue;
      vis.emplace(lr);
      ans.emplace_back(t,lr.first,lr.second);
    }
  }

  cout<<ans.size()<<endl;
  for(auto tlr:ans){
    int t,l,r;
    tie(t,l,r)=tlr;
    cout<<t<<" "<<l<<" "<<r<<"\n";
  }
  cout<<flush;
  return 0;
}
