---
title: Wavelet Matrix
documentation_of: ./datastructure/waveletmatrix.cpp
---

## できること
- `rank(v,k)`
-- $\lbrack 0, k)$ に含まれる $v$ の個数を求める
- `select(v,k)`
-- $k$ 番目の $v$ の位置を求める
- `quantile(l,r,k)`
-- $\lbrack l, r)$ に含まれる要素の中で $k$ 番目に大きいものを求める
- `rquantile(l,r,k)`
-- $\lbrack l, r)$ に含まれる要素の中で $k$ 番目に小さいものを求める
- `rangefreq(l,r,d,u)`
-- $\vert \lbrace i \mid i \in \lbrack l, r), x _ i \in \lbrack d, u) \rbrace \vert$ を求める
- `succ(l,r,v)`
-- $\lbrack l, r)$ に含まれる要素の中で $v$ の次に大きいものを求める
- `pred(l,r,v)`
-- $\lbrack l, r)$ に含まれる要素の中で $v$ の次に小さいものを求める
