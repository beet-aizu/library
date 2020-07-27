#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif

//BEGIN CUT HERE
template<typename T>
vector<int> cartesian_tree(const vector<T> &vs){
  int n=vs.size();
  vector<int> ps(n,-1),ls(n,-1),rs(n,-1);
  int cur=0;
  for(int i=1;i<n;i++){
    if(vs[cur]<=vs[i]){
      rs[cur]=i;
      ps[i]=cur;
      cur=i;
      continue;
    }
    while(~ps[cur] and vs[i]<vs[ps[cur]]) cur=ps[cur];
    ps[i]=ps[cur];
    if(~ps[i]) rs[ps[i]]=i;
    ls[i]=cur;
    ps[cur]=i;
    cur=i;
  }
  return ps;
}
//END CUT HERE

#ifndef call_from_test
signed main(){
  return 0;
}
#endif
