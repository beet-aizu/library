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


# :warning: polynomial/polynomial.cpp
<a href="../../index.html">Back to top page</a>

* category: polynomial
* <a href="{{ site.github.repository_url }}/blob/master/polynomial/polynomial.cpp">View this file on GitHub</a>
    - Last commit date: 2019-10-17 20:37:29 +0900




## Verified With
* :warning: <a href="../../verify/test/aoj/1293.test.cpp.html">test/aoj/1293.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
#endif
//BEGIN CUT HERE
struct Polynomial{
  using P = Polynomial;
  vector<int> co;
  Polynomial():co(1,1){}
  Polynomial(int s):co(s,0){}
  Polynomial(vector<int> co):co(co){}

  size_t size() const{
    return co.size();
  };

  void shrink(){
    while(co.size()>1u&&!co.back())
      co.pop_back();
  }

  void reduce(){
    int g=abs(co.back());
    if(!g) return;
    for(int c:co)
      if(c!=0) g=__gcd(g,abs(c));
    if(co.back()<0) g*=-1;
    for(int &c:co) c/=g;
  }

  void print(){
    shrink();
    reduce();
    int n=size(),flg=0;
    for(int i=n-1;i>0;i--){
      if(!co[i]) continue;
      flg=1;
      if(i!=n-1&&co[i]>0) cout<<"+";
      if(co[i]==-1) cout<<"-";
      else if(co[i]!=1) cout<<co[i];

      cout<<"x";
      if(i!=1) cout<<"^"<<i;
    }
    if(co[0]){
      if(flg&&co[0]>0) cout<<"+";
      cout<<co[0];
    }
    cout<<endl;
  }

  int operator[](int i) const{
    return co[i];
  }

  int &operator[](int i){
    return co[i];
  }

  P operator-() const{
    P res=*this;
    for(int &c:res.co) c*=-1;
    return res;
  }

  P operator+(const P &a) const{
    int n=size(),m=a.size();
    P res(max(n,m));
    for(int i=0;i<n;i++) res[i]+=co[i];
    for(int i=0;i<m;i++) res[i]+=a[i];
    return res;
  }
  P operator-(const P &a) const{return *this+(-a);};

  P operator*(const P &a) const{
    int n=size(),m=a.size();
    P res(n+m);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        res[i+j]+=co[i]*a[j];
    res.shrink();
    return res;
  }

  P pow(const P &a,int k) const{
    P res;
    for(int i=0;i<k;i++) res=res*a;
    return res;
  }

  pair<P, P> divide(const P &a) const{
    int n=size(),m=a.size(),s=n-m+1;
    if(s<0) return make_pair(P(1),*this);
    P div(s);
    P rest=*this;
    for(int i=0;i<s;i++){
      if(rest[n-(i+1)]%a[m-1]!=0)
        for(int &c:rest.co) c*=a[m-1];
      int d=rest[n-(i+1)]/a[m-1];
      div[s-(i+1)]=d;
      for(int j=m;j>0;j--) rest[n-(i+j)]-=a[m-j]*d;
    }
    return make_pair(div,rest);
  }

  P operator/(const P &a) const{return divide(a).first;};
  P operator%(const P &a) const{return divide(a).second;};
};

Polynomial gcd(Polynomial a,Polynomial b){
  a.shrink();a.reduce();
  b.shrink();b.reduce();
  if(a.size()<b.size()) swap(a,b);
  if(b.size()==1u&&!b[0]) return a;
  return gcd(b,a%b);
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

