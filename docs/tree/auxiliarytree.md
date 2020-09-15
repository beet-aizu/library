---
title: Auxiliary Tree
documentation_of: ./tree/auxiliarytree.cpp
---

## できること
与えられた木の頂点の部分集合に関して、その頂点を全て含むような最小の木を構築する

## つかいかた
- `query(ws)`: 部分集合 `ws` の Aux Tree を破壊的に構築する（必要な頂点が `ws` に追加される）
- `clear(ws)`: `ws` から伸びている辺を削除する

## 計算量
部分集合のサイズを$k$として、$O(k \log k)$

Aux Treeの頂点数は $2k$ 以下になる


## 参考リンク
[LCAをベースに構築するAuxiliary Treeのメモ](https://smijake3.hatenablog.com/entry/2019/09/15/200200)