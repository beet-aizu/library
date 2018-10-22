#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct Sack{
  using F = function<void(int)>;
  int n;
  vector<int> sz,hvy,big;
  vector<vector<int> > G,Q;
  F expand,shrink,query,reset;
  
  Sack(int n,F expand,F shrink,F query,F reset):
    sz(n),hvy(n,-1),big(n,0),G(n),Q(n),
    expand(expand),shrink(shrink),
    query(query),reset(reset){}
  
  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void add_query(int v,int k){
    Q[v].emplace_back(k);
  }
  
  void build(int v=0,int p=-1){
    sz[v]=1;
    for(int u:G[v]){
      if(u==p) continue;
      build(u,v);
      if(hvy[v]<0||sz[hvy[v]]<sz[u]) hvy[v]=u;
      sz[v]+=sz[u];
    }
  }

  void add(int v,int p,int x){
    if(x==1) expand(v);
    else shrink(v);
    for(int u:G[v])
      if(u!=p&&!big[u]) add(u,v,x);
  }

  void dfs(int v=0,int p=-1,bool k=0){
    for(int u:G[v])
      if(u!=p&&u!=hvy[v]) dfs(u,v,0);
    if(~hvy[v]){
      dfs(hvy[v],v,1);
      big[hvy[v]]=1;
    }
    add(v,p,1);
    for(int k:Q[v]) query(k);
    if(~hvy[v]) big[hvy[v]]=0;
    if(!k) add(v,p,0),reset(v);
  }
  
};
//END CUT HERE
//INSERT ABOVE HERE
signed ECR2_E(){
  int n;
  scanf("%d",&n);
  vector<int> c(n);
  for(int i=0;i<n;i++) scanf("%d",&c[i]);
  vector<int> cnt(n+1,0);
  vector<Int> ans(n,0);
  int mx=0;
  Int res=0;
  auto expand=
    [&](int v){
      cnt[c[v]]++;
      if(mx<cnt[c[v]]){
        mx=cnt[c[v]];
        res=0;
      }
      if(mx==cnt[c[v]]) res+=c[v];      
    };  
  auto shrink=[&](int v){cnt[c[v]]--;};
  auto query =[&](int v){ans[v]=res;};
  auto reset =[&](int v){v++;mx=res=0;};  
  Sack sc(n,expand,shrink,query,reset);
  for(int i=1;i<n;i++){
    int x,y;
    scanf("%d %d",&x,&y);
    x--;y--;
    sc.add_edge(x,y);
  }
  sc.build();
  for(int i=0;i<n;i++) sc.add_query(i,i);
  sc.dfs();
  for(int i=0;i<n;i++){
    if(i) printf(" ");
    printf("%lld",ans[i]);
  }
  puts("");
  return 0;
}

/*
  verified on 2018/07/16
  http://codeforces.com/contest/600/problem/E
*/


signed CFR316_D(){
  int n,q;
  scanf("%d %d",&n,&q);
  
  vector<int> c(n),dep(n);
  vector<int> vs(q),hs(q),ans(q);
  vector<int> cnt(n+1,0),odd(n+1,0);
  
  auto flip=
    [&](int v){
      odd[dep[v]]-=(cnt[dep[v]]>>c[v])&1;
      cnt[dep[v]]^=(1<<c[v]);
      odd[dep[v]]+=(cnt[dep[v]]>>c[v])&1;
    };  
  
  auto query =[&](int k){ans[k]=odd[hs[k]]<=1;};
  auto reset =[&](int v){v++;};
  
  Sack sc(n,flip,flip,query,reset);
  for(int i=1;i<n;i++){
    int p;
    scanf("%d",&p);
    p--;
    sc.add_edge(p,i);
  }
  sc.build();
  
  {
    auto &G=sc.G;
    function<void(int,int,int)> dfs=
      [&](int v,int p,int d){
        dep[v]=d;
        for(int u:G[v]){
          if(u==p) continue;
          dfs(u,v,d+1);
        }	
      };
    dfs(0,-1,1);
  }
  
  char* buf = new char[500500];
  scanf("%s",buf);
  for(int i=0;i<n;i++) c[i]=buf[i]-'a';
  
  for(int i=0;i<q;i++){
    scanf("%d %d",&vs[i],&hs[i]);
    vs[i]--;
    sc.add_query(vs[i],i);
  }
  
  sc.dfs();
  for(int i=0;i<q;i++)
    puts(ans[i]?"Yes":"No");
  return 0;
}
/*
  verified on 2018/07/16
  http://codeforces.com/contest/570/problem/D
*/



signed CFR130_E(){
  int n;
  scanf("%d",&n);
  
  vector<int> dep(n),rs;
  vector<int> vs,hs,ans;
  vector<int> cnt(n+1,0);
  
  auto expand=[&](int v){cnt[dep[v]]++;};  
  auto shrink=[&](int v){cnt[dep[v]]--;};
  auto query =[&](int k){ans[k]=cnt[dep[vs[k]]+hs[k]]-1;};
  auto reset =[&](int v){v++;};
  
  Sack sc(n,expand,shrink,query,reset);
  for(int i=0;i<n;i++){
    int p;
    scanf("%d",&p);
    p--;
    if(~p) sc.add_edge(p,i);
    else rs.emplace_back(i);
  }
  sc.build();
  
  vector<vector<int> > ps(20,vector<int>(n,-1));
  {
    auto &G=sc.G;
    function<void(int,int,int)> dfs=
      [&](int v,int p,int d){
        ps[0][v]=p;
        dep[v]=d;
        for(int u:G[v]){
          if(u==p) continue;
          dfs(u,v,d+1);
        }	
      };
    for(int r:rs) dfs(r,-1,1);
  }
  
  int q;
  scanf("%d",&q);
  vs.assign(q,0);
  hs.assign(q,0);
  ans.assign(q,0);

  for(int k=0;k+1<20;k++)
    for(int i=0;i<n;i++)
      ps[k+1][i]=ps[k][i]<0?-1:ps[k][ps[k][i]];
  
  auto calc=
                          [&](int v,int k){
                            for(int i=0;~v&&i<20;i++)
                              if((k>>i)&1) v=ps[i][v];
                            return v;
                          };
  
  for(int i=0;i<q;i++){
    scanf("%d %d",&vs[i],&hs[i]);
    vs[i]--;
    vs[i]=calc(vs[i],hs[i]);
    if(~vs[i]) sc.add_query(vs[i],i);
  }
  
  for(int r:rs) sc.dfs(r,-1,0);
  for(int i=0;i<q;i++){
    if(i) printf(" ");
    printf("%d",ans[i]);
  }
  puts("");
  return 0;
}
/*
  verified on 2018/07/16
  https://codeforces.com/contest/208/problem/E
*/

signed main(){
  //ECR2_E();
  //CFR316_D();
  CFR130_E();
  return 0;
}
