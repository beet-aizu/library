#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Mo{
  using F = function<void(int)>;
  vector<int> ls,rs,ord;
  int n,width,nl,nr,ptr;
  F expandL,expandR;
  F shrinkL,shrinkR;

  Mo(int n,int width,F expandL,F expandR,F shrinkL,F shrinkR):
    n(n),width(width),nl(0),nr(0),ptr(0),
    expandL(expandL),expandR(expandR),
    shrinkL(shrinkL),shrinkR(shrinkR){}

  Mo(int n,int width,F expand,F shrink):
    Mo(n,width,expand,expand,shrink,shrink){}

  void add(int l,int r){
    ls.emplace_back(l);
    rs.emplace_back(r);
  }

  void build(){
    ord.resize(ls.size());
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),
         [&](int a,int b){
           if(ls[a]/width!=ls[b]/width) return ls[a]<ls[b];
           if(rs[a]==rs[b]) return ls[a]<ls[b];
           return bool((rs[a]<rs[b])^((ls[a]/width)&1));
         });
  }

  int process(){
    if(ptr==(int)ord.size()) return -1;
    const int idx=ord[ptr++];
    while(nl>ls[idx]) expandL(--nl);
    while(nr<rs[idx]) expandR(nr++);
    while(nl<ls[idx]) shrinkL(nl++);
    while(nr>rs[idx]) shrinkR(--nr);
    return idx;
  }
};
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
