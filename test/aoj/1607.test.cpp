#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1607"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/chminmax.cpp"
#include "../../tools/compress.cpp"
#include "../../datastructure/radixheap.cpp"
#undef call_from_test

#ifdef SANITIZE
#define IGNORE
#endif

const int BS = 8, BS2 = BS * 2;
const int msk = (1<<BS)-1;
const int MAX = 12 * (1<<BS) * (1<<BS);
int dist[MAX];
bool hole[MAX];
long long add[(1<<BS) * (1<<BS)];
long long dp[(1<<BS)][(1<<BS)];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while(cin>>n,n){
    int m,k,r;
    cin>>m>>k>>r;
    vector<int> x(n),y(n),z(n);
    for(int i=0;i<n;i++) cin>>x[i]>>y[i]>>z[i];
    vector<int> u1(m),v1(m),u2(m),v2(m),w(m);
    for(int i=0;i<m;i++) cin>>u1[i]>>v1[i]>>u2[i]>>v2[i]>>w[i];

    vector<int> vx(x),vy(y);
    for(int p=0;p<m;p++){
      vx.emplace_back(u1[p]);
      vx.emplace_back(u2[p]);
      vy.emplace_back(v1[p]);
      vy.emplace_back(v2[p]);
      if(w[p]!=k) continue;
      if(u1[p]-1>=1) vx.emplace_back(u1[p]-1);
      if(u2[p]+1<=r) vx.emplace_back(u2[p]+1);
      if(v1[p]-1>=1) vy.emplace_back(v1[p]-1);
      if(v2[p]+1<=r) vy.emplace_back(v2[p]+1);
    }

    vx=compress(vx);
    vy=compress(vy);
    auto mx=dict(vx);
    auto my=dict(vy);

    // kokokara y yuusen
    auto idx=[&](int cy,int cx,int f){return (f<<BS2)|(cy<<BS)|cx;};

    memset(hole,0,sizeof(hole));
    for(int p=0;p<m;p++)
      for(int i=my[v1[p]];i<=my[v2[p]];i++)
        for(int j=mx[u1[p]];j<=mx[u2[p]];j++)
          hole[idx(i,j,w[p])]=1;

    int sy=vy.size(),sx=vx.size();

    auto dijkstra=
      [&](int a)->void{
        vector<int> wy,wx;
        for(int p=0;p<m;p++){
          if(w[p]<=z[a]) continue;
          wy.emplace_back(v1[p]);
          wy.emplace_back(v2[p]);
          wx.emplace_back(u1[p]);
          wx.emplace_back(u2[p]);
        }
        wy.emplace_back(y[a]);
        wx.emplace_back(x[a]);
        wy=compress(wy);
        wx=compress(wx);
        auto zy=dict(wy);
        auto zx=dict(wx);
        int ty=zy.size(),tx=zx.size();

        vector<pair<int, int> > vs;
        {
          for(int i=0;i<MAX;i++) dist[i]=INT_MAX;
          RadixHeap<int, int> q;
          {
            int v=idx(zy[y[a]],zx[x[a]],z[a]);
            dist[v]=0;
            q.emplace(dist[v],v);
          }

          while(!q.empty()){
            auto p=q.pop();
            int v=p.second;
            if(dist[v]<p.first) continue;

            int f=v>>BS2,i=(v>>BS)&msk,j=v&msk;
            int ai=my[wy[i]],aj=mx[wx[j]];
            if(f==k){
              vs.emplace_back((ai<<BS)|aj,dist[v]);
              continue;
            }

            auto push=
              [&](int ni,int nj,int nf){
                int u=idx(ni,nj,nf);
                int c=abs(wy[ni]-wy[i])+abs(wx[nj]-wx[j]);

                if(dist[u]>dist[v]+c){
                  dist[u]=dist[v]+c;
                  q.emplace(dist[u],u);
                }
              };

            if(hole[idx(ai,aj,f+1)]){
              push(i,j,f+1);
              continue;
            }

            if(i+1<ty) push(i+1,j,f);
            if(i-1>=0) push(i-1,j,f);
            if(j+1<tx) push(i,j+1,f);
            if(j-1>=0) push(i,j-1,f);
          }
        }
        {
          for(int i=0;i<(sy<<BS);i++) add[i]=INT_MAX;
          RadixHeap<int, int> q;
          for(auto p:vs){
            int v=p.first,d=p.second;
            add[v]=d;
            q.emplace(add[v],v);
          }

          while(!q.empty()){
            auto p=q.pop();
            int v=p.second;
            if(add[v]<p.first) continue;

            int i=v>>BS,j=v&msk;
            auto push=
              [&](int ni,int nj){
                int u=(ni<<BS)|nj;
                int c=abs(vy[ni]-vy[i])+abs(vx[nj]-vx[j]);
                if(add[u]>add[v]+c){
                  add[u]=add[v]+c;
                  q.emplace(add[u],u);
                }
              };

            if(i+1<sy) push(i+1,j);
            if(i-1>=0) push(i-1,j);
            if(j+1<sx) push(i,j+1);
            if(j-1>=0) push(i,j-1);
          }
        }
      };

    memset(dp,0,sizeof(dp));
    for(int p=0;p<n;p++){
      dijkstra(p);
      for(int i=0;i<sy;i++)
        for(int j=0;j<sx;j++)
          dp[i][j]+=add[(i<<BS)|j];
    }

    long long ans=1e18;
    for(int i=0;i<sy;i++)
      for(int j=0;j<sx;j++)
        if(!hole[idx(i,j,k)]) chmin(ans,dp[i][j]);

    for(int p=0;p<n;p++) ans+=(k-z[p])*100;
    cout<<ans<<endl;
  }
  return 0;
}
