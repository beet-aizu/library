#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/kdtree.cpp"
#undef call_from_test

signed main(){
  int N;
  scanf("%d",&N);
  KDTree kd(N);
  for(int i=0;i<N;i++) {
    int x,y;
    scanf("%d %d",&x,&y);
    kd.P[i]=KDTree::Point(i,x,y);
    kd.T[i].l = kd.T[i].r = kd.T[i].p = kd.NIL;
  }
  kd.np=0;
  int root=kd.makeKDTree(0,N,0);

  int q;
  scanf("%d",&q);
  int sx,tx,sy,ty;
  vector<KDTree::Point> ans;
  for(int i=0;i<q;i++){
    scanf("%d %d %d %d",&sx,&tx,&sy,&ty);
    ans.clear();
    kd.find(root,sx,tx,sy,ty,0,ans);
    sort(ans.begin(),ans.end());
    for(int j=0;j<(int)ans.size();j++){
      ans[j].print();
    }
    printf("\n");
  }
  return 0;
}
