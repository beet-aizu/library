#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct LevelAncestor{
  int n,h;
  vector<vector<int> > G,par,lad;
  vector<int> dep,nxt,len,pth,ord,hs;
  LevelAncestor(){}
  LevelAncestor(int n):
    n(n),G(n),dep(n),nxt(n,-1),len(n),pth(n),ord(n),hs(n+1,0){
    h=1;
    while((1<<h)<=n) h++;
    par.assign(h,vector<int>(n,-1));
    
    for(int i=2;i<=n;i++) hs[i]=hs[i>>1]+1;
  }

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  
  void dfs(int v,int p,int d,int f){
    if(nxt[v]<0){
      par[0][nxt[v]=v]=p;
      len[v]=dep[v]=d;
      for(int u:G[v]){
        if(u==p) continue;
        dfs(u,v,d+1,0);
        if(len[v]<len[u]) nxt[v]=u,len[v]=len[u];
      }
    }
    if(!f) return;
    pth[v]=lad.size();
    lad.emplace_back();
    for(int k=v;;k=nxt[k]){
      lad.back().emplace_back(k);
      pth[k]=pth[v];
      if(k==nxt[k]) break;
    }
    for(;;p=v,v=nxt[v]){	
      for(int u:G[v])
        if(u!=p&&u!=nxt[v]) dfs(u,v,d+1,1);	
      if(v==nxt[v]) break;
    }
  }
  
  void build(int r=0){
    dfs(r,-1,0,1);
    for(int k=0;k+1<h;k++){
      for(int v=0;v<n;v++){
        if(par[k][v]<0) par[k+1][v]=-1;
        else par[k+1][v]=par[k][par[k][v]];
      }
    }
    for(int i=0;i<(int)lad.size();i++){
      int v=lad[i][0],p=par[0][v];
      if(~p){
        int k=pth[p],l=min(ord[p]+1,(int)lad[i].size());
        lad[i].resize(l+lad[i].size());
        for(int j=0,m=lad[i].size();j+l<m;j++)
          lad[i][m-(j+1)]=lad[i][m-(j+l+1)];
        for(int j=0;j<l;j++)
          lad[i][j]=lad[k][ord[p]-l+j+1];
      }
      for(int j=0;j<(int)lad[i].size();j++)
        if(pth[lad[i][j]]==i) ord[lad[i][j]]=j;
    }
  }
  
  int lca(int u,int v){
    if(dep[u]>dep[v]) swap(u,v);
    for(int k=0;k<h;k++){
      if((dep[v]-dep[u])>>k&1){
        v=par[k][v];
      }
    }
    if(u==v) return u;
    for(int k=h-1;k>=0;k--){
      if(par[k][u]!=par[k][v]){
        u=par[k][u];
        v=par[k][v];
      }
    }
    return par[0][u];
  }

  int up(int v,int d){
    if(d==0) return v;
    v=par[hs[d]][v];
    d-=1LL<<hs[d];
    return lad[pth[v]][ord[v]-d];
  }
  
  int distance(int u,int v){
    return dep[u]+dep[v]-dep[lca(u,v)]*2;
  }
};
//END CUT HERE

//INSERT ABOVE HERE
char buf[256];
signed solve(){
  int n;
  scanf("%d",&n);
  using P = pair<int, int>;
  vector<vector<P> > G(n);
  LevelAncestor la(n);
  for(int i=1;i<n;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    a--;b--;
    la.add_edge(a,b);
    G[a].emplace_back(b,c);
    G[b].emplace_back(a,c);
  }
  la.build();

  vector<Int> dep(n,0);
  {
    queue<P> q;
    q.emplace(0,-1);
    while(!q.empty()){
      int v,p;
      tie(v,p)=q.front();q.pop();
      for(auto e:G[v]){
        int u,c;
        tie(u,c)=e;
        if(u==p) continue;
        dep[u]=dep[v]+c;
        q.emplace(u,v);
      }
    }
  }
  
  while(scanf("%s",buf)){
    string s(buf);
    if(s=="DONE"s) break;
    if(s=="DIST"s){
      int a,b;
      scanf("%d %d",&a,&b);
      a--;b--;
      printf("%lld\n",dep[a]+dep[b]-2*dep[la.lca(a,b)]);
    }
    if(s=="KTH"s){
      int a,b,k;
      scanf("%d %d %d",&a,&b,&k);
      a--;b--;k--;
      int l=la.lca(a,b);
      int x=la.distance(a,l),y=la.distance(l,b);
      assert(0<=k&&k<=x+y);
      printf("%d\n",(k<=x?la.up(a,k):la.up(b,x+y-k))+1);
    }
  }
  return 0;
}

signed SPOJ_QTREE2(){
  int t;
  scanf("%d",&t);
  for(int i=0;i<t;i++) solve();
  return 0;
}
/*
  verified on 2018/08/25
  https://www.spoj.com/problems/QTREE2/ 
*/

signed main(){
  SPOJ_QTREE2();
  return 0;
}
