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


# :warning: datastructure/absolutesum.cpp
* category: datastructure


[Back to top page](../../index.html)



## Code
```cpp
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
template<typename T>
struct AbsoluteSum{
  multiset<T> lp,rp;
  T sum;
  AbsoluteSum():sum(0){}
  T insert(T x){
    if(lp.empty()){
      lp.emplace(x);
      rp.emplace(x);
      return T(0);
    }
    auto p=interval();
    lp.emplace(x);
    rp.emplace(x);
    if(p.first<=x&&x<=p.second) return T(0);
    if(*lp.rbegin()>*rp.begin()){
      T a=*lp.rbegin();
      T b=*rp.begin();
      lp.erase(lp.find(a));
      rp.erase(rp.find(b));
      rp.emplace(a);
      lp.emplace(b);
    }
    T res=min(abs(p.first-x),abs(p.second-x));
    sum+=res;
    return res;
  }

  T erase(T x){
    assert(lp.count(x)+rp.count(x)>=2);
    if(lp.count(x)&&rp.count(x)){
      lp.erase(lp.find(x));
      rp.erase(rp.find(x));
      return T(0);
    }
    if(lp.count(x)){
      lp.erase(lp.find(x));
      lp.erase(lp.find(x));
      lp.emplace(*rp.begin());
      rp.erase(rp.begin());
    }else{
      rp.erase(rp.find(x));
      rp.erase(rp.find(x));
      rp.emplace(*lp.rbegin());
      lp.erase(lp.rbegin().base());
    }
    auto p=interval();
    if(p.first<=x&&x<=p.second) return T(0);
    T res=min(abs(p.first-x),abs(p.second-x));
    sum-=res;
    return res;
  }

  pair<T, T> interval(){
    assert(!lp.empty());
    return make_pair(*lp.rbegin(),*rp.begin());
  }

  T value(){return sum;}
};
//END CUT HERE
//INSERT ABOVE HERE
signed ABC127_F(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int q;
  cin>>q;
  using ll = long long;
  AbsoluteSum<ll> as;
  ll sum=0;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    if(t==1){
      ll a,b;
      cin>>a>>b;
      as.insert(a);
      sum+=b;
    }
    if(t==2){
      cout<<as.interval().first<<" "<<sum+as.value()<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
/*
  verified on 2019/06/19
  https://atcoder.jp/contests/abc127/tasks/abc127_f
*/

signed YUKI_837(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  using ll = long long;

  int n;
  cin>>n;
  vector<ll> ys(n);
  for(int i=0;i<n;i++) cin>>ys[i];
  sort(ys.begin(),ys.end());
  if(ys.front()==ys.back()){
    cout<<1<<endl;
    return 0;
  }

  AbsoluteSum<ll> as;
  vector<ll> dp(n,0);
  for(int i=0;i<n;i++){
    as.insert(ys[i]);
    dp[i]+=as.value();
  }
  for(int i=0;i<n;i++){
    as.erase(ys[i]);
    dp[i]+=as.value();
  }

  cout<<*min_element(dp.begin(),dp.end())<<endl;
  return 0;
}
/*
  verified on 2019/06/19
  https://yukicoder.me/problems/no/837
*/

signed main(){
  //ABC127_F();
  //YUKI_837();
  return 0;
}

```

[Back to top page](../../index.html)

