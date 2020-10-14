// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1613

#include <bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../io/single.cpp"
#include "../../tree/ahu.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  auto construct=[&](int h,int w){
    auto st=read<string>(h);
    st.emplace(st.begin(),string(w,'.'));
    st.emplace(st.end(),string(w,'.'));
    for(auto &s:st) s='.'+s+'.';
    h=st.size();w=st[0].size();

    int dy[]={0,0,1,-1,1,1,-1,-1};
    int dx[]={1,-1,0,0,1,-1,1,-1};
    auto in=[&](int y,int x){return 0<=y and y<h and 0<=x and x<w;};

    int n=0;
    vector blg(h,vector(w,-1));
    auto bfs=[&](int y,int x){
      int dir=(1+(st[y][x]=='#'))*4;
      using P = pair<int, int>;
      queue<P> que;
      auto push=[&](int ny,int nx){
        if(~blg[ny][nx]) return;
        blg[ny][nx]=n;
        que.emplace(ny,nx);
      };
      push(y,x);
      while(!que.empty()){
        auto[cy,cx]=que.front();que.pop();
        for(int k=0;k<dir;k++){
          int ny=cy+dy[k],nx=cx+dx[k];
          if(in(ny,nx) and st[cy][cx]==st[ny][nx]) push(ny,nx);
        }
      }
      n++;
    };

    for(int i=0;i<h;i++)
      for(int j=0;j<w;j++)
        if(blg[i][j]<0) bfs(i,j);

    vector<set<int>> S(n);
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        for(int k=0;k<4;k++){
          int ni=i+dy[k],nj=j+dx[k];
          if(in(ni,nj) and blg[i][j]!=blg[ni][nj])
            S[blg[i][j]].emplace(blg[ni][nj]);
        }
      }
    }

    AHU G(n);
    for(int i=0;i<n;i++)
      for(int j:S[i])
        if(i<j) G.add_edge(i,j);
    return G.build();
  };

  int h,w;
  while(cin>>h>>w,h||w){
    auto T1=construct(h,w);
    cin>>h>>w;
    auto T2=construct(h,w);
    cout<<(T1==T2?"yes":"no")<<'\n';
  }
  return 0;
}
