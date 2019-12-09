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
<script type="text/javascript" src="assets/js/copy-button.js"></script>
<link rel="stylesheet" href="assets/css/copy-button.css" />


# ライブラリの HTML ビルドテスト

ここに書いた内容がトップページに足されます

* this unordered seed list will be replaced by toc as unordered list
{:toc}

## Library Files
### algorithm
* :heavy_check_mark: [algorithm/knuthyao.cpp](library/algorithm/knuthyao.cpp.html)
* :heavy_check_mark: [algorithm/largestrectangle.cpp](library/algorithm/largestrectangle.cpp.html)
* :heavy_check_mark: [algorithm/mo.cpp](library/algorithm/mo.cpp.html)
* :heavy_check_mark: [algorithm/monotoneminima.cpp](library/algorithm/monotoneminima.cpp.html)
* :warning: [algorithm/onlineoffline.cpp](library/algorithm/onlineoffline.cpp.html)
* :heavy_check_mark: [algorithm/optimalbinarytree.cpp](library/algorithm/optimalbinarytree.cpp.html)
* :warning: [algorithm/parallelbinarysearch.cpp](library/algorithm/parallelbinarysearch.cpp.html)


### bbst
* :warning: [bbst/avltree.cpp](library/bbst/avltree.cpp.html)
* :heavy_check_mark: [bbst/pb_ds_tree.cpp](library/bbst/pb_ds_tree.cpp.html)


### bbst/basic
* :heavy_check_mark: [bbst/basic/array.cpp](library/bbst/basic/array.cpp.html)
* :heavy_check_mark: [bbst/basic/base.cpp](library/bbst/basic/base.cpp.html)
* :heavy_check_mark: [bbst/basic/dual.cpp](library/bbst/basic/dual.cpp.html)
* :heavy_check_mark: [bbst/basic/lazy.cpp](library/bbst/basic/lazy.cpp.html)
* :heavy_check_mark: [bbst/basic/ushi.cpp](library/bbst/basic/ushi.cpp.html)


### bbst/persistent
* :warning: [bbst/persistent/array.cpp](library/bbst/persistent/array.cpp.html)
* :warning: [bbst/persistent/lazy.cpp](library/bbst/persistent/lazy.cpp.html)
* :warning: [bbst/persistent/ushi.cpp](library/bbst/persistent/ushi.cpp.html)


### convolution
* :heavy_check_mark: [convolution/arbitrarymodconvolution.cpp](library/convolution/arbitrarymodconvolution.cpp.html)
* :heavy_check_mark: [convolution/arbitrarymodconvolution_with_garner.cpp](library/convolution/arbitrarymodconvolution_with_garner.cpp.html)
* :heavy_check_mark: [convolution/convolution2D.cpp](library/convolution/convolution2D.cpp.html)
* :heavy_check_mark: [convolution/fastfouriertransform.cpp](library/convolution/fastfouriertransform.cpp.html)
* :warning: [convolution/fastwalshhadamardtransform.cpp](library/convolution/fastwalshhadamardtransform.cpp.html)
* :heavy_check_mark: [convolution/numbertheoretictransform.cpp](library/convolution/numbertheoretictransform.cpp.html)


### datastructure
* :heavy_check_mark: [datastructure/BIT2D.cpp](library/datastructure/BIT2D.cpp.html)
* :warning: [datastructure/absolutesum.cpp](library/datastructure/absolutesum.cpp.html)
* :heavy_check_mark: [datastructure/binaryindexedtree.cpp](library/datastructure/binaryindexedtree.cpp.html)
* :heavy_check_mark: [datastructure/binarytrie.cpp](library/datastructure/binarytrie.cpp.html)
* :heavy_check_mark: [datastructure/cartesiantree.cpp](library/datastructure/cartesiantree.cpp.html)
* :heavy_check_mark: [datastructure/convexhulltrick.cpp](library/datastructure/convexhulltrick.cpp.html)
* :warning: [datastructure/convexhulltrickwithindex.cpp](library/datastructure/convexhulltrickwithindex.cpp.html)
* :heavy_check_mark: [datastructure/disjointsparsetable.cpp](library/datastructure/disjointsparsetable.cpp.html)
* :heavy_check_mark: [datastructure/kdtree.cpp](library/datastructure/kdtree.cpp.html)
* :heavy_check_mark: [datastructure/nonmonotonicconvexhulltrick.cpp](library/datastructure/nonmonotonicconvexhulltrick.cpp.html)
* :heavy_check_mark: [datastructure/pb_ds_cc_hash_table.cpp](library/datastructure/pb_ds_cc_hash_table.cpp.html)
* :warning: [datastructure/prioritysum.cpp](library/datastructure/prioritysum.cpp.html)
* :heavy_check_mark: [datastructure/quickfind.cpp](library/datastructure/quickfind.cpp.html)
* :heavy_check_mark: [datastructure/radixheap.cpp](library/datastructure/radixheap.cpp.html)
* :heavy_check_mark: [datastructure/rangeslide.cpp](library/datastructure/rangeslide.cpp.html)
* :heavy_check_mark: [datastructure/skewheap.cpp](library/datastructure/skewheap.cpp.html)
* :heavy_check_mark: [datastructure/slidingwindowaggregation.cpp](library/datastructure/slidingwindowaggregation.cpp.html)
* :heavy_check_mark: [datastructure/sparsetable.cpp](library/datastructure/sparsetable.cpp.html)
* :heavy_check_mark: [datastructure/unionfindtree.cpp](library/datastructure/unionfindtree.cpp.html)
* :heavy_check_mark: [datastructure/waveletmatrix.cpp](library/datastructure/waveletmatrix.cpp.html)
* :heavy_check_mark: [datastructure/weightedunionfindtree.cpp](library/datastructure/weightedunionfindtree.cpp.html)


### flow
* :heavy_check_mark: [flow/bimatch.cpp](library/flow/bimatch.cpp.html)
* :heavy_check_mark: [flow/dinic.cpp](library/flow/dinic.cpp.html)
* :heavy_check_mark: [flow/fordfulkerson.cpp](library/flow/fordfulkerson.cpp.html)
* :heavy_check_mark: [flow/hopcroft_karp.cpp](library/flow/hopcroft_karp.cpp.html)
* :heavy_check_mark: [flow/leastflow.cpp](library/flow/leastflow.cpp.html)
* :heavy_check_mark: [flow/negativeedge.cpp](library/flow/negativeedge.cpp.html)
* :heavy_check_mark: [flow/primaldual.cpp](library/flow/primaldual.cpp.html)


### geometry
* :heavy_check_mark: [geometry/geometry.cpp](library/geometry/geometry.cpp.html)


### geometry/3D
* :warning: [geometry/3D/geometry3D.cpp](library/geometry/3D/geometry3D.cpp.html)


### graph
* :heavy_check_mark: [graph/arborescence_edmond.cpp](library/graph/arborescence_edmond.cpp.html)
* :heavy_check_mark: [graph/arborescence_tarjan.cpp](library/graph/arborescence_tarjan.cpp.html)
* :heavy_check_mark: [graph/bellmanford.cpp](library/graph/bellmanford.cpp.html)
* :heavy_check_mark: [graph/chebyshevneighbors.cpp](library/graph/chebyshevneighbors.cpp.html)
* :heavy_check_mark: [graph/chromatic.cpp](library/graph/chromatic.cpp.html)
* :heavy_check_mark: [graph/dijkstra.cpp](library/graph/dijkstra.cpp.html)
* :heavy_check_mark: [graph/dynamicconnectivity.cpp](library/graph/dynamicconnectivity.cpp.html)
* :warning: [graph/girth.cpp](library/graph/girth.cpp.html)
* :heavy_check_mark: [graph/independentset.cpp](library/graph/independentset.cpp.html)
* :heavy_check_mark: [graph/kruskal.cpp](library/graph/kruskal.cpp.html)
* :heavy_check_mark: [graph/lowlink.cpp](library/graph/lowlink.cpp.html)
* :heavy_check_mark: [graph/maximalmatching.cpp](library/graph/maximalmatching.cpp.html)
* :heavy_check_mark: [graph/multipleeuleriantrail.cpp](library/graph/multipleeuleriantrail.cpp.html)
* :warning: [graph/semikernel.cpp](library/graph/semikernel.cpp.html)
* :heavy_check_mark: [graph/stronglyconnectedcomponent.cpp](library/graph/stronglyconnectedcomponent.cpp.html)
* :warning: [graph/topologicalsort.cpp](library/graph/topologicalsort.cpp.html)
* :heavy_check_mark: [graph/twosatisfiability.cpp](library/graph/twosatisfiability.cpp.html)
* :warning: [graph/voronoiminimumspanningtree.cpp](library/graph/voronoiminimumspanningtree.cpp.html)


### heuristic
* :warning: [heuristic/timer.cpp](library/heuristic/timer.cpp.html)
* :warning: [heuristic/xorshift.cpp](library/heuristic/xorshift.cpp.html)


### linearalgebra
* :heavy_check_mark: [linearalgebra/binarymatrix.cpp](library/linearalgebra/binarymatrix.cpp.html)
* :heavy_check_mark: [linearalgebra/matrix.cpp](library/linearalgebra/matrix.cpp.html)
* :heavy_check_mark: [linearalgebra/squarematrix.cpp](library/linearalgebra/squarematrix.cpp.html)
* :heavy_check_mark: [linearalgebra/tree_theorem.cpp](library/linearalgebra/tree_theorem.cpp.html)


### linkcuttree
* :heavy_check_mark: [linkcuttree/base.cpp](library/linkcuttree/base.cpp.html)
* :heavy_check_mark: [linkcuttree/farthest.cpp](library/linkcuttree/farthest.cpp.html)
* :heavy_check_mark: [linkcuttree/path.cpp](library/linkcuttree/path.cpp.html)
* :heavy_check_mark: [linkcuttree/subtree.cpp](library/linkcuttree/subtree.cpp.html)


### math
* :heavy_check_mark: [math/carmichael.cpp](library/math/carmichael.cpp.html)
* :warning: [math/combination.cpp](library/math/combination.cpp.html)
* :heavy_check_mark: [math/convertbase.cpp](library/math/convertbase.cpp.html)
* :heavy_check_mark: [math/extgcd.cpp](library/math/extgcd.cpp.html)
* :heavy_check_mark: [math/factorize.cpp](library/math/factorize.cpp.html)
* :heavy_check_mark: [math/fraction.cpp](library/math/fraction.cpp.html)
* :heavy_check_mark: [math/is_prime.cpp](library/math/is_prime.cpp.html)
* :warning: [math/kitamasa.cpp](library/math/kitamasa.cpp.html)
* :heavy_check_mark: [math/linearcongruence.cpp](library/math/linearcongruence.cpp.html)
* :heavy_check_mark: [math/tetrahedra.cpp](library/math/tetrahedra.cpp.html)
* :heavy_check_mark: [math/totient.cpp](library/math/totient.cpp.html)
* :warning: [math/totient_table.cpp](library/math/totient_table.cpp.html)


### mod
* :heavy_check_mark: [mod/enumeration.cpp](library/mod/enumeration.cpp.html)
* :warning: [mod/factorial.cpp](library/mod/factorial.cpp.html)
* :heavy_check_mark: [mod/log.cpp](library/mod/log.cpp.html)
* :heavy_check_mark: [mod/mint.cpp](library/mod/mint.cpp.html)
* :heavy_check_mark: [mod/order.cpp](library/mod/order.cpp.html)
* :heavy_check_mark: [mod/pow.cpp](library/mod/pow.cpp.html)
* :heavy_check_mark: [mod/sqrt.cpp](library/mod/sqrt.cpp.html)
* :warning: [mod/tetration.cpp](library/mod/tetration.cpp.html)


### polynomial
* :heavy_check_mark: [polynomial/formalpowerseries.cpp](library/polynomial/formalpowerseries.cpp.html)
* :heavy_check_mark: [polynomial/hash.cpp](library/polynomial/hash.cpp.html)
* :heavy_check_mark: [polynomial/polynomial.cpp](library/polynomial/polynomial.cpp.html)


### segtree/basic
* :heavy_check_mark: [segtree/basic/chien.cpp](library/segtree/basic/chien.cpp.html)
* :heavy_check_mark: [segtree/basic/dual.cpp](library/segtree/basic/dual.cpp.html)
* :heavy_check_mark: [segtree/basic/ushi.cpp](library/segtree/basic/ushi.cpp.html)


### segtree/cht
* :heavy_check_mark: [segtree/cht/lichao.cpp](library/segtree/cht/lichao.cpp.html)


### segtree/count
* :heavy_check_mark: [segtree/count/dynamic_offline.cpp](library/segtree/count/dynamic_offline.cpp.html)
* :heavy_check_mark: [segtree/count/static.cpp](library/segtree/count/static.cpp.html)


### segtree/persistent
* :heavy_check_mark: [segtree/persistent/ushi.cpp](library/segtree/persistent/ushi.cpp.html)


### segtree/types
* :warning: [segtree/types/offline.cpp](library/segtree/types/offline.cpp.html)
* :warning: [segtree/types/online.cpp](library/segtree/types/online.cpp.html)


### string
* :heavy_check_mark: [string/ahocorasick.cpp](library/string/ahocorasick.cpp.html)
* :heavy_check_mark: [string/knuth_morris_pratt.cpp](library/string/knuth_morris_pratt.cpp.html)
* :heavy_check_mark: [string/longestcommonprefix.cpp](library/string/longestcommonprefix.cpp.html)
* :heavy_check_mark: [string/longestcommonsubstring.cpp](library/string/longestcommonsubstring.cpp.html)
* :heavy_check_mark: [string/manacher.cpp](library/string/manacher.cpp.html)
* :heavy_check_mark: [string/palindromictree.cpp](library/string/palindromictree.cpp.html)
* :heavy_check_mark: [string/parse.cpp](library/string/parse.cpp.html)
* :heavy_check_mark: [string/rectanglehash.cpp](library/string/rectanglehash.cpp.html)
* :heavy_check_mark: [string/rollinghash.cpp](library/string/rollinghash.cpp.html)
* :heavy_check_mark: [string/suffixarray.cpp](library/string/suffixarray.cpp.html)
* :heavy_check_mark: [string/trie.cpp](library/string/trie.cpp.html)
* :heavy_check_mark: [string/zalgorithm.cpp](library/string/zalgorithm.cpp.html)


### tools
* :warning: [tools/all_permutations.cpp](library/tools/all_permutations.cpp.html)
* :warning: [tools/bfs.cpp](library/tools/bfs.cpp.html)
* :heavy_check_mark: [tools/bigint.cpp](library/tools/bigint.cpp.html)
* :heavy_check_mark: [tools/chminmax.cpp](library/tools/chminmax.cpp.html)
* :heavy_check_mark: [tools/compress.cpp](library/tools/compress.cpp.html)
* :warning: [tools/debug.cpp](library/tools/debug.cpp.html)
* :heavy_check_mark: [tools/dice.cpp](library/tools/dice.cpp.html)
* :heavy_check_mark: [tools/drop.cpp](library/tools/drop.cpp.html)
* :heavy_check_mark: [tools/fastio.cpp](library/tools/fastio.cpp.html)
* :heavy_check_mark: [tools/fixpoint.cpp](library/tools/fixpoint.cpp.html)
* :warning: [tools/int128.cpp](library/tools/int128.cpp.html)
* :warning: [tools/iskado.cpp](library/tools/iskado.cpp.html)
* :heavy_check_mark: [tools/precision.cpp](library/tools/precision.cpp.html)
* :warning: [tools/split.cpp](library/tools/split.cpp.html)
* :warning: [tools/trio.cpp](library/tools/trio.cpp.html)
* :heavy_check_mark: [tools/vec.cpp](library/tools/vec.cpp.html)
* :warning: [tools/zip.cpp](library/tools/zip.cpp.html)


### tree
* :heavy_check_mark: [tree/centroid.cpp](library/tree/centroid.cpp.html)
* :heavy_check_mark: [tree/diameterforedge.cpp](library/tree/diameterforedge.cpp.html)
* :heavy_check_mark: [tree/diameterforvertex.cpp](library/tree/diameterforvertex.cpp.html)
* :heavy_check_mark: [tree/eulertourforedge.cpp](library/tree/eulertourforedge.cpp.html)
* :heavy_check_mark: [tree/eulertourforvertex.cpp](library/tree/eulertourforvertex.cpp.html)
* :heavy_check_mark: [tree/heavylightdecomposition.cpp](library/tree/heavylightdecomposition.cpp.html)
* :heavy_check_mark: [tree/lca.cpp](library/tree/lca.cpp.html)
* :heavy_check_mark: [tree/levelancestor.cpp](library/tree/levelancestor.cpp.html)
* :heavy_check_mark: [tree/lowestcommonancestor.cpp](library/tree/lowestcommonancestor.cpp.html)
* :heavy_check_mark: [tree/rerooting.cpp](library/tree/rerooting.cpp.html)
* :warning: [tree/sack.cpp](library/tree/sack.cpp.html)
* :warning: [tree/treeconstruction.cpp](library/tree/treeconstruction.cpp.html)


## Verify Files
* :heavy_check_mark: [test/aoj/0109.test.cpp](verify/test/aoj/0109.test.cpp.html)
* :heavy_check_mark: [test/aoj/0233.test.cpp](verify/test/aoj/0233.test.cpp.html)
* :heavy_check_mark: [test/aoj/0314.test.cpp](verify/test/aoj/0314.test.cpp.html)
* :heavy_check_mark: [test/aoj/0367.linkcuttree.test.cpp](verify/test/aoj/0367.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/0377.test.cpp](verify/test/aoj/0377.test.cpp.html)
* :heavy_check_mark: [test/aoj/0391.test.cpp](verify/test/aoj/0391.test.cpp.html)
* :heavy_check_mark: [test/aoj/0403.test.cpp](verify/test/aoj/0403.test.cpp.html)
* :heavy_check_mark: [test/aoj/0415.test.cpp](verify/test/aoj/0415.test.cpp.html)
* :heavy_check_mark: [test/aoj/0423.test.cpp](verify/test/aoj/0423.test.cpp.html)
* :heavy_check_mark: [test/aoj/0424.test.cpp](verify/test/aoj/0424.test.cpp.html)
* :heavy_check_mark: [test/aoj/0425.test.cpp](verify/test/aoj/0425.test.cpp.html)
* :heavy_check_mark: [test/aoj/0502.test.cpp](verify/test/aoj/0502.test.cpp.html)
* :heavy_check_mark: [test/aoj/0563.test.cpp](verify/test/aoj/0563.test.cpp.html)
* :heavy_check_mark: [test/aoj/0613.test.cpp](verify/test/aoj/0613.test.cpp.html)
* :heavy_check_mark: [test/aoj/1197.test.cpp](verify/test/aoj/1197.test.cpp.html)
* :heavy_check_mark: [test/aoj/1254.test.cpp](verify/test/aoj/1254.test.cpp.html)
* :heavy_check_mark: [test/aoj/1293.test.cpp](verify/test/aoj/1293.test.cpp.html)
* :heavy_check_mark: [test/aoj/1308.test.cpp](verify/test/aoj/1308.test.cpp.html)
* :heavy_check_mark: [test/aoj/1312.test.cpp](verify/test/aoj/1312.test.cpp.html)
* :heavy_check_mark: [test/aoj/1328.test.cpp](verify/test/aoj/1328.test.cpp.html)
* :heavy_check_mark: [test/aoj/1338.test.cpp](verify/test/aoj/1338.test.cpp.html)
* :heavy_check_mark: [test/aoj/1508.test.cpp](verify/test/aoj/1508.test.cpp.html)
* :heavy_check_mark: [test/aoj/1549.test.cpp](verify/test/aoj/1549.test.cpp.html)
* :heavy_check_mark: [test/aoj/1579.test.cpp](verify/test/aoj/1579.test.cpp.html)
* :heavy_check_mark: [test/aoj/1595.linkcuttree.test.cpp](verify/test/aoj/1595.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/1595.test.cpp](verify/test/aoj/1595.test.cpp.html)
* :heavy_check_mark: [test/aoj/1599.test.cpp](verify/test/aoj/1599.test.cpp.html)
* :heavy_check_mark: [test/aoj/1607.test.cpp](verify/test/aoj/1607.test.cpp.html)
* :heavy_check_mark: [test/aoj/1615.test.cpp](verify/test/aoj/1615.test.cpp.html)
* :heavy_check_mark: [test/aoj/1630.test.cpp](verify/test/aoj/1630.test.cpp.html)
* :heavy_check_mark: [test/aoj/2060.test.cpp](verify/test/aoj/2060.test.cpp.html)
* :heavy_check_mark: [test/aoj/2212.test.cpp](verify/test/aoj/2212.test.cpp.html)
* :heavy_check_mark: [test/aoj/2222.test.cpp](verify/test/aoj/2222.test.cpp.html)
* :heavy_check_mark: [test/aoj/2230.test.cpp](verify/test/aoj/2230.test.cpp.html)
* :heavy_check_mark: [test/aoj/2235.test.cpp](verify/test/aoj/2235.test.cpp.html)
* :heavy_check_mark: [test/aoj/2257.test.cpp](verify/test/aoj/2257.test.cpp.html)
* :heavy_check_mark: [test/aoj/2292.test.cpp](verify/test/aoj/2292.test.cpp.html)
* :heavy_check_mark: [test/aoj/2294.test.cpp](verify/test/aoj/2294.test.cpp.html)
* :heavy_check_mark: [test/aoj/2309.tarjan.test.cpp](verify/test/aoj/2309.tarjan.test.cpp.html)
* :heavy_check_mark: [test/aoj/2309.test.cpp](verify/test/aoj/2309.test.cpp.html)
* :heavy_check_mark: [test/aoj/2313.test.cpp](verify/test/aoj/2313.test.cpp.html)
* :heavy_check_mark: [test/aoj/2324.test.cpp](verify/test/aoj/2324.test.cpp.html)
* :heavy_check_mark: [test/aoj/2359.test.cpp](verify/test/aoj/2359.test.cpp.html)
* :heavy_check_mark: [test/aoj/2397.test.cpp](verify/test/aoj/2397.test.cpp.html)
* :heavy_check_mark: [test/aoj/2415.test.cpp](verify/test/aoj/2415.test.cpp.html)
* :heavy_check_mark: [test/aoj/2444.test.cpp](verify/test/aoj/2444.test.cpp.html)
* :heavy_check_mark: [test/aoj/2450.linkcuttree.test.cpp](verify/test/aoj/2450.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/2450.test.cpp](verify/test/aoj/2450.test.cpp.html)
* :heavy_check_mark: [test/aoj/2488.test.cpp](verify/test/aoj/2488.test.cpp.html)
* :heavy_check_mark: [test/aoj/2513.test.cpp](verify/test/aoj/2513.test.cpp.html)
* :heavy_check_mark: [test/aoj/2560.test.cpp](verify/test/aoj/2560.test.cpp.html)
* :heavy_check_mark: [test/aoj/2603.test.cpp](verify/test/aoj/2603.test.cpp.html)
* :heavy_check_mark: [test/aoj/2624.test.cpp](verify/test/aoj/2624.test.cpp.html)
* :heavy_check_mark: [test/aoj/2627.test.cpp](verify/test/aoj/2627.test.cpp.html)
* :heavy_check_mark: [test/aoj/2644.test.cpp](verify/test/aoj/2644.test.cpp.html)
* :heavy_check_mark: [test/aoj/2646.test.cpp](verify/test/aoj/2646.test.cpp.html)
* :heavy_check_mark: [test/aoj/2647.test.cpp](verify/test/aoj/2647.test.cpp.html)
* :heavy_check_mark: [test/aoj/2659.test.cpp](verify/test/aoj/2659.test.cpp.html)
* :heavy_check_mark: [test/aoj/2667.test.cpp](verify/test/aoj/2667.test.cpp.html)
* :heavy_check_mark: [test/aoj/2674.count.test.cpp](verify/test/aoj/2674.count.test.cpp.html)
* :heavy_check_mark: [test/aoj/2674.test.cpp](verify/test/aoj/2674.test.cpp.html)
* :heavy_check_mark: [test/aoj/2679.test.cpp](verify/test/aoj/2679.test.cpp.html)
* :heavy_check_mark: [test/aoj/2711.test.cpp](verify/test/aoj/2711.test.cpp.html)
* :heavy_check_mark: [test/aoj/2720.test.cpp](verify/test/aoj/2720.test.cpp.html)
* :heavy_check_mark: [test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp](verify/test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp.html)
* :heavy_check_mark: [test/aoj/2725.test.cpp](verify/test/aoj/2725.test.cpp.html)
* :heavy_check_mark: [test/aoj/2790.test.cpp](verify/test/aoj/2790.test.cpp.html)
* :heavy_check_mark: [test/aoj/2842.2D_BIT.test.cpp](verify/test/aoj/2842.2D_BIT.test.cpp.html)
* :heavy_check_mark: [test/aoj/2842.test.cpp](verify/test/aoj/2842.test.cpp.html)
* :heavy_check_mark: [test/aoj/2871.test.cpp](verify/test/aoj/2871.test.cpp.html)
* :heavy_check_mark: [test/aoj/2872.test.cpp](verify/test/aoj/2872.test.cpp.html)
* :heavy_check_mark: [test/aoj/2890.test.cpp](verify/test/aoj/2890.test.cpp.html)
* :heavy_check_mark: [test/aoj/2934.test.cpp](verify/test/aoj/2934.test.cpp.html)
* :heavy_check_mark: [test/aoj/2948.test.cpp](verify/test/aoj/2948.test.cpp.html)
* :heavy_check_mark: [test/aoj/2959.test.cpp](verify/test/aoj/2959.test.cpp.html)
* :heavy_check_mark: [test/aoj/2970.test.cpp](verify/test/aoj/2970.test.cpp.html)
* :heavy_check_mark: [test/aoj/2971.test.cpp](verify/test/aoj/2971.test.cpp.html)
* :heavy_check_mark: [test/aoj/2975.test.cpp](verify/test/aoj/2975.test.cpp.html)
* :heavy_check_mark: [test/aoj/2977.test.cpp](verify/test/aoj/2977.test.cpp.html)
* :heavy_check_mark: [test/aoj/2983.test.cpp](verify/test/aoj/2983.test.cpp.html)
* :heavy_check_mark: [test/aoj/2985.garner.test.cpp](verify/test/aoj/2985.garner.test.cpp.html)
* :heavy_check_mark: [test/aoj/2985.test.cpp](verify/test/aoj/2985.test.cpp.html)
* :heavy_check_mark: [test/aoj/3024.test.cpp](verify/test/aoj/3024.test.cpp.html)
* :heavy_check_mark: [test/aoj/3033.test.cpp](verify/test/aoj/3033.test.cpp.html)
* :heavy_check_mark: [test/aoj/3035.test.cpp](verify/test/aoj/3035.test.cpp.html)
* :heavy_check_mark: [test/aoj/3047.test.cpp](verify/test/aoj/3047.test.cpp.html)
* :heavy_check_mark: [test/aoj/3058.test.cpp](verify/test/aoj/3058.test.cpp.html)
* :heavy_check_mark: [test/aoj/3062.test.cpp](verify/test/aoj/3062.test.cpp.html)
* :heavy_check_mark: [test/aoj/3063.test.cpp](verify/test/aoj/3063.test.cpp.html)
* :heavy_check_mark: [test/aoj/3069.lichao.test.cpp](verify/test/aoj/3069.lichao.test.cpp.html)
* :heavy_check_mark: [test/aoj/3069.test.cpp](verify/test/aoj/3069.test.cpp.html)
* :heavy_check_mark: [test/aoj/3072.test.cpp](verify/test/aoj/3072.test.cpp.html)
* :heavy_check_mark: [test/aoj/3073.test.cpp](verify/test/aoj/3073.test.cpp.html)
* :heavy_check_mark: [test/aoj/3074.test.cpp](verify/test/aoj/3074.test.cpp.html)
* :heavy_check_mark: [test/aoj/3102.test.cpp](verify/test/aoj/3102.test.cpp.html)
* :heavy_check_mark: [test/aoj/3112.test.cpp](verify/test/aoj/3112.test.cpp.html)
* :heavy_check_mark: [test/aoj/ALDS1_10_C.test.cpp](verify/test/aoj/ALDS1_10_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/ALDS1_14_B.knuth_morris_pratt.test.cpp](verify/test/aoj/ALDS1_14_B.knuth_morris_pratt.test.cpp.html)
* :heavy_check_mark: [test/aoj/ALDS1_14_B.test.cpp](verify/test/aoj/ALDS1_14_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/ALDS1_14_C.test.cpp](verify/test/aoj/ALDS1_14_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/ALDS1_14_D.test.cpp](verify/test/aoj/ALDS1_14_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/ALDS1_1_C.test.cpp](verify/test/aoj/ALDS1_1_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/ALDS1_9_C.test.cpp](verify/test/aoj/ALDS1_9_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_3_B.test.cpp](verify/test/aoj/DPL_3_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_3_C.test.cpp](verify/test/aoj/DPL_3_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_A.test.cpp](verify/test/aoj/DPL_5_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_B.test.cpp](verify/test/aoj/DPL_5_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_C.test.cpp](verify/test/aoj/DPL_5_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_D.test.cpp](verify/test/aoj/DPL_5_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_E.test.cpp](verify/test/aoj/DPL_5_E.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_F.test.cpp](verify/test/aoj/DPL_5_F.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_G.test.cpp](verify/test/aoj/DPL_5_G.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_H.test.cpp](verify/test/aoj/DPL_5_H.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_I.test.cpp](verify/test/aoj/DPL_5_I.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_J.test.cpp](verify/test/aoj/DPL_5_J.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_K.test.cpp](verify/test/aoj/DPL_5_K.test.cpp.html)
* :heavy_check_mark: [test/aoj/DPL_5_L.test.cpp](verify/test/aoj/DPL_5_L.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_1_A.quickfind.test.cpp](verify/test/aoj/DSL_1_A.quickfind.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_1_A.test.cpp](verify/test/aoj/DSL_1_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_1_B.test.cpp](verify/test/aoj/DSL_1_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_A.bbst.test.cpp](verify/test/aoj/DSL_2_A.bbst.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_A.test.cpp](verify/test/aoj/DSL_2_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_B.binarytrie.test.cpp](verify/test/aoj/DSL_2_B.binarytrie.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_B.test.cpp](verify/test/aoj/DSL_2_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_C.test.cpp](verify/test/aoj/DSL_2_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_D.bbst.test.cpp](verify/test/aoj/DSL_2_D.bbst.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_D.test.cpp](verify/test/aoj/DSL_2_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_E.bbst.test.cpp](verify/test/aoj/DSL_2_E.bbst.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_E.test.cpp](verify/test/aoj/DSL_2_E.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_F.bbst.test.cpp](verify/test/aoj/DSL_2_F.bbst.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_F.test.cpp](verify/test/aoj/DSL_2_F.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_G.bbst.test.cpp](verify/test/aoj/DSL_2_G.bbst.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_G.test.cpp](verify/test/aoj/DSL_2_G.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_H.bbst.test.cpp](verify/test/aoj/DSL_2_H.bbst.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_H.test.cpp](verify/test/aoj/DSL_2_H.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_I.bbst.test.cpp](verify/test/aoj/DSL_2_I.bbst.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_2_I.test.cpp](verify/test/aoj/DSL_2_I.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_3_D.cartesiantree.test.cpp](verify/test/aoj/DSL_3_D.cartesiantree.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_3_D.disjointsparsetable.test.cpp](verify/test/aoj/DSL_3_D.disjointsparsetable.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp](verify/test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_3_D.sparsetable.test.cpp](verify/test/aoj/DSL_3_D.sparsetable.test.cpp.html)
* :heavy_check_mark: [test/aoj/DSL_3_D.test.cpp](verify/test/aoj/DSL_3_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_1_A.test.cpp](verify/test/aoj/GRL_1_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_1_B.test.cpp](verify/test/aoj/GRL_1_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_2_A.test.cpp](verify/test/aoj/GRL_2_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_2_B.tarjan.test.cpp](verify/test/aoj/GRL_2_B.tarjan.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_2_B.test.cpp](verify/test/aoj/GRL_2_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_3_A.test.cpp](verify/test/aoj/GRL_3_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_3_B.test.cpp](verify/test/aoj/GRL_3_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_3_C.test.cpp](verify/test/aoj/GRL_3_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_4_A.test.cpp](verify/test/aoj/GRL_4_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_A.linkcuttree.test.cpp](verify/test/aoj/GRL_5_A.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_A.test.cpp](verify/test/aoj/GRL_5_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_C.lca.test.cpp](verify/test/aoj/GRL_5_C.lca.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_C.lowestcommonancestor.test.cpp](verify/test/aoj/GRL_5_C.lowestcommonancestor.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_C.test.cpp](verify/test/aoj/GRL_5_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_D.linkcuttree.test.cpp](verify/test/aoj/GRL_5_D.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_D.test.cpp](verify/test/aoj/GRL_5_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_5_E.linkcuttree.test.cpp](verify/test/aoj/GRL_5_E.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_6_A.fordfulkerson.test.cpp](verify/test/aoj/GRL_6_A.fordfulkerson.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_6_A.test.cpp](verify/test/aoj/GRL_6_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_6_B.test.cpp](verify/test/aoj/GRL_6_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_7_A.hopcroft_karp.test.cpp](verify/test/aoj/GRL_7_A.hopcroft_karp.test.cpp.html)
* :heavy_check_mark: [test/aoj/GRL_7_A.test.cpp](verify/test/aoj/GRL_7_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/ITP1_11_A.test.cpp](verify/test/aoj/ITP1_11_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/ITP1_11_B.test.cpp](verify/test/aoj/ITP1_11_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/ITP1_11_C.test.cpp](verify/test/aoj/ITP1_11_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/ITP1_11_D.test.cpp](verify/test/aoj/ITP1_11_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/NTL_1_A.test.cpp](verify/test/aoj/NTL_1_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/NTL_1_B.test.cpp](verify/test/aoj/NTL_1_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/NTL_1_D.test.cpp](verify/test/aoj/NTL_1_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/NTL_1_E.test.cpp](verify/test/aoj/NTL_1_E.test.cpp.html)
* :heavy_check_mark: [test/aoj/NTL_2_A.test.cpp](verify/test/aoj/NTL_2_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/NTL_2_B.test.cpp](verify/test/aoj/NTL_2_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/NTL_2_C.test.cpp](verify/test/aoj/NTL_2_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/NTL_2_D.test.cpp](verify/test/aoj/NTL_2_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/NTL_2_E.test.cpp](verify/test/aoj/NTL_2_E.test.cpp.html)
* :heavy_check_mark: [test/aoj/NTL_2_F.test.cpp](verify/test/aoj/NTL_2_F.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/2334.test.cpp](verify/test/aoj/geometry/2334.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/2448.test.cpp](verify/test/aoj/geometry/2448.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/2454.test.cpp](verify/test/aoj/geometry/2454.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/3049.test.cpp](verify/test/aoj/geometry/3049.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/3056.test.cpp](verify/test/aoj/geometry/3056.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_1_A.test.cpp](verify/test/aoj/geometry/CGL_1_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_1_B.test.cpp](verify/test/aoj/geometry/CGL_1_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_1_C.test.cpp](verify/test/aoj/geometry/CGL_1_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_2_A.test.cpp](verify/test/aoj/geometry/CGL_2_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_2_B.test.cpp](verify/test/aoj/geometry/CGL_2_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_2_C.test.cpp](verify/test/aoj/geometry/CGL_2_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_2_D.test.cpp](verify/test/aoj/geometry/CGL_2_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_3_A.test.cpp](verify/test/aoj/geometry/CGL_3_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_3_B.test.cpp](verify/test/aoj/geometry/CGL_3_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_3_C.test.cpp](verify/test/aoj/geometry/CGL_3_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_4_A.test.cpp](verify/test/aoj/geometry/CGL_4_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_4_B.test.cpp](verify/test/aoj/geometry/CGL_4_B.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_4_C.test.cpp](verify/test/aoj/geometry/CGL_4_C.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_5_A.test.cpp](verify/test/aoj/geometry/CGL_5_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_6_A.test.cpp](verify/test/aoj/geometry/CGL_6_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_7_A.test.cpp](verify/test/aoj/geometry/CGL_7_A.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_7_D.test.cpp](verify/test/aoj/geometry/CGL_7_D.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_7_E.test.cpp](verify/test/aoj/geometry/CGL_7_E.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_7_F.test.cpp](verify/test/aoj/geometry/CGL_7_F.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_7_G.test.cpp](verify/test/aoj/geometry/CGL_7_G.test.cpp.html)
* :heavy_check_mark: [test/aoj/geometry/CGL_7_H.test.cpp](verify/test/aoj/geometry/CGL_7_H.test.cpp.html)
* :heavy_check_mark: [test/yosupo/bernoulli_number.test.cpp](verify/test/yosupo/bernoulli_number.test.cpp.html)
* :heavy_check_mark: [test/yosupo/bipartitematching.test.cpp](verify/test/yosupo/bipartitematching.test.cpp.html)
* :heavy_check_mark: [test/yosupo/convolution_mod.test.cpp](verify/test/yosupo/convolution_mod.test.cpp.html)
* :heavy_check_mark: [test/yosupo/discrete_logarithm_mod.test.cpp](verify/test/yosupo/discrete_logarithm_mod.test.cpp.html)
* :heavy_check_mark: [test/yosupo/exp_of_formal_power_series.test.cpp](verify/test/yosupo/exp_of_formal_power_series.test.cpp.html)
* :heavy_check_mark: [test/yosupo/inv_of_formal_power_series.test.cpp](verify/test/yosupo/inv_of_formal_power_series.test.cpp.html)
* :heavy_check_mark: [test/yosupo/lca.test.cpp](verify/test/yosupo/lca.test.cpp.html)
* :heavy_check_mark: [test/yosupo/log_of_formal_power_series.test.cpp](verify/test/yosupo/log_of_formal_power_series.test.cpp.html)
* :heavy_check_mark: [test/yosupo/matrix_det.test.cpp](verify/test/yosupo/matrix_det.test.cpp.html)
* :heavy_check_mark: [test/yosupo/maximum_independent_set.test.cpp](verify/test/yosupo/maximum_independent_set.test.cpp.html)
* :heavy_check_mark: [test/yosupo/number_of_substrings.test.cpp](verify/test/yosupo/number_of_substrings.test.cpp.html)
* :heavy_check_mark: [test/yosupo/partition_function.test.cpp](verify/test/yosupo/partition_function.test.cpp.html)
* :heavy_check_mark: [test/yosupo/point_add_range_sum.test.cpp](verify/test/yosupo/point_add_range_sum.test.cpp.html)
* :heavy_check_mark: [test/yosupo/point_set_range_composite.test.cpp](verify/test/yosupo/point_set_range_composite.test.cpp.html)
* :heavy_check_mark: [test/yosupo/rectangle_sum.test.cpp](verify/test/yosupo/rectangle_sum.test.cpp.html)
* :heavy_check_mark: [test/yosupo/scc.test.cpp](verify/test/yosupo/scc.test.cpp.html)
* :heavy_check_mark: [test/yosupo/sqrt_mod.test.cpp](verify/test/yosupo/sqrt_mod.test.cpp.html)
* :heavy_check_mark: [test/yosupo/staticrmq.disjointsparsetable.test.cpp](verify/test/yosupo/staticrmq.disjointsparsetable.test.cpp.html)
* :heavy_check_mark: [test/yosupo/staticrmq.sparsetable.test.cpp](verify/test/yosupo/staticrmq.sparsetable.test.cpp.html)
* :heavy_check_mark: [test/yosupo/suffixarray.test.cpp](verify/test/yosupo/suffixarray.test.cpp.html)
* :heavy_check_mark: [test/yosupo/unionfind.test.cpp](verify/test/yosupo/unionfind.test.cpp.html)
* :heavy_check_mark: [test/yosupo/vertex_add_path_sum.test.cpp](verify/test/yosupo/vertex_add_path_sum.test.cpp.html)
* :heavy_check_mark: [test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp](verify/test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp.html)
* :heavy_check_mark: [test/yosupo/vertex_add_subtree_sum.test.cpp](verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html)
* :heavy_check_mark: [test/yosupo/zalgorithm.test.cpp](verify/test/yosupo/zalgorithm.test.cpp.html)


