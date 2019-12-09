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


[Back to top page](../../index.html)



## Required
* :heavy_check_mark: [algorithm/mo.cpp](../algorithm/mo.cpp.html)
* :heavy_check_mark: [convolution/arbitrarymodconvolution.cpp](../convolution/arbitrarymodconvolution.cpp.html)
* :heavy_check_mark: [convolution/arbitrarymodconvolution_with_garner.cpp](../convolution/arbitrarymodconvolution_with_garner.cpp.html)
* :warning: [convolution/fastwalshhadamardtransform.cpp](../convolution/fastwalshhadamardtransform.cpp.html)
* :heavy_check_mark: [datastructure/binaryindexedtree.cpp](../datastructure/binaryindexedtree.cpp.html)
* :heavy_check_mark: [datastructure/slidingwindowaggregation.cpp](../datastructure/slidingwindowaggregation.cpp.html)
* :heavy_check_mark: [flow/negativeedge.cpp](../flow/negativeedge.cpp.html)
* :heavy_check_mark: [graph/lowlink.cpp](../graph/lowlink.cpp.html)
* :warning: [graph/voronoiminimumspanningtree.cpp](../graph/voronoiminimumspanningtree.cpp.html)
* :heavy_check_mark: [linearalgebra/squarematrix.cpp](../linearalgebra/squarematrix.cpp.html)
* :heavy_check_mark: [linkcuttree/path.cpp](../linkcuttree/path.cpp.html)
* :heavy_check_mark: [linkcuttree/subtree.cpp](../linkcuttree/subtree.cpp.html)
* :heavy_check_mark: [mod/log.cpp](../mod/log.cpp.html)
* :heavy_check_mark: [mod/order.cpp](../mod/order.cpp.html)
* :heavy_check_mark: [polynomial/formalpowerseries.cpp](../polynomial/formalpowerseries.cpp.html)
* :heavy_check_mark: [string/ahocorasick.cpp](../string/ahocorasick.cpp.html)
* :heavy_check_mark: [string/longestcommonprefix.cpp](../string/longestcommonprefix.cpp.html)
* :heavy_check_mark: [string/palindromictree.cpp](../string/palindromictree.cpp.html)
* :heavy_check_mark: [tree/eulertourforedge.cpp](../tree/eulertourforedge.cpp.html)
* :heavy_check_mark: [tree/eulertourforvertex.cpp](../tree/eulertourforvertex.cpp.html)


## Verified
* :heavy_check_mark: [test/aoj/0109.test.cpp](../../verify/test/aoj/0109.test.cpp.html)
* :heavy_check_mark: [test/aoj/0314.test.cpp](../../verify/test/aoj/0314.test.cpp.html)
* :heavy_check_mark: [test/aoj/0367.linkcuttree.test.cpp](../../verify/test/aoj/0367.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/0403.test.cpp](../../verify/test/aoj/0403.test.cpp.html)
* :heavy_check_mark: [test/aoj/0415.test.cpp](../../verify/test/aoj/0415.test.cpp.html)
* :heavy_check_mark: [test/aoj/0423.test.cpp](../../verify/test/aoj/0423.test.cpp.html)
* :heavy_check_mark: [test/aoj/0424.test.cpp](../../verify/test/aoj/0424.test.cpp.html)
* :heavy_check_mark: [test/aoj/0425.test.cpp](../../verify/test/aoj/0425.test.cpp.html)
* :heavy_check_mark: [test/aoj/1312.test.cpp](../../verify/test/aoj/1312.test.cpp.html)
* :heavy_check_mark: [test/aoj/1338.test.cpp](../../verify/test/aoj/1338.test.cpp.html)
* :heavy_check_mark: [test/aoj/1579.test.cpp](../../verify/test/aoj/1579.test.cpp.html)
* :heavy_check_mark: [test/aoj/1595.linkcuttree.test.cpp](../../verify/test/aoj/1595.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/1595.test.cpp](../../verify/test/aoj/1595.test.cpp.html)
* :heavy_check_mark: [test/aoj/1599.test.cpp](../../verify/test/aoj/1599.test.cpp.html)
* :heavy_check_mark: [test/aoj/2212.test.cpp](../../verify/test/aoj/2212.test.cpp.html)
* :heavy_check_mark: [test/aoj/2292.test.cpp](../../verify/test/aoj/2292.test.cpp.html)
* :heavy_check_mark: [test/aoj/2309.tarjan.test.cpp](../../verify/test/aoj/2309.tarjan.test.cpp.html)
* :heavy_check_mark: [test/aoj/2309.test.cpp](../../verify/test/aoj/2309.test.cpp.html)
* :heavy_check_mark: [test/aoj/2313.test.cpp](../../verify/test/aoj/2313.test.cpp.html)
* :heavy_check_mark: [test/aoj/2359.test.cpp](../../verify/test/aoj/2359.test.cpp.html)
* :heavy_check_mark: [test/aoj/2444.test.cpp](../../verify/test/aoj/2444.test.cpp.html)
* :heavy_check_mark: [test/aoj/2450.linkcuttree.test.cpp](../../verify/test/aoj/2450.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/2488.test.cpp](../../verify/test/aoj/2488.test.cpp.html)
* :heavy_check_mark: [test/aoj/2603.test.cpp](../../verify/test/aoj/2603.test.cpp.html)
* :heavy_check_mark: [test/aoj/2674.count.test.cpp](../../verify/test/aoj/2674.count.test.cpp.html)
* :heavy_check_mark: [test/aoj/2674.test.cpp](../../verify/test/aoj/2674.test.cpp.html)
* :heavy_check_mark: [test/aoj/2711.test.cpp](../../verify/test/aoj/2711.test.cpp.html)
* :heavy_check_mark: [test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp](../../verify/test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp.html)
* :heavy_check_mark: [test/aoj/2725.test.cpp](../../verify/test/aoj/2725.test.cpp.html)
* :heavy_check_mark: [test/aoj/2842.2D_BIT.test.cpp](../../verify/test/aoj/2842.2D_BIT.test.cpp.html)
* :heavy_check_mark: [test/aoj/2872.test.cpp](../../verify/test/aoj/2872.test.cpp.html)
* :heavy_check_mark: [test/aoj/2890.test.cpp](../../verify/test/aoj/2890.test.cpp.html)
* :heavy_check_mark: [test/aoj/2970.test.cpp](../../verify/test/aoj/2970.test.cpp.html)
* :heavy_check_mark: [test/aoj/2975.test.cpp](../../verify/test/aoj/2975.test.cpp.html)
* :heavy_check_mark: [test/aoj/2983.test.cpp](../../verify/test/aoj/2983.test.cpp.html)
* :heavy_check_mark: [test/aoj/2985.garner.test.cpp](../../verify/test/aoj/2985.garner.test.cpp.html)
* :heavy_check_mark: [test/aoj/2985.test.cpp](../../verify/test/aoj/2985.test.cpp.html)
* :heavy_check_mark: [test/aoj/3033.test.cpp](../../verify/test/aoj/3033.test.cpp.html)
* :heavy_check_mark: [test/aoj/3035.test.cpp](../../verify/test/aoj/3035.test.cpp.html)
* :heavy_check_mark: [test/aoj/3047.test.cpp](../../verify/test/aoj/3047.test.cpp.html)
* :heavy_check_mark: [test/aoj/3069.lichao.test.cpp](../../verify/test/aoj/3069.lichao.test.cpp.html)
* :heavy_check_mark: [test/aoj/3069.test.cpp](../../verify/test/aoj/3069.test.cpp.html)
* :heavy_check_mark: [test/aoj/3073.test.cpp](../../verify/test/aoj/3073.test.cpp.html)
* :heavy_check_mark: [test/aoj/ALDS1_14_C.test.cpp](../../verify/test/aoj/ALDS1_14_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_3_B.test.cpp](../../verify/test/aoj/DPL_3_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_1_A.quickfind.test.cpp](../../verify/test/aoj/DSL_1_A.quickfind.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_A.bbst.test.cpp](../../verify/test/aoj/DSL_2_A.bbst.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_A.test.cpp](../../verify/test/aoj/DSL_2_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_B.binarytrie.test.cpp](../../verify/test/aoj/DSL_2_B.binarytrie.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_B.test.cpp](../../verify/test/aoj/DSL_2_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_D.bbst.test.cpp](../../verify/test/aoj/DSL_2_D.bbst.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_D.test.cpp](../../verify/test/aoj/DSL_2_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_E.bbst.test.cpp](../../verify/test/aoj/DSL_2_E.bbst.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_E.test.cpp](../../verify/test/aoj/DSL_2_E.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_F.bbst.test.cpp](../../verify/test/aoj/DSL_2_F.bbst.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_F.test.cpp](../../verify/test/aoj/DSL_2_F.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_G.bbst.test.cpp](../../verify/test/aoj/DSL_2_G.bbst.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_G.test.cpp](../../verify/test/aoj/DSL_2_G.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_H.bbst.test.cpp](../../verify/test/aoj/DSL_2_H.bbst.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_H.test.cpp](../../verify/test/aoj/DSL_2_H.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_I.bbst.test.cpp](../../verify/test/aoj/DSL_2_I.bbst.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_I.test.cpp](../../verify/test/aoj/DSL_2_I.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_3_D.cartesiantree.test.cpp](../../verify/test/aoj/DSL_3_D.cartesiantree.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_3_D.disjointsparsetable.test.cpp](../../verify/test/aoj/DSL_3_D.disjointsparsetable.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp](../../verify/test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_3_D.sparsetable.test.cpp](../../verify/test/aoj/DSL_3_D.sparsetable.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_3_D.test.cpp](../../verify/test/aoj/DSL_3_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_1_A.test.cpp](../../verify/test/aoj/GRL_1_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_1_B.test.cpp](../../verify/test/aoj/GRL_1_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_2_B.tarjan.test.cpp](../../verify/test/aoj/GRL_2_B.tarjan.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_2_B.test.cpp](../../verify/test/aoj/GRL_2_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_4_A.test.cpp](../../verify/test/aoj/GRL_4_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_A.linkcuttree.test.cpp](../../verify/test/aoj/GRL_5_A.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_A.test.cpp](../../verify/test/aoj/GRL_5_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_C.lca.test.cpp](../../verify/test/aoj/GRL_5_C.lca.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_D.linkcuttree.test.cpp](../../verify/test/aoj/GRL_5_D.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_D.test.cpp](../../verify/test/aoj/GRL_5_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_E.linkcuttree.test.cpp](../../verify/test/aoj/GRL_5_E.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_6_A.fordfulkerson.test.cpp](../../verify/test/aoj/GRL_6_A.fordfulkerson.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_7_A.hopcroft_karp.test.cpp](../../verify/test/aoj/GRL_7_A.hopcroft_karp.test.cpp.html)
* :heavy_check_mark: [test/aoj/NTL_1_A.test.cpp](../../verify/test/aoj/NTL_1_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/NTL_1_B.test.cpp](../../verify/test/aoj/NTL_1_B.test.cpp.html)
* :heavy_check_mark: [test/yosupo/bernoulli_number.test.cpp](../../verify/test/yosupo/bernoulli_number.test.cpp.html)
* :heavy_check_mark: [test/yosupo/bipartitematching.test.cpp](../../verify/test/yosupo/bipartitematching.test.cpp.html)
* :heavy_check_mark: [test/yosupo/convolution_mod.test.cpp](../../verify/test/yosupo/convolution_mod.test.cpp.html)
* :heavy_check_mark: [test/yosupo/discrete_logarithm_mod.test.cpp](../../verify/test/yosupo/discrete_logarithm_mod.test.cpp.html)
* :heavy_check_mark: [test/yosupo/exp_of_formal_power_series.test.cpp](../../verify/test/yosupo/exp_of_formal_power_series.test.cpp.html)
* :heavy_check_mark: [test/yosupo/inv_of_formal_power_series.test.cpp](../../verify/test/yosupo/inv_of_formal_power_series.test.cpp.html)
* :heavy_check_mark: [test/yosupo/lca.test.cpp](../../verify/test/yosupo/lca.test.cpp.html)
* :heavy_check_mark: [test/yosupo/log_of_formal_power_series.test.cpp](../../verify/test/yosupo/log_of_formal_power_series.test.cpp.html)
* :heavy_check_mark: [test/yosupo/matrix_det.test.cpp](../../verify/test/yosupo/matrix_det.test.cpp.html)
* :heavy_check_mark: [test/yosupo/maximum_independent_set.test.cpp](../../verify/test/yosupo/maximum_independent_set.test.cpp.html)
* :heavy_check_mark: [test/yosupo/number_of_substrings.test.cpp](../../verify/test/yosupo/number_of_substrings.test.cpp.html)
* :heavy_check_mark: [test/yosupo/partition_function.test.cpp](../../verify/test/yosupo/partition_function.test.cpp.html)
* :heavy_check_mark: [test/yosupo/point_add_range_sum.test.cpp](../../verify/test/yosupo/point_add_range_sum.test.cpp.html)
* :heavy_check_mark: [test/yosupo/point_set_range_composite.test.cpp](../../verify/test/yosupo/point_set_range_composite.test.cpp.html)
* :heavy_check_mark: [test/yosupo/rectangle_sum.test.cpp](../../verify/test/yosupo/rectangle_sum.test.cpp.html)
* :heavy_check_mark: [test/yosupo/scc.test.cpp](../../verify/test/yosupo/scc.test.cpp.html)
* :heavy_check_mark: [test/yosupo/sqrt_mod.test.cpp](../../verify/test/yosupo/sqrt_mod.test.cpp.html)
* :heavy_check_mark: [test/yosupo/staticrmq.disjointsparsetable.test.cpp](../../verify/test/yosupo/staticrmq.disjointsparsetable.test.cpp.html)
* :heavy_check_mark: [test/yosupo/staticrmq.sparsetable.test.cpp](../../verify/test/yosupo/staticrmq.sparsetable.test.cpp.html)
* :heavy_check_mark: [test/yosupo/suffixarray.test.cpp](../../verify/test/yosupo/suffixarray.test.cpp.html)
* :heavy_check_mark: [test/yosupo/unionfind.test.cpp](../../verify/test/yosupo/unionfind.test.cpp.html)
* :heavy_check_mark: [test/yosupo/vertex_add_path_sum.test.cpp](../../verify/test/yosupo/vertex_add_path_sum.test.cpp.html)
* :heavy_check_mark: [test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp](../../verify/test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/yosupo/vertex_add_subtree_sum.test.cpp](../../verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html)
* :heavy_check_mark: [test/yosupo/zalgorithm.test.cpp](../../verify/test/yosupo/zalgorithm.test.cpp.html)


## Code
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
using Int = long long;
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

[Back to top page](../../index.html)

