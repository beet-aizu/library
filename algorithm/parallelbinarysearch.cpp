#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
vector<int> parallelbinarysearch(int n,int q,
                                 function<void(void)> init,
                                 function<void(int)> apply,
                                 function<bool(int)> check){
  vector<vector<int> > C(q);
  vector<int> L(n,-1),R(n,q);
  bool flg=1;
  while(flg){
    flg=0;
    init();
    for(int i=0;i<n;i++)
      if(L[i]+1<R[i]) C[(L[i]+R[i])>>1].emplace_back(i);
    for(int i=0;i<q;i++){
      flg|=!C[i].empty();
      apply(i);
      for(int j:C[i]){
        if(check(j)) R[j]=i;
        else L[j]=i;
      }
      C[i].clear();
    }
  }
  return R;
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../datastructure/unionfindtree.cpp"
#undef call_from_test

signed CODETHANKSFESTIVAL2017_H(){
  int n,m;
  cin>>n>>m;
  vector<int> a(m),b(m);
  for(int i=0;i<m;i++) cin>>a[i]>>b[i];
  int q;
  cin>>q;
  vector<int> x(q),y(q);
  for(int i=0;i<q;i++) cin>>x[i]>>y[i];

  for(int i=0;i<m;i++) a[i]--,b[i]--;
  for(int i=0;i<q;i++) x[i]--,y[i]--;

  UnionFind uf;
  auto init=[&]{uf=UnionFind(n);};
  auto apply=[&](int i){uf.unite(a[i],b[i]);};
  auto check=[&](int i){return uf.same(x[i],y[i]);};

  auto ans=parallelbinarysearch(q,m,init,apply,check);

  for(int i=0;i<q;i++)
    cout<<(ans[i]==m?-1:ans[i]+1)<<endl;

  return 0;
}
/*
  verified on 2019/10/25
  https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h
*/

signed main(){
  CODETHANKSFESTIVAL2017_H();
  return 0;
}
#endif
