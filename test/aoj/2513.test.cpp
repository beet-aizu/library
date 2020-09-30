// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2513

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../matching/bimatch.cpp"
#undef call_from_test

signed main(){
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
