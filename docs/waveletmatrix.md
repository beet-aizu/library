---
documentation_of: ./datastructure/waveletmatrix.cpp
---

## できること
- rank
-- $\lbrack 0, k)$ に含まれる $v$ の個数を求める
- select
-- $k$ 番目の $v$ の位置を求める
- quantile
-- $\lbrack l, r)$ に含まれる要素の中で $k$ 番目に大きいものを求める
- rquantile
-- $\lbrack l, r)$ に含まれる要素の中で $k$ 番目に小さいものを求める
- rangefreq
-- $\vert \lbrace i \mid i \in \lbrack l, r), x _ i \in \lbrack d, u) \rbrace \vert$ を求める
- succ
-- $\lbrack l, r)$ に含まれる要素の中で $v$ の次に大きいものを求める
- pred
-- $\lbrack l, r)$ に含まれる要素の中で $v$ の次に小さいものを求める

## verify 用問題一覧
- rank
-- 募集中
- select
-- 募集中
- quantile
-- [yukicoder 1732](https://yukicoder.me/problems/1732)
- rquantile
-- [Library-Checker Range Kth Smallest](https://judge.yosupo.jp/problem/range_kth_smallest)
- rangefreq
-- [yukicoder 1937](https://yukicoder.me/problems/1937)
- succ, pred
-- [AOJ 1549](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549)
