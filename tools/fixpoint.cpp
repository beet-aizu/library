#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
template<typename F>
struct FixPoint : F{
  FixPoint(F&& f):F(forward<F>(f)){}
  template<typename... Args>
  decltype(auto) operator()(Args&&... args) const{
    return F::operator()(*this,forward<Args>(args)...);
  }
};
template<typename F>
inline decltype(auto) MFP(F&& f){
  return FixPoint<F>{forward<F>(f)};
}
//END CUT HERE

//INSERT ABOVE HERE
signed main(){
  int h,w;
  cin>>h>>w;
  vector<string> st(h);
  for(int i=0;i<h;i++) cin>>st[i];

  vector<vector<int> > used(h,vector<int>(w,0));

  auto dfs=
    MFP([&](auto dfs,int y,int x)->void{
          used[y][x]=1;
          if(y  >0&&st[y-1][x]!='#'&&!used[y-1][x]) dfs(y-1,x);
          if(y+1<h&&st[y+1][x]!='#'&&!used[y+1][x]) dfs(y+1,x);
          if(x  >0&&st[y][x-1]!='#'&&!used[y][x-1]) dfs(y,x-1);
          if(x+1<w&&st[y][x+1]!='#'&&!used[y][x+1]) dfs(y,x+1);
        });

  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      if(st[i][j]=='s') dfs(i,j);

  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      if(st[i][j]=='g')
        cout<<(used[i][j]?"Yes":"No")<<endl;
  return 0;
}
/*
  https://atcoder.jp/contests/atc001/tasks/dfs_a
*/
