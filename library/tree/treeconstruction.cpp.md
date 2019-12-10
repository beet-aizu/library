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


# :warning: tree/treeconstruction.cpp
<a href="../../index.html">Back to top page</a>

* category: tree
* <a href="{{ site.github.repository_url }}/blob/master/tree/treeconstruction.cpp">View this file on GitHub</a> (Last commit date: 2018-10-22 18:52:44 +0900)




## Code
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE
vector <int> treeconstruction(vector <int> d) {
  const int MAX = 111;
  vector<int> res,NG;
  int n=d.size();
  int m=0;
  int t[MAX]={};
  queue<int> q[MAX];
  for(int i=0;i<n;i++){
    t[d[i]]++;
    q[d[i]].push(i);
    m=max(m,d[i]);
  }
  bool f=1;
  for(int i=0;i<(m+1)/2;i++) f&=t[m-i]>=2;
  if(m%2) f&=t[m/2+1]==2;
  else f&=t[m/2]==1;
  for(int i=0;i<n;i++){
    if(m%2) f&=d[i]>=m/2+1;
    else f&=d[i]>=m/2;
  }
  if(!f) return NG;
    
  bool used[MAX]={};
  int b[MAX][2]={};

  if(m%2){
    for(int i=0;i<=m/2;i++){
      b[m-i][0]=q[m-i].front();q[m-i].pop();
      b[m-i][1]=q[m-i].front();q[m-i].pop();
      used[b[m-i][0]]=1;
      used[b[m-i][1]]=1;
      if(i){
        res.push_back(b[m-i+1][0]);
        res.push_back(b[m-i][0]);
        res.push_back(b[m-i+1][1]);
        res.push_back(b[m-i][1]);
      }
      if(i==m/2){
        res.push_back(b[m-i][0]);
        res.push_back(b[m-i][1]);
      }
    }
    for(int i=0;i<n;i++){
      if(used[i]) continue;
      res.push_back(i);
      res.push_back(b[d[i]-1][0]);
    }
  }else{
    for(int i=0;i<m/2;i++){
      b[m-i][0]=q[m-i].front();q[m-i].pop();
      b[m-i][1]=q[m-i].front();q[m-i].pop();
      used[b[m-i][0]]=1;
      used[b[m-i][1]]=1;
      if(i){
        res.push_back(b[m-i+1][0]);
        res.push_back(b[m-i][0]);
        res.push_back(b[m-i+1][1]);
        res.push_back(b[m-i][1]);
      }
    }
    b[m/2][0]=q[m/2].front();q[m/2].pop();
    used[b[m/2][0]]=1;
    res.push_back(b[m/2+1][0]);
    res.push_back(b[m/2][0]);
    res.push_back(b[m/2+1][1]);
    res.push_back(b[m/2][0]);
      
    for(int i=0;i<n;i++){
      if(used[i]) continue;
      res.push_back(i);
      res.push_back(b[d[i]-1][0]);
    }
  }
  return res;
}
//END CUT HERE
int main(){
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

