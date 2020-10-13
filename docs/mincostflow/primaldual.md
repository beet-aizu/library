---
title: 最小費用流
documentation_of: //mincostflow/primaldual.cpp
---

## 解説記事
[最小費用流の双対について](https://beet-aizu.hatenablog.com/entry/2019/10/20/150649)

## 計算量
流量を $F$ として、$O(F E \log V)$

## ポテンシャルの初期化
コストが負の辺が存在する場合、 `build` の際に `init` を渡すことでポテンシャルの初期化の仕方を指定できる。

一般の場合には bellman-ford を用いて $O(VE)$ で初期化する。

DAG の場合には DP を用いて $O(E)$ で初期化することもできる。[例](https://beet-aizu.github.io/library/test/aoj/2290.test.cpp)

コストが負の辺の最大流量の和が小さい場合は、[最小費用流の負辺除去](https://beet-aizu.github.io/library/mincostflow/negativeedge.cpp) を使用する。