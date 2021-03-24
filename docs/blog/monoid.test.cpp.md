---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: '#line 1 "docs/blog/monoid.test.cpp"

    // verification-helper: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A

    #include <cstdio>

    signed main(){printf("Hello World\n");}

    '
  code: '// verification-helper: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A

    #include <cstdio>

    signed main(){printf("Hello World\n");}

    '
  dependsOn: []
  isVerificationFile: true
  path: docs/blog/monoid.test.cpp
  requiredBy: []
  timestamp: '2021-03-24 17:35:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: docs/blog/monoid.test.cpp
layout: document
title: "\u30E2\u30CE\u30A4\u30C9\u307E\u3068\u3081"
---

## 有名なやつ
和、積、min, max, gcd, lcm
やるだけなのでコードは省略

## 行列
正方行列ライブラリ：
[https://github.com/beet-aizu/library/blob/master/linearalgebra/squarematrix.cpp:embed:cite]


[https://atcoder.jp/contests/ddcc2019-final/tasks/ddcc2019_final_d:embed:cite]
部分列の数え上げ
グラフ上の経路数の数え上げは行列累乗に帰着される
一点更新　区間積　うし木
```cpp
  using M = SquareMatrix<unsigned, 6>;
  auto f=[](M a,M b){return a*b;};
```
[https://atcoder.jp/contests/ddcc2019-final/submissions/4558460:title]



[https://atcoder.jp/contests/yahoo-procon2019-final/tasks/yahoo_procon2019_final_d:embed:cite]

DAGの数え上げはDPでできる　DPをセグ木で高速化
 [tex: (T, f) ] をモノイドとすると、 [tex: g(a,b) = f(b,a) ] としたとき [tex: (T, g) ] もまたモノイドになる。
∵結合則だけ示せばよい　 [tex: g(a,g(b,c)) = g(a,f(c,b)) = f(f(c,b),a) = f(c,f(b,a)) = f(c,g(a,b)) = g(g(a,b),c)) ]
一点更新　区間積　うし木
```cpp
  using M = Mint<Int>;
  using MM = SquareMatrix<M, 2>;
  auto f=[&](MM a,MM b){return b*a;};
```
[https://atcoder.jp/contests/yahoo-procon2019-final/submissions/4558478:title]


## ペアにする
[https://atcoder.jp/contests/arc067/tasks/arc067_d:embed:cite]
indexとペアにする
区間max うし木
```cpp
    using P = pair<Int, Int>;
    auto f=[&](P a,P b){return max(a,b);};
```
[https://atcoder.jp/contests/arc067/submissions/4403664:title]



[http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3035:embed:cite]
個数とペアにする
区間min/max、区間加算　遅延セグ木
```cpp

  struct T{
    Int w,x,y,z;
    T(Int w,Int x,Int y,Int z):w(w),x(x),y(y),z(z){}
  };

  auto f=[](T a,T b){
           Int cw=min(a.w,b.w);
           Int cx=(a.w==b.w?a.x+b.x:(a.w<b.w?a.x:b.x));
           Int cy=max(a.y,b.y);
           Int cz=(a.y==b.y?a.z+b.z:(a.y>b.y?a.z:b.z));
           return T(cw,cx,cy,cz);
         };
  auto g=[](T a,Int b){
           return T(a.w+b,a.x,a.y+b,a.z);
         };
  auto h=[](Int a,Int b){return a+b;};
```
[http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3401776#1:title]



[https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_f:embed:cite]
ノードが生きているかとペアにする
区間chmin、区間min　遅延セグ木
```cpp
  struct T{
    Int val,alive;
    T(Int val,Int alive):val(val),alive(alive){}
  };
  auto f=[](T a,T b){
           return T(min(a.val,b.val),a.alive|b.alive);
         };
  auto g=[](T a,Int b){
           return T(a.alive?min(a.val,b):a.val,a.alive);
         };
  auto h=[](Int a,Int b){return min(a,b);};
```
[https://atcoder.jp/contests/nikkei2019-final/submissions/4322642:title]




## 関数の合成
関数 [tex: f,g ] に対し、 [tex: g(f(x)) = (g \circ f) (x) ]  がうまく計算できるとき、セグ木に載せられる場合がある。

[https://atcoder.jp/contests/arc008/tasks/arc008_4:embed:cite]
一次関数の合成は一次関数になる　うし木
```cpp
  using P = pair<D, D>;
  auto f=[](P a,P b){
           return P(a.first*b.first,b.first*a.second+b.second);
         };
```
[https://atcoder.jp/contests/arc008/submissions/4557658:title]
[https://judge.yosupo.jp/problem/point_set_range_composite:embed:cite]



[https://beta.atcoder.jp/contests/jag2018summer-day2/tasks/jag2018summer_day2_i:embed:cite]
正の整数bと非負整数a,cに対し、 [tex: f(x) = \left \lfloor \cfrac{x+a}{b} \right \rfloor +c]  は合成できる。
bをある程度の大きさで制限する必要あり。　遅延セグ木
```cpp
  using ll = long long;
  struct T{
    ll cur,fst;
    T(ll cur,ll fst):cur(cur),fst(fst){}
  };
  struct E{
    ll r,a,b,c;
    E(ll r,ll a,ll b,ll c):r(r),a(a),b(b),c(c){}
    bool operator==(const E &o) const{
      return r==o.r&&a==o.a&&b==o.b&&c==o.c;
    }
  };

  auto f=[](T a,T b){
           return T(max(a.cur,b.cur),max(a.fst,b.fst));
         };

  auto g=[](T a,E b){
           return T(((b.r?a.fst:a.cur)+b.a)/b.b+b.c,a.fst);
         };

  const ll LIM = 1e9;
  auto h=[](E a,E b){
           if(b.r) return b;
           E c(a.r,a.a+a.b*(a.c+b.a),a.b*b.b,0);
           c.c=c.a/c.b+b.c;
           c.a%=c.b;
           if(c.b>LIM){
             c.a=max(0LL,LIM-(c.b-c.a));
             c.b=LIM;
           }
           return c;
         };
```
[https://atcoder.jp/contests/jag2018summer-day2/submissions/4557801:title]



[https://beta.atcoder.jp/contests/yahoo-procon2017-qual/tasks/yahoo_procon2017_qual_d:embed:cite]
[tex: f(x) = \max(x+a, b) ] は合成できる。
pekempeyさんの解説：
[https://pekempey.hatenablog.com/entry/2017/03/07/023127:embed:cite]
```cpp
  using P = pair<ll, ll>;
  auto f=[](P a,P b){
           return P(a.first+b.first,max(a.second+b.first,b.second));
         };
```
[https://atcoder.jp/contests/yahoo-procon2017-qual/submissions/4558139:title]



[https://atcoder.jp/contests/arc017/tasks/arc017_4:embed:cite]
区間加算区間GCDはそのままでは処理できない。
階差を取ると区間加算が2箇所の加算になり、元のGCDは階差のGCDと先頭要素のGCDを利用して求められる。

```cpp
  auto f=[](int a,int b){
           if(a==0&&b==0) return 0;
           if(a==0||b==0) return a?a:b;
           return gcd(abs(a),abs(b));
         };
```
[https://atcoder.jp/contests/arc017/submissions/4558398:title]


[https://yukicoder.me/problems/no/1099:embed:cite]
区間二乗和
二乗和、線形和、個数を持ってえい
```cpp
  using T = tuple<Int, Int, Int>;
  auto f=[](T a,T b){
    auto [ax,ay,az]=a;
    auto [bx,by,bz]=b;
    return T(ax+bx,ay+by,az+bz);
  };
  auto g=[](T a,Int b){
    auto [ax,ay,az]=a;
    return T(ax+2*ay*b+az*b*b,ay+az*b,az);
  };
  auto h=[](Int a,Int b){return a+b;};
```
[https://yukicoder.me/submissions/503055:embed:cite]


TODO：書く


[http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0355:embed:cite]
RollingHash


[http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0390:embed:cite]
二面体群



[https://yukicoder.me/problems/no/749:embed:cite]
upd, mul, add, fib


[https://yukicoder.me/problems/no/619:embed:cite]
足し算と掛け算




[https://uva.onlinejudge.org/external/131/p13192.pdf]
最大値の期待値




[https://beta.atcoder.jp/contests/jag2018summer-day2/tasks/jag2018summer_day2_j:embed:cite]
区間反転、区間最小





[https://yukicoder.me/problems/no/776:embed:cite]
連続する部分列の和の最大値


[https://codeforces.com/contest/446/problem/C:embed:cite]
フィボナッチ数を区間に足す、区間和


## HL分解との組み合わせ

[https://yukicoder.me/problems/no/650:embed:cite]
一点更新　区間積　うし木
```cpp
  using M = Mint<int>;
  using MM = SquareMatrix<M, 2>;
  auto f=[](MM a,MM b){return a*b;};
```
[https://yukicoder.me/submissions/320087:title]




[http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0367:embed:cite]
辺属性のモノイドは端点を持っておく

[http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2450:embed:cite]

みんな大好き Do use Segment Tree　連続する部分列の和の最大値
