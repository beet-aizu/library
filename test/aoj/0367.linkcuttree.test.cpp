#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0367"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../linkcuttree/base.cpp"
#include "../../linkcuttree/path.cpp"
#undef call_from_test

signed main(){
  using ll = long long;

  int n,k;
  cin>>n>>k;

  using T = tuple<ll, ll, ll>;
  vector<ll> ws(n,0);
  vector< unordered_map<ll, ll> > m(n);

  auto mget=[&](ll a,ll b){
              if(!m[a].count(b)) return 0LL;
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

  auto g=[&](T a,ll){return a;};

  auto h=[&](ll a,ll){return a;};

  auto s=[&](T a){
           ll al,ar,av;
           tie(al,ar,av)=a;
           return T(ar,al,av);
         };

  using Node = NodeBase<T, ll>;
  constexpr size_t LIM = 1e6;
  using LCT = Path<Node, LIM>;
  LCT lct(f,g,h,s,T(-1,-1,0),0);
  for(int i=0;i<n;i++) lct.create(T(i,i,0));

  for(int i=0;i<n-1;i++){
    int a,b,c;
    cin>>a>>b>>c;
    lct.evert(lct[b]);
    lct.link(lct[a],lct[b]);
    m[a][b]=m[b][a]=c;
  }

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    string op;
    cin>>op;
    if(op=="add"){
      int x,d;
      cin>>x>>d;
      lct.expose(lct[x]);
      ws[x]+=d;
      lct.pushup(lct[x]);
    }
    if(op=="send"){
      int s,t;
      cin>>s>>t;
      lct.evert(lct[s]);
      cout<<get<2>(lct.query(lct[t]))<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
