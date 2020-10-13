---
title: Longest Common Prefix
documentation_of: //string/longestcommonprefix.cpp
---

## できること
- `query(a,b)`
-- $S$ の末尾辞の中で $a$ 番目に小さいものと $b$ 番目に小さいもののLCPを求める
- `lcp(a,b)`
-- $S[a:\|S\|]$ と $S[b:\|S\|]$ のLCPを求める

## 計算量
構築: $O(\|S\| \log \|S\|)$

クエリ: $O(\log \|S\|)$

## 注意
- $a \neq b$ を仮定している
