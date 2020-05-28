#define PROBLEM "https://yukicoder.me/problems/3961"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tree/centroid.cpp"
#include "../../tools/fixpoint.cpp"
#undef call_from_test

template<typename V>
void compress(V& v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using ll = long long;

  int n,k;
  cin>>n>>k;

  using P = pair<int, int>;
  vector< map<int, int> > col(n);
  Centroid G(n);
  for(int i=1;i<n;i++){
    int x,y,z;
    cin>>x>>y>>z;
    x--;y--;z--;
    G.add_edge(x,y);
    col[x][y]=z;
    col[y][x]=z;
  }

  queue<int> que;
  que.emplace(G.build(0)[0]);

  ll ans=0;
  vector<int> cnt(k,0),uku(k,0);
  vector<P> ps(n),vp(n);

  while(!que.empty()){
    int r=que.front();que.pop();
    auto calc=
      [&](P p,int q)->P{
        assert(~p.first);
        if(p.first==q||p.second==q) return p;
        if(p.second==-1) return minmax({p.first,q});
        return P(-1,-1);
      };

    vp.clear();
    for(int t:G.G[r]){
      if(!G.alive(t)) continue;

      MFP([&](auto dfs,int v,int p,P st)->void{
        ps[v]=st;
        if(st.first<0) return;
        for(int u:G.G[v]){
          if(u==p) continue;
          if(!G.alive(u)) continue;
          dfs(u,v,calc(st,col[u][v]));
        }
        if(st.second!=-1)
          vp.emplace_back(st);
      })(t,r,P(col[r][t],-1));
    }
    compress(vp);
    auto idx=[&](P p){return lower_bound(vp.begin(),vp.end(),p)-vp.begin();};

    vector<int> num(vp.size());
    int all=0;
    for(int t:G.G[r]){
      if(!G.alive(t)) continue;

      // count
      MFP([&](auto dfs,int v,int p)->void{
        P st=ps[v];
        if(st.first<0) return;
        for(int u:G.G[v]){
          if(u==p) continue;
          if(!G.alive(u)) continue;
          dfs(u,v);
        }
        if(st.second==-1){
          ans+=all-cnt[st.first];
          ans+=uku[st.first];
        }else{
          ans+=1;
          ans+=cnt[st.first];
          ans+=cnt[st.second];
          ans+=num[idx(st)];
        }
      })(t,r);

      // paint
      MFP([&](auto dfs,int v,int p)->void{
        P st=ps[v];
        if(st.first<0) return;
        for(int u:G.G[v]){
          if(u==p) continue;
          if(!G.alive(u)) continue;
          dfs(u,v);
        }
        if(st.second==-1){
          cnt[st.first]++;
          all++;
        }else{
          num[idx(st)]++;
          uku[st.first]++;
          uku[st.second]++;
        }
      })(t,r);
    }

    for(int t:G.G[r]){
      if(!G.alive(t)) continue;

      // clear
      MFP([&](auto dfs,int v,int p)->void{
        P st=ps[v];
        if(st.first<0) return;
        for(int u:G.G[v]){
          if(u==p) continue;
          if(!G.alive(u)) continue;
          dfs(u,v);
        }
        if(st.second==-1){
          cnt[st.first]--;
        }else{
          uku[st.first]--;
          uku[st.second]--;
        }
      })(t,r);
    }

    G.disable(r);
    for(int u:G.G[r])
      if(G.alive(u))
        que.emplace(G.build(u)[0]);
  }

  cout<<ans<<endl;
  return 0;
}
