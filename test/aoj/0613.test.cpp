#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0613"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fixpoint.cpp"
#include "../../tools/chminmax.cpp"
#include "../../vector/compress.cpp"
#include "../../datastructure/rangeslide.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;

  int n;
  ll d;
  cin>>n>>d;
  vector<ll> xs(n),ys(n);
  for(int i=0;i<n;i++) cin>>xs[i]>>ys[i];

  if(n==1){
    cout<<(xs[0]<=d?ys[0]:0)<<endl;
    return 0;
  }

  int h=n/2;
  using P = pair<ll, ll>;
  auto calc=
    [&](int a,int b){
      vector<P> res;
      MFP([&](auto dfs,int k,ll s,ll t)->void{
            if(k==b){
              res.emplace_back(s,t);
              return;
            }
            dfs(k+1,s,t);
            dfs(k+1,s+xs[k],t+ys[k]);
            dfs(k+1,s-xs[k],t-ys[k]);
          })(a,0,0);
      sort(res.begin(),res.end());
      return res;
    };
  auto v1=calc(0,h);
  auto v2=calc(h,n);
  reverse(v2.begin(),v2.end());

  const ll INF = 1e17;
  vector<ll> vs;
  for(auto p:v1) vs.emplace_back(p.first);
  vs.emplace_back(-INF);
  vs.emplace_back(+INF);
  vs=compress(vs);

  vector<ll> ws(vs.size(),-INF);
  {
    int k=0;
    for(auto p:v1){
      while(vs[k]<p.first) k++;
      chmax(ws[k],p.second);
    }
  }
  v1.clear();

  auto cmp=[](ll a,ll b){return a>b;};
  RangeSlide<ll, decltype(cmp)> slide(ws,cmp);

  vector<ll> ks;
  {
    int l=0,r=0;
    for(auto p:v2){
      ll x=p.first,k=p.second;
      while(l<(int)vs.size()&&vs[l]< -x-d) l++;
      while(r<(int)vs.size()&&vs[r]<=-x+d) r++;
      if(l==r) continue;
      slide.add_range(l,r);
      ks.emplace_back(k);
    }
  }
  vs.clear();
  v2.clear();

  auto res=slide.build();

  ll ans=0;
  for(int i=0;i<(int)res.size();i++)
    chmax(ans,ws[res[i]]+ks[i]);

  cout<<ans<<endl;
  return 0;
}
