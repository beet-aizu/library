#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct BiMatch{
  int n,time;
  vector<vector<int>> G;
  vector<int> match,used,dead;

  BiMatch(){}
  BiMatch(int n):n(n),time(0),G(n),
                 match(n,-1),used(n,-1),dead(n,0){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  int dfs(int v){
    used[v]=time;
    for(int u:G[v]){
      if(dead[u]) continue;
      int w=match[u];
      if((w<0) || (used[w]<time && !dead[w] && dfs(w))){
        match[v]=u;
        match[u]=v;
        return 1;
      }
    }
    return 0;
  }

  int build(){
    int res=0;
    for(int v=0;v<n;v++){
      if(dead[v]) continue;
      if(match[v]<0){
        time++;
        res+=dfs(v);
      }
    }
    return res;
  }

  int disable(int v){
    assert(!dead[v]);
    int u=match[v];
    if(~u) match[u]=-1;
    match[v]=-1;
    dead[v]=1;
    time++;
    return ~u?dfs(u)-1:0;
  }

  int enable(int v){
    assert(dead[v]);
    dead[v]=0;
    time++;
    return dfs(v);
  }
};
//END CUT HERE

signed GRL_7_A(){
  int X,Y,E;
  cin>>X>>Y>>E;
  BiMatch bm(X+Y);
  for(int i=0;i<E;i++){
    int x,y;
    cin>>x>>y;
    bm.add_edge(x,X+y);
  }
  cout<<bm.build()<<endl;
  return 0;
}
/*
  verified on 2019/06/16
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A&lang=jp
*/

signed AOJ_2513(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while(cin>>n,n){
    vector<vector<int>> xss;
    vector<vector<int>> yss;
    for(int i=0;i<n;i++){
      vector<int> xs(3),ys(3);
      for(int j=0;j<3;j++) cin>>xs[j]>>ys[j];
      xss.emplace_back(xs);
      yss.emplace_back(ys);
    }

    const int T = 16;
    int dx[T][4]={{ 0,-1, 1, 0},
                  { 0, 1, 1, 2},
                  { 0, 0, 1,-1},
                  { 0,-1,-1,-2},

                  { 0, 1, 2, 3},
                  { 0,-2,-1, 1},

                  {-1, 0, 1, 2},
                  {-3,-2,-1, 0},

                  { 0, 0,-1,-1},
                  { 1, 1, 0, 0},

                  { 0, 0, 1, 1},
                  {-1,-1, 0, 0},

                  {-1, 0, 0, 1},
                  {-2,-1,-1, 0},

                  { 1, 0, 0,-1},
                  { 2, 1, 1, 0},

    };
    int dy[T][4]={{ 0, 0, 0,-1},
                  { 0, 1, 0, 0},
                  { 0,-1,-1,-1},
                  { 0, 0, 1, 0},

                  { 0, 0, 0, 0},
                  { 0, 0, 0, 0},

                  { 0, 0, 0, 0},
                  { 0, 0, 0, 0},

                  { 0,-1,-1,-2},
                  { 1, 0, 0,-1},

                  { 0,-1,-1,-2},
                  { 1, 0, 0,-1},

                  { 0, 0,-1,-1},
                  { 1, 1, 0, 0},

                  { 0, 0,-1,-1},
                  { 1, 1, 0, 0},

    };

    using P = pair<int, int>;

    int m=n;
    map<P, int> mp;
    vector<set<int>> G(n);

    for(int i=0;i<n;i++){
      auto &xs=xss[i];
      auto &ys=yss[i];
      for(int j=0;j<3;j++)
        mp[P(xs[j],ys[j])]=m++;
    }

    vector<set<int> > H(n);
    for(int i=0;i<n;i++){
      auto &xs=xss[i];
      auto &ys=yss[i];
      set<P> tmp;
      for(int j=0;j<3;j++)
        tmp.emplace(xs[j],ys[j]);

      int sy=((xs[0]+ys[0])%2==0?1:-1);

      for(int j=0;j<T;j++){
        set<P> res;
        for(int k=0;k<4;k++)
          res.emplace(xs[0]+dx[j][k],ys[0]+sy*dy[j][k]);

        int cnt=0;
        P uku;
        for(auto p:res){
          if(tmp.count(p)){
            cnt++;
            continue;
          }
          uku=p;
        }
        if(cnt!=3) continue;
        if(!mp.count(uku)) mp[uku]=m++;
        G[i].emplace(mp[uku]);
      }
    }

    BiMatch bm(m);
    for(int i=0;i<n;i++)
      for(int j:G[i])
        bm.add_edge(i,j);

    for(int i=0;i<n;i++){
      auto &xs=xss[i];
      auto &ys=yss[i];
      for(int j=0;j<3;j++)
        bm.disable(mp[P(xs[j],ys[j])]);
    }

    int res=bm.build();

    if(res==n){
      cout<<"Valid"<<"\n";
      continue;
    }

    if(res+4<n){
      cout<<"Invalid"<<"\n";
      continue;
    }

    set<int> ans;
    for(int i=0;i<n;i++){
      auto &xs=xss[i];
      auto &ys=yss[i];
      res+=bm.disable(i);

      for(int j=0;j<3;j++)
        res+=bm.enable(mp[P(xs[j],ys[j])]);

      if(res+1==n) ans.emplace(i);

      for(int j=0;j<3;j++)
        res+=bm.disable(mp[P(xs[j],ys[j])]);

      res+=bm.enable(i);
    }

    if(ans.empty()){
      cout<<"Invalid"<<"\n";
    }else{
      cout<<"Remove"<<"\n";
      for(int i:ans) cout<<i+1<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/16
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2513&lang=jp
*/

signed main(){
  //GRL_7_A();
  //AOJ_2513();
  return 0;
}
