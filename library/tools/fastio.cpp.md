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


# :heavy_check_mark: tools/fastio.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4a931512ce65bdc9ca6808adf92d8783">tools</a>
* <a href="{{ site.github.repository_url }}/blob/master/tools/fastio.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 23:51:01+09:00




## Required by

* :heavy_check_mark: <a href="../algorithm/mo.cpp.html">algorithm/mo.cpp</a>
* :heavy_check_mark: <a href="../algorithm/monotoneminima.cpp.html">algorithm/monotoneminima.cpp</a>
* :warning: <a href="../convolution/fastwalshhadamardtransform.cpp.html">convolution/fastwalshhadamardtransform.cpp</a>
* :heavy_check_mark: <a href="../datastructure/binaryindexedtree.cpp.html">datastructure/binaryindexedtree.cpp</a>
* :heavy_check_mark: <a href="../datastructure/slidingwindowaggregation.cpp.html">datastructure/slidingwindowaggregation.cpp</a>
* :heavy_check_mark: <a href="../flow/negativeedge.cpp.html">flow/negativeedge.cpp</a>
* :heavy_check_mark: <a href="../graph/lowlink.cpp.html">graph/lowlink.cpp</a>
* :heavy_check_mark: <a href="../graph/nicetree.cpp.html">graph/nicetree.cpp</a>
* :warning: <a href="../graph/voronoiminimumspanningtree.cpp.html">graph/voronoiminimumspanningtree.cpp</a>
* :heavy_check_mark: <a href="../linearalgebra/binarymatrix.cpp.html">linearalgebra/binarymatrix.cpp</a>
* :heavy_check_mark: <a href="../linearalgebra/squarematrix.cpp.html">linearalgebra/squarematrix.cpp</a>
* :heavy_check_mark: <a href="../linkcuttree/subtree.cpp.html">linkcuttree/subtree.cpp</a>
* :heavy_check_mark: <a href="../mod/order.cpp.html">mod/order.cpp</a>
* :heavy_check_mark: <a href="../polynomial/berlekampmassey.cpp.html">polynomial/berlekampmassey.cpp</a>
* :heavy_check_mark: <a href="../polynomial/formalpowerseries.cpp.html">polynomial/formalpowerseries.cpp</a>
* :heavy_check_mark: <a href="../segtree/cht/lichao.cpp.html">segtree/cht/lichao.cpp</a>
* :heavy_check_mark: <a href="../tree/diameterforedge.cpp.html">tree/diameterforedge.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0109.test.cpp.html">test/aoj/0109.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0294.test.cpp.html">test/aoj/0294.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0314.test.cpp.html">test/aoj/0314.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0367.linkcuttree.test.cpp.html">test/aoj/0367.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0367.test.cpp.html">test/aoj/0367.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0391.test.cpp.html">test/aoj/0391.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0403.test.cpp.html">test/aoj/0403.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0415.test.cpp.html">test/aoj/0415.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0423.test.cpp.html">test/aoj/0423.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0424.test.cpp.html">test/aoj/0424.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0425.test.cpp.html">test/aoj/0425.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0558.test.cpp.html">test/aoj/0558.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/0563.test.cpp.html">test/aoj/0563.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1069.test.cpp.html">test/aoj/1069.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1312.test.cpp.html">test/aoj/1312.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1328.test.cpp.html">test/aoj/1328.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1338.test.cpp.html">test/aoj/1338.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1508.test.cpp.html">test/aoj/1508.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1549.test.cpp.html">test/aoj/1549.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1579.test.cpp.html">test/aoj/1579.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1595.linkcuttree.test.cpp.html">test/aoj/1595.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1595.test.cpp.html">test/aoj/1595.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1599.test.cpp.html">test/aoj/1599.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/1607.test.cpp.html">test/aoj/1607.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2187.test.cpp.html">test/aoj/2187.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2212.test.cpp.html">test/aoj/2212.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2286.test.cpp.html">test/aoj/2286.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2292.test.cpp.html">test/aoj/2292.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2294.test.cpp.html">test/aoj/2294.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2309.tarjan.test.cpp.html">test/aoj/2309.tarjan.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2309.test.cpp.html">test/aoj/2309.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2313.test.cpp.html">test/aoj/2313.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2328.test.cpp.html">test/aoj/2328.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2359.test.cpp.html">test/aoj/2359.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2405.test.cpp.html">test/aoj/2405.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2415.knuthyao.test.cpp.html">test/aoj/2415.knuthyao.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2415.test.cpp.html">test/aoj/2415.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2444.test.cpp.html">test/aoj/2444.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2450.linkcuttree.test.cpp.html">test/aoj/2450.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2450.test.cpp.html">test/aoj/2450.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2488.test.cpp.html">test/aoj/2488.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2563.test.cpp.html">test/aoj/2563.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2603.test.cpp.html">test/aoj/2603.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2646.test.cpp.html">test/aoj/2646.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2667.test.cpp.html">test/aoj/2667.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2674.count.test.cpp.html">test/aoj/2674.count.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2674.test.cpp.html">test/aoj/2674.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2711.test.cpp.html">test/aoj/2711.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp.html">test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2725.test.cpp.html">test/aoj/2725.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2736.test.cpp.html">test/aoj/2736.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2842.2D_BIT.test.cpp.html">test/aoj/2842.2D_BIT.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2872.test.cpp.html">test/aoj/2872.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2890.test.cpp.html">test/aoj/2890.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2970.test.cpp.html">test/aoj/2970.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2975.test.cpp.html">test/aoj/2975.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2983.test.cpp.html">test/aoj/2983.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2985.garner.test.cpp.html">test/aoj/2985.garner.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/2985.test.cpp.html">test/aoj/2985.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3033.test.cpp.html">test/aoj/3033.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3035.test.cpp.html">test/aoj/3035.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3047.test.cpp.html">test/aoj/3047.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3053.test.cpp.html">test/aoj/3053.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3063.test.cpp.html">test/aoj/3063.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3069.lichao.test.cpp.html">test/aoj/3069.lichao.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3069.test.cpp.html">test/aoj/3069.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3073.test.cpp.html">test/aoj/3073.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3117.test.cpp.html">test/aoj/3117.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/3120.test.cpp.html">test/aoj/3120.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_14_C.test.cpp.html">test/aoj/ALDS1_14_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DPL_3_B.test.cpp.html">test/aoj/DPL_3_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_1_A.quickfind.test.cpp.html">test/aoj/DSL_1_A.quickfind.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_1_B.test.cpp.html">test/aoj/DSL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_A.bbst.test.cpp.html">test/aoj/DSL_2_A.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_A.test.cpp.html">test/aoj/DSL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_B.binarytrie.test.cpp.html">test/aoj/DSL_2_B.binarytrie.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_B.test.cpp.html">test/aoj/DSL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_C.test.cpp.html">test/aoj/DSL_2_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_D.bbst.test.cpp.html">test/aoj/DSL_2_D.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_D.test.cpp.html">test/aoj/DSL_2_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_E.bbst.test.cpp.html">test/aoj/DSL_2_E.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_E.test.cpp.html">test/aoj/DSL_2_E.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_F.bbst.test.cpp.html">test/aoj/DSL_2_F.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_F.test.cpp.html">test/aoj/DSL_2_F.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_G.bbst.test.cpp.html">test/aoj/DSL_2_G.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_G.test.cpp.html">test/aoj/DSL_2_G.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_H.bbst.test.cpp.html">test/aoj/DSL_2_H.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_H.test.cpp.html">test/aoj/DSL_2_H.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_I.bbst.test.cpp.html">test/aoj/DSL_2_I.bbst.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_I.test.cpp.html">test/aoj/DSL_2_I.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.cartesiantree.test.cpp.html">test/aoj/DSL_3_D.cartesiantree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.disjointsparsetable.test.cpp.html">test/aoj/DSL_3_D.disjointsparsetable.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp.html">test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.sparsetable.test.cpp.html">test/aoj/DSL_3_D.sparsetable.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_3_D.test.cpp.html">test/aoj/DSL_3_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_A.test.cpp.html">test/aoj/GRL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_B.test.cpp.html">test/aoj/GRL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_2_B.tarjan.test.cpp.html">test/aoj/GRL_2_B.tarjan.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_2_B.test.cpp.html">test/aoj/GRL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_4_A.test.cpp.html">test/aoj/GRL_4_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_A.linkcuttree.test.cpp.html">test/aoj/GRL_5_A.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_A.test.cpp.html">test/aoj/GRL_5_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_C.lca.test.cpp.html">test/aoj/GRL_5_C.lca.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_D.linkcuttree.test.cpp.html">test/aoj/GRL_5_D.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_D.test.cpp.html">test/aoj/GRL_5_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_E.linkcuttree.test.cpp.html">test/aoj/GRL_5_E.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_6_A.fordfulkerson.test.cpp.html">test/aoj/GRL_6_A.fordfulkerson.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_7_A.hopcroft_karp.test.cpp.html">test/aoj/GRL_7_A.hopcroft_karp.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/NTL_1_A.test.cpp.html">test/aoj/NTL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/NTL_1_B.test.cpp.html">test/aoj/NTL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/bernoulli_number.test.cpp.html">test/yosupo/bernoulli_number.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/bipartitematching.test.cpp.html">test/yosupo/bipartitematching.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/convolution_mod.test.cpp.html">test/yosupo/convolution_mod.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/convolution_mod_1000000007.garner.test.cpp.html">test/yosupo/convolution_mod_1000000007.garner.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/convolution_mod_1000000007.test.cpp.html">test/yosupo/convolution_mod_1000000007.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/discrete_logarithm_mod.test.cpp.html">test/yosupo/discrete_logarithm_mod.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/dominatortree.test.cpp.html">test/yosupo/dominatortree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp.html">test/yosupo/dynamic_tree_vertex_add_path_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp.html">test/yosupo/dynamic_tree_vertex_add_subtree_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/exp_of_formal_power_series.test.cpp.html">test/yosupo/exp_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/inv_of_formal_power_series.test.cpp.html">test/yosupo/inv_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/kth_root_integer.test.cpp.html">test/yosupo/kth_root_integer.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/lca.linkcuttree.test.cpp.html">test/yosupo/lca.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/lca.test.cpp.html">test/yosupo/lca.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/line_add_get_min.test.cpp.html">test/yosupo/line_add_get_min.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/log_of_formal_power_series.test.cpp.html">test/yosupo/log_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/matrix_det.test.cpp.html">test/yosupo/matrix_det.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/maximum_independent_set.test.cpp.html">test/yosupo/maximum_independent_set.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/montmort_number_mod.test.cpp.html">test/yosupo/montmort_number_mod.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/multipoint_evaluation.test.cpp.html">test/yosupo/multipoint_evaluation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/number_of_substrings.test.cpp.html">test/yosupo/number_of_substrings.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/partition_function.test.cpp.html">test/yosupo/partition_function.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/point_add_range_sum.test.cpp.html">test/yosupo/point_add_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/point_set_range_composite.test.cpp.html">test/yosupo/point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/polynomial_interpolation.test.cpp.html">test/yosupo/polynomial_interpolation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/queue_operate_all_composite.test.cpp.html">test/yosupo/queue_operate_all_composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/range_affine_range_sum.test.cpp.html">test/yosupo/range_affine_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/rectangle_sum.test.cpp.html">test/yosupo/rectangle_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/runenumerate.test.cpp.html">test/yosupo/runenumerate.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/scc.test.cpp.html">test/yosupo/scc.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/sqrt_mod.test.cpp.html">test/yosupo/sqrt_mod.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/sqrt_of_formal_power_series.test.cpp.html">test/yosupo/sqrt_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/staticrmq.disjointsparsetable.test.cpp.html">test/yosupo/staticrmq.disjointsparsetable.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/staticrmq.sparsetable.test.cpp.html">test/yosupo/staticrmq.sparsetable.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/suffixarray.test.cpp.html">test/yosupo/suffixarray.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/sum_of_floor_of_linear.test.cpp.html">test/yosupo/sum_of_floor_of_linear.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/tetration_mod.test.cpp.html">test/yosupo/tetration_mod.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/two_sat.test.cpp.html">test/yosupo/two_sat.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/unionfind.test.cpp.html">test/yosupo/unionfind.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_path_sum.test.cpp.html">test/yosupo/vertex_add_path_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp.html">test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html">test/yosupo/vertex_add_subtree_sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/zalgorithm.test.cpp.html">test/yosupo/zalgorithm.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/104.test.cpp.html">test/yukicoder/104.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1732.test.cpp.html">test/yukicoder/1732.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1923.test.cpp.html">test/yukicoder/1923.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1937.test.cpp.html">test/yukicoder/1937.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1948.test.cpp.html">test/yukicoder/1948.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1950.test.cpp.html">test/yukicoder/1950.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/1973.test.cpp.html">test/yukicoder/1973.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/2085.test.cpp.html">test/yukicoder/2085.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/2113.test.cpp.html">test/yukicoder/2113.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/2147.test.cpp.html">test/yukicoder/2147.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/22.test.cpp.html">test/yukicoder/22.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/222.test.cpp.html">test/yukicoder/222.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/2600.test.cpp.html">test/yukicoder/2600.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/2744.test.cpp.html">test/yukicoder/2744.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/3211.test.cpp.html">test/yukicoder/3211.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/3227.test.cpp.html">test/yukicoder/3227.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/399.test.cpp.html">test/yukicoder/399.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yukicoder/444.test.cpp.html">test/yukicoder/444.test.cpp</a>


## Code

<a id="unbundled"></a>
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

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: tools/fastio.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

