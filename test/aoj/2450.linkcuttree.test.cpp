#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../linkcuttree/path.cpp"
#undef call_from_test

signed main(){
  int n,q;
  cin>>n>>q;

  using T = tuple<int, int, int, int, int>;
  using P = pair<int, int>;

  T ti(-1,-1,-1,-1,-1);
  P ei(-1,-114514);

  auto f=[&](T a,T b){
           int as,ava,avi,avl,avr;
           tie(as,ava,avi,avl,avr)=a;
           int bs,bva,bvi,bvl,bvr;
           tie(bs,bva,bvi,bvl,bvr)=b;
           int cs=as+bs;
           int cva=ava+bva,cvi=max(avi,bvi),cvl=avl,cvr=bvr;
           cvi=max(cvi,avr+bvl);
           cvl=max(cvl,ava+bvl);
           cvr=max(cvr,avr+bva);
           return T(cs,cva,cvi,cvl,cvr);
         };

  auto g=[&](T a,P p){
           if(p==ei) return a;
           int as,ava,avi,avl,avr;
           tie(as,ava,avi,avl,avr)=a;
           int v=p.first,b=p.second;
           if(~v) as=1;
           if(b>=0) return T(as,b*as,b*as,b*as,b*as);
           return T(as,b*as,b,b,b);
         };

  auto h=[&](P a,P b){a.first++;return b;};
  auto s=
    [&](T a){
      int as,ava,avi,avl,avr;
      tie(as,ava,avi,avl,avr)=a;
      swap(avl,avr);
      return T(as,ava,avi,avl,avr);
    };


  using LCT = LinkCutTree<T, P>;
  vector<LCT::Node* > vs(n);
  vector<int> ps(n,-1);

  LCT lct(f,g,h,s,ti,ei);

  vector<int> ws(n);
  for(int i=0;i<n;i++) cin>>ws[i];
  for(int i=0;i<n;i++) vs[i]=lct.create(i,g(ti,P(i,ws[i])));

  vector<vector<int> > G(n);
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  for(int i=0;i<n;i++)
    sort(G[i].begin(),G[i].end());

  {
    queue<P> q;
    q.emplace(0,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      if(~p) lct.link(vs[p],vs[v]);
      ps[v]=p;
      for(int u:G[v]){
        if(u==p) continue;
        q.emplace(u,v);
      }
    }
  }

  while(q--){
    int t,a,b,c;
    cin>>t>>a>>b>>c;
    a--;b--;
    if(t==1){
      lct.evert(vs[a]);
      lct.update(vs[b],P(-1,c));
    }
    if(t==2){
      lct.evert(vs[a]);
      int vva,vvi,vvl,vvr;
      tie(ignore,vva,vvi,vvl,vvr)=lct.query(vs[b]);
      cout<<max({vva,vvi,vvl,vvr})<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
