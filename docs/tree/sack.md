---
title: Sack (dsu on tree)
documentation_of: ../tree/sack.cpp
---

## できること
部分木に対するクエリを処理できる

unordered 系を使ったマージテクより定数倍が軽いことが多い

## つかいかた
以下のラムダ式を実装する
- `expand(v)` : `v` を追加したときの処理
- `shrink(v)` : `v` を削除したときの処理
- `query(k)` : `k` 番目のクエリに対する処理

## 計算量
頂点数を $N$ として、`expand`, `shrink` が $O(N \log N)$ 回呼び出される

## 注意
- `shrink(v)` を呼ぶときは全体が初期化されるので、 `expand(v)` で変更した値を全て初期値にしてもよい（直前の操作のロールバックができる必要はない）
- 頂点 `v` の追加削除の際に複数の処理を行う必要がある場合は、`v` の子としてダミーの頂点を追加するとよい


## 参考リンク
[[Tutorial] Sack (dsu on tree)](https://codeforces.com/blog/entry/44351)