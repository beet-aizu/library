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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/ITP1_11_D.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/ITP1_11_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-17 20:42:16+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/tools/dice.cpp.html">tools/dice.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/dice.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  vector<Die> ds(n);
  for(int j=0;j<n;j++)
    for(int i=0;i<6;i++)
      cin>>ds[j].s[i];

  bool ff=true;
  for(int i=0;i<n;i++){
    auto vd=makeDice(ds[i]);
    for(int j=0;j<i;j++){
      bool f=false;
      for(auto d:vd) f|=d==ds[j];
      ff&=!f;
    }
  }

  cout<<(ff?"Yes":"No")<<endl;
  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/ITP1_11_D.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#line 1 "tools/dice.cpp"

#line 3 "tools/dice.cpp"
using namespace std;
#endif
//BEGIN CUT HERE
struct Die{
  int s[6];
  int &top()   {return s[0];}
  int &south() {return s[1];}
  int &east()  {return s[2];}
  int &west()  {return s[3];}
  int &north() {return s[4];}
  int &bottom(){return s[5];}
  void roll(char c){
    //the view from above
    // N
    //W E
    // S
    string b("EWNSRL");
    int v[6][4]={{0,3,5,2},
                 {0,2,5,3},
                 {0,1,5,4},
                 {0,4,5,1},
                 {1,2,4,3},
                 {1,3,4,2}};
    for(int k=0;k<6;k++){
      if(b[k]!=c) continue;
      int t=s[v[k][0]];
      s[v[k][0]]=s[v[k][1]];
      s[v[k][1]]=s[v[k][2]];
      s[v[k][2]]=s[v[k][3]];
      s[v[k][3]]=t;
    }
  }
  using ll = long long;
  ll hash(){
    ll res=0;
    for(int i=0;i<6;i++) res=res*256+s[i];
    return res;
  }
  bool operator==(const Die &d) const{
    for(int i=0;i<6;i++) if(s[i]!=d.s[i]) return 0;
    return 1;
  }
};

vector<Die> makeDice(Die d){
  vector<Die> res;
  for(int i=0;i<6;i++){
    Die t(d);
    if(i==1) t.roll('N');
    if(i==2) t.roll('S');
    if(i==3) t.roll('S'),t.roll('S');
    if(i==4) t.roll('L');
    if(i==5) t.roll('R');
    for(int k=0;k<4;k++){
      res.push_back(t);
      t.roll('E');
    }
  }
  return res;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
#line 8 "test/aoj/ITP1_11_D.test.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  vector<Die> ds(n);
  for(int j=0;j<n;j++)
    for(int i=0;i<6;i++)
      cin>>ds[j].s[i];

  bool ff=true;
  for(int i=0;i<n;i++){
    auto vd=makeDice(ds[i]);
    for(int j=0;j<i;j++){
      bool f=false;
      for(auto d:vd) f|=d==ds[j];
      ff&=!f;
    }
  }

  cout<<(ff?"Yes":"No")<<endl;
  return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

