---
title: Binary Indexed Tree
documentation_of: ./datastructure/binaryindexedtree.cpp
---

## できること
- `sum(i)`
-- $\sum_{j<i} v_j$ を求める
- `add(i,a)`
-- $v_i := v_i + w$ とする
- `lower_bound(w)`
-- $v_i \geq 0$ の仮定のもと、$\min \lbrace i \mid \rm{sum}(i) \ge w \rbrace$ を求める

## verify 用問題一覧
- lower_bound
-- [AOJ 0343](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0343)
