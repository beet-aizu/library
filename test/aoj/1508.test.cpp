#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../bbst/basic/chien.cpp"
#undef call_from_test

signed main(){
  int n,q;
  scanf("%d %d",&n,&q);
  vector<int> v(n);
  for(int i=0;i<n;i++) scanf("%d",&v[i]);

  auto f=[](int a,int b){return min(a,b);};
  const int INF = 1e9;
  RBST<int, int> rbst(f,f,f,INF,-1);

  auto rt=rbst.build(v);

  for(int i=0;i<q;i++){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    if(x==0){
      int l=y,r=z+1;
      rt=rbst.toggle(rt,l,r);
      rt=rbst.toggle(rt,l+1,r);
    }
    if(x==1){
      int l=y,r=z+1;
      printf("%d\n",rbst.query(rt,l,r));
    }
    if(x==2){
      rt=rbst.set_val(rt,y,z);
    }
  }

  return 0;
}
