---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: tools/bfs.cpp
<a href="../../index.html">Back to top page</a>

* category: tools
* <a href="{{ site.github.repository_url }}/blob/master/tools/bfs.cpp">View this file on GitHub</a>
    - Last commit date: 2018-09-26 22:54:03 +0900




## Code
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
vector<vector<int> > bfs(vector<string> &s,int sy,int sx,char wall,int dir){
  int h=s.size(),w=s.front().size();
  vector<vector<int> > dp(h,vector<int>(w,-1));
  using P = pair<int, int>;
  queue<P> q;

  dp[sy][sx]=0;
  q.emplace(sy,sx);
  
  int dy[]={1,-1,0,0,1,1,-1,-1};
  int dx[]={0,0,1,-1,1,-1,1,-1};
  auto in=[&](int y,int x){return 0<=y&&y<h&&0<=x&&x<w;};
  
  while(!q.empty()){
    int y,x;
    tie(y,x)=q.front();q.pop();
    for(int k=0;k<dir;k++){
      int ny=y+dy[k],nx=x+dx[k];
      if(!in(ny,nx)||s[ny][nx]==wall) continue;
      if(~dp[ny][nx]) continue;
      dp[ny][nx]=dp[y][x]+1;
      q.emplace(ny,nx);
    }
  }
  
  return dp;
}
//END CUT HERE
//INSERT ABOVE HERE
signed ABC088_D(){
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++) cin>>s[i];
  auto dp=bfs(s,0,0,'#',4);
  
  if(dp[h-1][w-1]<0){
    cout<<-1<<endl;
    return 0;
  }
  
  int cnt=0;
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cnt+=s[i][j]=='.';
  cout<<cnt-(dp[h-1][w-1]+1)<<endl;
  return 0;
}

/*
  verified on 2018/02/18
  https://beta.atcoder.jp/contests/abc088/tasks/abc088_d
*/

signed main(){
  ABC088_D();
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

