#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0367"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../linkcuttree/path.cpp"
#undef call_from_test

signed main(){
  using ll = long long;

  int n,k;
  cin>>n>>k;

  vector< vector<int> > G(n);
  vector< unordered_map<ll, ll> > m(n);
  for(int i=0;i<n-1;i++){
    int a,b,c;
    cin>>a>>b>>c;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
    m[a][b]=m[b][a]=c;
  }

  vector<ll> ws(n,0);
  vector<int> ps(n,-1);
  using T = tuple<ll, ll, ll>;
  auto mget=[&](ll a,ll b){
              if(ps[a]!=b&&ps[b]!=a) return 0LL;
              ll res=ws[a]+ws[b]+m[a][b];
              if(res%k) return res;
              return 0LL;
            };

  auto f=[&](T a,T b){
           ll al,ar,av;
           tie(al,ar,av)=a;
           ll bl,br,bv;
           tie(bl,br,bv)=b;
           return T(al,br,av+bv+mget(ar,bl));
         };

  auto g=[&](T a,ll b){b++;return a;};
  auto h=[&](ll a,ll b){b++;return a;};
  auto s=[&](T a){
           ll al,ar,av;
           tie(al,ar,av)=a;
           return T(ar,al,av);
         };

  using LCT = LinkCutTree<T, ll>;
  LCT lct(f,g,h,s,T(-1,-1,0),0);
  vector<LCT::Node* > vs(n);
  for(int i=0;i<n;i++) vs[i]=lct.create(i,T(i,i,0));

  {
    using P = pair<ll, ll>;
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

  int q;
  cin>>q;
  while(q--){
    string op;
    cin>>op;
    if(op=="add"){
      int x,d;
      cin>>x>>d;
      lct.expose(vs[x]);
      ws[x]+=d;
      lct.recalc(vs[x]);
    }
    if(op=="send"){
      int s,t;
      cin>>s>>t;
      lct.evert(vs[s]);
      cout<<get<2>(lct.query(vs[t]))<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
