---
title: Heavy Light Decomposition
documentation_of: ./tree/heavylightdecomposition.cpp
---

## できること

HL分解では、木（あるいは森 ）上のパスを $O(\log N)$ 個に分割することができます。
分割後のパスに対して操作を行った後にマージし直すことで、操作を高速に行うことができます。

HL分解を使えるかどうかの条件は、載せるデータ構造（セグ木、BIT）等のみに依存します。
つまり、ある単純な（一直線に並んでいるような）要素列に対しての問題が $O(X)$ で解けるなら、
それが木の上のパスになった場合でも $O(X \log N)$ で解くことができます。

## つかいかた
頂点属性のクエリの場合は `for_each()` 、辺属性のクエリの場合は `for_each_edge()` で処理します

演算が可換でない場合は `w = lca(u, v)` として、`for_each(w, u)` と `for_each_edge(w, v)` の結果を合成すればよいです


### 解説記事
[Easiest HLD with subtree queries](https://codeforces.com/blog/entry/53170)

古い [Heavy-Light Decomposition](https://beet-aizu.hatenablog.com/entry/2017/12/12/235950)
