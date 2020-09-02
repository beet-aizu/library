#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../segtree/count/dynamic_offline.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int h,w,t,q;
  cin>>h>>w>>t>>q;

  RangeCount<int, int> beet(h),ushi(h);

  vector<int> ts(q),cs(q);
  vector<int> y1(q),x1(q),y2(q),x2(q);

  for(int i=0;i<q;i++){
    cin>>ts[i]>>cs[i]>>y1[i]>>x1[i];
    y1[i]--;x1[i]--;

    if(cs[i]==0||cs[i]==1){
      beet.preupdate(y1[i],x1[i]);
      ushi.preupdate(y1[i],x1[i]);
    }

    if(cs[i]==2) cin>>y2[i]>>x2[i];
  }
  beet.build();
  ushi.build();

  using P = pair<int, int>;
  queue<P> que;

  for(int i=0;i<q;i++){
    while(!que.empty()&&que.front().first<=ts[i]){
      int k=que.front().second;que.pop();
      beet.update(y1[k],x1[k],-1);
      ushi.update(y1[k],x1[k],+1);
    }
    if(cs[i]==0){
      beet.update(y1[i],x1[i],+1);
      que.emplace(ts[i]+t,i);
    }
    if(cs[i]==1){
      if(ushi.query(y1[i],y1[i]+1,x1[i],x1[i]+1)==0) continue;
      ushi.update(y1[i],x1[i],-1);
    }
    if(cs[i]==2){
      cout<<ushi.query(y1[i],y2[i],x1[i],x2[i])<<" ";
      cout<<beet.query(y1[i],y2[i],x1[i],x2[i])<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
