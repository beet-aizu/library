#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../datastructure/BIT2D.cpp"
#undef call_from_test

signed main(){
  int h,w,t,q;
  cin>>h>>w>>t>>q;
  BIT2D<int> beet(h+100,w+100);
  BIT2D<int> ushi(h+100,w+100);
  using P = pair<int, int>;
  using PP = pair<int, P>;
  queue<PP> qq;
  for(int i=0;i<q;i++){
    int a,c,x1,y1;
    cin>>a>>c>>x1>>y1;
    while(!qq.empty()&&qq.front().first<=a){
      P p=qq.front().second;qq.pop();
      int x=p.first,y=p.second;
      assert(beet.sum(x-1,y-1,x,y)==1);
      beet.add(x,y,-1);
      assert(ushi.sum(x-1,y-1,x,y)==0);
      ushi.add(x,y,1);
    }
    if(c==0){
      assert(beet.sum(x1-1,y1-1,x1,y1)==0);
      beet.add(x1,y1,1);
      qq.push(PP(a+t,P(x1,y1)));
    }
    if(c==1){
      if(ushi.sum(x1-1,y1-1,x1,y1)==0) continue;
      ushi.add(x1,y1,-1);
    }
    if(c==2){
      int x2,y2;
      cin>>x2>>y2;
      x1--;y1--;
      cout<<ushi.sum(x1,y1,x2,y2)<<" "<<beet.sum(x1,y1,x2,y2)<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
