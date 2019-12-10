---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: tools/fastio.cpp
* category: tools


<a href="../../index.html">Back to top page</a>



## Required
* :warning: <a href="../algorithm/mo.cpp.html">algorithm/mo.cpp</a>
* :warning: <a href="../convolution/arbitrarymodconvolution.cpp.html">convolution/arbitrarymodconvolution.cpp</a>
* :heavy_check_mark: <a href="../convolution/arbitrarymodconvolution_with_garner.cpp.html">convolution/arbitrarymodconvolution_with_garner.cpp</a>
* :warning: <a href="../convolution/fastwalshhadamardtransform.cpp.html">convolution/fastwalshhadamardtransform.cpp</a>
* :heavy_check_mark: <a href="../datastructure/binaryindexedtree.cpp.html">datastructure/binaryindexedtree.cpp</a>
* :heavy_check_mark: <a href="../datastructure/slidingwindowaggregation.cpp.html">datastructure/slidingwindowaggregation.cpp</a>
* :warning: <a href="../flow/negativeedge.cpp.html">flow/negativeedge.cpp</a>
* :warning: <a href="../graph/lowlink.cpp.html">graph/lowlink.cpp</a>
* :warning: <a href="../graph/voronoiminimumspanningtree.cpp.html">graph/voronoiminimumspanningtree.cpp</a>
* :heavy_check_mark: <a href="../linearalgebra/squarematrix.cpp.html">linearalgebra/squarematrix.cpp</a>
* :warning: <a href="../linkcuttree/path.cpp.html">linkcuttree/path.cpp</a>
* :heavy_check_mark: <a href="../linkcuttree/subtree.cpp.html">linkcuttree/subtree.cpp</a>
* :heavy_check_mark: <a href="../mod/log.cpp.html">mod/log.cpp</a>
* :heavy_check_mark: <a href="../mod/order.cpp.html">mod/order.cpp</a>
* :warning: <a href="../polynomial/formalpowerseries.cpp.html">polynomial/formalpowerseries.cpp</a>
* :heavy_check_mark: <a href="../string/ahocorasick.cpp.html">string/ahocorasick.cpp</a>
* :heavy_check_mark: <a href="../string/longestcommonprefix.cpp.html">string/longestcommonprefix.cpp</a>
* :warning: <a href="../string/palindromictree.cpp.html">string/palindromictree.cpp</a>
* :heavy_check_mark: <a href="../tree/eulertourforedge.cpp.html">tree/eulertourforedge.cpp</a>
* :heavy_check_mark: <a href="../tree/eulertourforvertex.cpp.html">tree/eulertourforvertex.cpp</a>


## Verified
* :heavy_check_mark: <a href="../../verify/test/aoj/0109.test.cpp.html">test/aoj/0109.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/0314.test.cpp.html">test/aoj/0314.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/0367.linkcuttree.test.cpp.html">test/aoj/0367.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0403.test.cpp.html">test/aoj/0403.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/0415.test.cpp.html">test/aoj/0415.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0423.test.cpp.html">test/aoj/0423.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0424.test.cpp.html">test/aoj/0424.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/0425.test.cpp.html">test/aoj/0425.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0563.test.cpp.html">test/aoj/0563.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/1312.test.cpp.html">test/aoj/1312.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1338.test.cpp.html">test/aoj/1338.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/1579.test.cpp.html">test/aoj/1579.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1595.linkcuttree.test.cpp.html">test/aoj/1595.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1595.test.cpp.html">test/aoj/1595.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1599.test.cpp.html">test/aoj/1599.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1607.test.cpp.html">test/aoj/1607.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2187.test.cpp.html">test/aoj/2187.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2212.test.cpp.html">test/aoj/2212.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2292.test.cpp.html">test/aoj/2292.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2294.test.cpp.html">test/aoj/2294.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2309.tarjan.test.cpp.html">test/aoj/2309.tarjan.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2309.test.cpp.html">test/aoj/2309.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2313.test.cpp.html">test/aoj/2313.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2359.test.cpp.html">test/aoj/2359.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2444.test.cpp.html">test/aoj/2444.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2450.linkcuttree.test.cpp.html">test/aoj/2450.linkcuttree.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2488.test.cpp.html">test/aoj/2488.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2603.test.cpp.html">test/aoj/2603.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2646.test.cpp.html">test/aoj/2646.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2674.count.test.cpp.html">test/aoj/2674.count.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2674.test.cpp.html">test/aoj/2674.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2711.test.cpp.html">test/aoj/2711.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp.html">test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2725.test.cpp.html">test/aoj/2725.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2842.2D_BIT.test.cpp.html">test/aoj/2842.2D_BIT.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2872.test.cpp.html">test/aoj/2872.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2890.test.cpp.html">test/aoj/2890.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2970.test.cpp.html">test/aoj/2970.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2975.test.cpp.html">test/aoj/2975.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2983.test.cpp.html">test/aoj/2983.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2985.garner.test.cpp.html">test/aoj/2985.garner.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/2985.test.cpp.html">test/aoj/2985.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/3033.test.cpp.html">test/aoj/3033.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3035.test.cpp.html">test/aoj/3035.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/3047.test.cpp.html">test/aoj/3047.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/3053.test.cpp.html">test/aoj/3053.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3069.lichao.test.cpp.html">test/aoj/3069.lichao.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/3069.test.cpp.html">test/aoj/3069.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3073.test.cpp.html">test/aoj/3073.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_14_C.test.cpp.html">test/aoj/ALDS1_14_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_3_B.test.cpp.html">test/aoj/DPL_3_B.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/DSL_1_A.quickfind.test.cpp.html">test/aoj/DSL_1_A.quickfind.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_1_B.test.cpp.html">test/aoj/DSL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_A.bbst.test.cpp.html">test/aoj/DSL_2_A.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_A.test.cpp.html">test/aoj/DSL_2_A.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/DSL_2_B.binarytrie.test.cpp.html">test/aoj/DSL_2_B.binarytrie.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_B.test.cpp.html">test/aoj/DSL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_D.bbst.test.cpp.html">test/aoj/DSL_2_D.bbst.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/DSL_2_D.test.cpp.html">test/aoj/DSL_2_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_E.bbst.test.cpp.html">test/aoj/DSL_2_E.bbst.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/DSL_2_E.test.cpp.html">test/aoj/DSL_2_E.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/DSL_2_F.bbst.test.cpp.html">test/aoj/DSL_2_F.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_F.test.cpp.html">test/aoj/DSL_2_F.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/DSL_2_G.bbst.test.cpp.html">test/aoj/DSL_2_G.bbst.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/DSL_2_G.test.cpp.html">test/aoj/DSL_2_G.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_H.bbst.test.cpp.html">test/aoj/DSL_2_H.bbst.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/DSL_2_H.test.cpp.html">test/aoj/DSL_2_H.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/DSL_2_I.bbst.test.cpp.html">test/aoj/DSL_2_I.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_I.test.cpp.html">test/aoj/DSL_2_I.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/DSL_3_D.cartesiantree.test.cpp.html">test/aoj/DSL_3_D.cartesiantree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.disjointsparsetable.test.cpp.html">test/aoj/DSL_3_D.disjointsparsetable.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp.html">test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.sparsetable.test.cpp.html">test/aoj/DSL_3_D.sparsetable.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.test.cpp.html">test/aoj/DSL_3_D.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/GRL_1_A.test.cpp.html">test/aoj/GRL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_B.test.cpp.html">test/aoj/GRL_1_B.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/GRL_2_B.tarjan.test.cpp.html">test/aoj/GRL_2_B.tarjan.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_2_B.test.cpp.html">test/aoj/GRL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_4_A.test.cpp.html">test/aoj/GRL_4_A.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/GRL_5_A.linkcuttree.test.cpp.html">test/aoj/GRL_5_A.linkcuttree.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/GRL_5_A.test.cpp.html">test/aoj/GRL_5_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_C.lca.test.cpp.html">test/aoj/GRL_5_C.lca.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/GRL_5_D.linkcuttree.test.cpp.html">test/aoj/GRL_5_D.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_D.test.cpp.html">test/aoj/GRL_5_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_E.linkcuttree.test.cpp.html">test/aoj/GRL_5_E.linkcuttree.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/GRL_6_A.fordfulkerson.test.cpp.html">test/aoj/GRL_6_A.fordfulkerson.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/GRL_7_A.hopcroft_karp.test.cpp.html">test/aoj/GRL_7_A.hopcroft_karp.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/NTL_1_A.test.cpp.html">test/aoj/NTL_1_A.test.cpp</a>
* :warning: <a href="../../verify/test/aoj/NTL_1_B.test.cpp.html">test/aoj/NTL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/bernoulli_number.test.cpp.html">test/yosupo/bernoulli_number.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/bipartitematching.test.cpp.html">test/yosupo/bipartitematching.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/convolution_mod.test.cpp.html">test/yosupo/convolution_mod.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/discrete_logarithm_mod.test.cpp.html">test/yosupo/discrete_logarithm_mod.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/exp_of_formal_power_series.test.cpp.html">test/yosupo/exp_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/inv_of_formal_power_series.test.cpp.html">test/yosupo/inv_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/lca.test.cpp.html">test/yosupo/lca.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/log_of_formal_power_series.test.cpp.html">test/yosupo/log_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/matrix_det.test.cpp.html">test/yosupo/matrix_det.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/maximum_independent_set.test.cpp.html">test/yosupo/maximum_independent_set.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/number_of_substrings.test.cpp.html">test/yosupo/number_of_substrings.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/partition_function.test.cpp.html">test/yosupo/partition_function.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/point_add_range_sum.test.cpp.html">test/yosupo/point_add_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/point_set_range_composite.test.cpp.html">test/yosupo/point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/rectangle_sum.test.cpp.html">test/yosupo/rectangle_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/scc.test.cpp.html">test/yosupo/scc.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/sqrt_mod.test.cpp.html">test/yosupo/sqrt_mod.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/staticrmq.disjointsparsetable.test.cpp.html">test/yosupo/staticrmq.disjointsparsetable.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/staticrmq.sparsetable.test.cpp.html">test/yosupo/staticrmq.sparsetable.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/suffixarray.test.cpp.html">test/yosupo/suffixarray.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/unionfind.test.cpp.html">test/yosupo/unionfind.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_path_sum.test.cpp.html">test/yosupo/vertex_add_path_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp.html">test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html">test/yosupo/vertex_add_subtree_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/zalgorithm.test.cpp.html">test/yosupo/zalgorithm.test.cpp</a>


## Code
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

