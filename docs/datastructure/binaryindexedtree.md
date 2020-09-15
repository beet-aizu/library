---
title: Binary Indexed Tree
documentation_of: ./datastructure/binaryindexedtree.cpp
---

## できること
- `add(i,a)`
-- $v_i := v_i + a$ とする
- `query(l,r)`
-- $\sum_{l \leq i \lt r} v_i$ を求める
- `lower_bound(w)`
-- $v_i \geq 0$ の仮定のもと、$\min (\lbrace i \mid \rm{sum}(i) \ge w \rbrace)$ を求める
- `upper_bound(w)`
-- $v_i \geq 0$ の仮定のもと、$\min (\lbrace i \mid \rm{sum}(i) \gt w \rbrace)$ を求める

## verify 用問題一覧
- lower_bound
-- [AOJ 0343](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0343)
