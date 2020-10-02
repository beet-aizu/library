---
title: Suffix Array
documentation_of: //string/suffixarray.cpp
---

## できること
- `sa[i]` : $S$ の末尾辞の中で $i$ 番目に小さいものの位置
- `rev[i]` : $S[i:\|S\|]$ が辞書順で何番目か


## 計算量
$O(\|S\| \log \|S\|)$

## 注意
- 番兵として末尾に `$` を挿入している

- $S$ に記号が含まれている場合は注意が必要

- `sa[0]` は常に $\|S\|$ になる

## 解説記事
[ Suffix Array in O(N * logN) and LCP in O(N) ](https://sites.google.com/site/indy256/algo/suffix_array)