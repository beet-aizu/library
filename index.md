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


# C++ Competitive Programming Library

[![Actions Status]({{ site.github.repository_url }}/workflows/verify/badge.svg)]({{ site.github.repository_url }}/actions) <a href="{{ site.github.repository_url }}"><img src="https://img.shields.io/github/last-commit/{{ site.github.owner_name }}/{{ site.github.repository_name }}" /></a>

## Library Files
### algorithm
* :heavy_check_mark: <a href="library/algorithm/knuthyao.cpp.html">algorithm/knuthyao.cpp</a>
* :heavy_check_mark: <a href="library/algorithm/largestrectangle.cpp.html">algorithm/largestrectangle.cpp</a>
* :heavy_check_mark: <a href="library/algorithm/mo.cpp.html">algorithm/mo.cpp</a>
* :heavy_check_mark: <a href="library/algorithm/monotoneminima.cpp.html">algorithm/monotoneminima.cpp</a>
* :warning: <a href="library/algorithm/onlineoffline.cpp.html">algorithm/onlineoffline.cpp</a>
* :heavy_check_mark: <a href="library/algorithm/optimalbinarytree.cpp.html">algorithm/optimalbinarytree.cpp</a>
* :warning: <a href="library/algorithm/parallelbinarysearch.cpp.html">algorithm/parallelbinarysearch.cpp</a>


### bbst
* :warning: <a href="library/bbst/avltree.cpp.html">bbst/avltree.cpp</a>
* :heavy_check_mark: <a href="library/bbst/pb_ds_tree.cpp.html">bbst/pb_ds_tree.cpp</a>


### bbst/basic
* :heavy_check_mark: <a href="library/bbst/basic/array.cpp.html">bbst/basic/array.cpp</a>
* :heavy_check_mark: <a href="library/bbst/basic/base.cpp.html">bbst/basic/base.cpp</a>
* :heavy_check_mark: <a href="library/bbst/basic/dual.cpp.html">bbst/basic/dual.cpp</a>
* :heavy_check_mark: <a href="library/bbst/basic/lazy.cpp.html">bbst/basic/lazy.cpp</a>
* :heavy_check_mark: <a href="library/bbst/basic/ushi.cpp.html">bbst/basic/ushi.cpp</a>


### bbst/persistent
* :warning: <a href="library/bbst/persistent/array.cpp.html">bbst/persistent/array.cpp</a>
* :warning: <a href="library/bbst/persistent/lazy.cpp.html">bbst/persistent/lazy.cpp</a>
* :warning: <a href="library/bbst/persistent/ushi.cpp.html">bbst/persistent/ushi.cpp</a>


### convolution
* :heavy_check_mark: <a href="library/convolution/arbitrarymodconvolution.cpp.html">convolution/arbitrarymodconvolution.cpp</a>
* :heavy_check_mark: <a href="library/convolution/arbitrarymodconvolution_with_garner.cpp.html">convolution/arbitrarymodconvolution_with_garner.cpp</a>
* :heavy_check_mark: <a href="library/convolution/convolution2D.cpp.html">convolution/convolution2D.cpp</a>
* :heavy_check_mark: <a href="library/convolution/fastfouriertransform.cpp.html">convolution/fastfouriertransform.cpp</a>
* :warning: <a href="library/convolution/fastwalshhadamardtransform.cpp.html">convolution/fastwalshhadamardtransform.cpp</a>
* :heavy_check_mark: <a href="library/convolution/numbertheoretictransform.cpp.html">convolution/numbertheoretictransform.cpp</a>


### datastructure
* :heavy_check_mark: <a href="library/datastructure/BIT2D.cpp.html">datastructure/BIT2D.cpp</a>
* :warning: <a href="library/datastructure/absolutesum.cpp.html">datastructure/absolutesum.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/binaryindexedtree.cpp.html">datastructure/binaryindexedtree.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/binarytrie.cpp.html">datastructure/binarytrie.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/cartesiantree.cpp.html">datastructure/cartesiantree.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/convexhulltrick.cpp.html">datastructure/convexhulltrick.cpp</a>
* :warning: <a href="library/datastructure/convexhulltrickwithindex.cpp.html">datastructure/convexhulltrickwithindex.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/disjointsparsetable.cpp.html">datastructure/disjointsparsetable.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/kdtree.cpp.html">datastructure/kdtree.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/nonmonotonicconvexhulltrick.cpp.html">datastructure/nonmonotonicconvexhulltrick.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/pb_ds_cc_hash_table.cpp.html">datastructure/pb_ds_cc_hash_table.cpp</a>
* :warning: <a href="library/datastructure/prioritysum.cpp.html">datastructure/prioritysum.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/quickfind.cpp.html">datastructure/quickfind.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/radixheap.cpp.html">datastructure/radixheap.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/rangeslide.cpp.html">datastructure/rangeslide.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/skewheap.cpp.html">datastructure/skewheap.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/slidingwindowaggregation.cpp.html">datastructure/slidingwindowaggregation.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/sparsetable.cpp.html">datastructure/sparsetable.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/unionfindtree.cpp.html">datastructure/unionfindtree.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/waveletmatrix.cpp.html">datastructure/waveletmatrix.cpp</a>
* :heavy_check_mark: <a href="library/datastructure/weightedunionfindtree.cpp.html">datastructure/weightedunionfindtree.cpp</a>


### flow
* :heavy_check_mark: <a href="library/flow/bimatch.cpp.html">flow/bimatch.cpp</a>
* :heavy_check_mark: <a href="library/flow/dinic.cpp.html">flow/dinic.cpp</a>
* :heavy_check_mark: <a href="library/flow/fordfulkerson.cpp.html">flow/fordfulkerson.cpp</a>
* :heavy_check_mark: <a href="library/flow/hopcroft_karp.cpp.html">flow/hopcroft_karp.cpp</a>
* :heavy_check_mark: <a href="library/flow/leastflow.cpp.html">flow/leastflow.cpp</a>
* :heavy_check_mark: <a href="library/flow/negativeedge.cpp.html">flow/negativeedge.cpp</a>
* :heavy_check_mark: <a href="library/flow/primaldual.cpp.html">flow/primaldual.cpp</a>


### geometry
* :heavy_check_mark: <a href="library/geometry/geometry.cpp.html">geometry/geometry.cpp</a>


### geometry/3D
* :warning: <a href="library/geometry/3D/geometry3D.cpp.html">geometry/3D/geometry3D.cpp</a>


### graph
* :heavy_check_mark: <a href="library/graph/arborescence_edmond.cpp.html">graph/arborescence_edmond.cpp</a>
* :heavy_check_mark: <a href="library/graph/arborescence_tarjan.cpp.html">graph/arborescence_tarjan.cpp</a>
* :heavy_check_mark: <a href="library/graph/bellmanford.cpp.html">graph/bellmanford.cpp</a>
* :heavy_check_mark: <a href="library/graph/chebyshevneighbors.cpp.html">graph/chebyshevneighbors.cpp</a>
* :heavy_check_mark: <a href="library/graph/chromatic.cpp.html">graph/chromatic.cpp</a>
* :heavy_check_mark: <a href="library/graph/dijkstra.cpp.html">graph/dijkstra.cpp</a>
* :heavy_check_mark: <a href="library/graph/dynamicconnectivity.cpp.html">graph/dynamicconnectivity.cpp</a>
* :warning: <a href="library/graph/girth.cpp.html">graph/girth.cpp</a>
* :heavy_check_mark: <a href="library/graph/independentset.cpp.html">graph/independentset.cpp</a>
* :heavy_check_mark: <a href="library/graph/kruskal.cpp.html">graph/kruskal.cpp</a>
* :heavy_check_mark: <a href="library/graph/lowlink.cpp.html">graph/lowlink.cpp</a>
* :heavy_check_mark: <a href="library/graph/maximalmatching.cpp.html">graph/maximalmatching.cpp</a>
* :heavy_check_mark: <a href="library/graph/multipleeuleriantrail.cpp.html">graph/multipleeuleriantrail.cpp</a>
* :warning: <a href="library/graph/semikernel.cpp.html">graph/semikernel.cpp</a>
* :heavy_check_mark: <a href="library/graph/stronglyconnectedcomponent.cpp.html">graph/stronglyconnectedcomponent.cpp</a>
* :warning: <a href="library/graph/topologicalsort.cpp.html">graph/topologicalsort.cpp</a>
* :heavy_check_mark: <a href="library/graph/twosatisfiability.cpp.html">graph/twosatisfiability.cpp</a>
* :warning: <a href="library/graph/voronoiminimumspanningtree.cpp.html">graph/voronoiminimumspanningtree.cpp</a>


### linearalgebra
* :heavy_check_mark: <a href="library/linearalgebra/binarymatrix.cpp.html">linearalgebra/binarymatrix.cpp</a>
* :heavy_check_mark: <a href="library/linearalgebra/matrix.cpp.html">linearalgebra/matrix.cpp</a>
* :heavy_check_mark: <a href="library/linearalgebra/squarematrix.cpp.html">linearalgebra/squarematrix.cpp</a>
* :heavy_check_mark: <a href="library/linearalgebra/tree_theorem.cpp.html">linearalgebra/tree_theorem.cpp</a>


### linkcuttree
* :heavy_check_mark: <a href="library/linkcuttree/base.cpp.html">linkcuttree/base.cpp</a>
* :heavy_check_mark: <a href="library/linkcuttree/farthest.cpp.html">linkcuttree/farthest.cpp</a>
* :heavy_check_mark: <a href="library/linkcuttree/path.cpp.html">linkcuttree/path.cpp</a>
* :heavy_check_mark: <a href="library/linkcuttree/subtree.cpp.html">linkcuttree/subtree.cpp</a>


### math
* :heavy_check_mark: <a href="library/math/carmichael.cpp.html">math/carmichael.cpp</a>
* :warning: <a href="library/math/combination.cpp.html">math/combination.cpp</a>
* :heavy_check_mark: <a href="library/math/convertbase.cpp.html">math/convertbase.cpp</a>
* :heavy_check_mark: <a href="library/math/extgcd.cpp.html">math/extgcd.cpp</a>
* :heavy_check_mark: <a href="library/math/factorize.cpp.html">math/factorize.cpp</a>
* :heavy_check_mark: <a href="library/math/fraction.cpp.html">math/fraction.cpp</a>
* :heavy_check_mark: <a href="library/math/is_prime.cpp.html">math/is_prime.cpp</a>
* :heavy_check_mark: <a href="library/math/kitamasa.cpp.html">math/kitamasa.cpp</a>
* :heavy_check_mark: <a href="library/math/linearcongruence.cpp.html">math/linearcongruence.cpp</a>
* :heavy_check_mark: <a href="library/math/tetrahedra.cpp.html">math/tetrahedra.cpp</a>
* :heavy_check_mark: <a href="library/math/totient.cpp.html">math/totient.cpp</a>
* :heavy_check_mark: <a href="library/math/totient_table.cpp.html">math/totient_table.cpp</a>


### mod
* :heavy_check_mark: <a href="library/mod/enumeration.cpp.html">mod/enumeration.cpp</a>
* :warning: <a href="library/mod/factorial.cpp.html">mod/factorial.cpp</a>
* :heavy_check_mark: <a href="library/mod/log.cpp.html">mod/log.cpp</a>
* :heavy_check_mark: <a href="library/mod/mint.cpp.html">mod/mint.cpp</a>
* :heavy_check_mark: <a href="library/mod/order.cpp.html">mod/order.cpp</a>
* :heavy_check_mark: <a href="library/mod/pow.cpp.html">mod/pow.cpp</a>
* :heavy_check_mark: <a href="library/mod/sqrt.cpp.html">mod/sqrt.cpp</a>
* :warning: <a href="library/mod/tetration.cpp.html">mod/tetration.cpp</a>


### polynomial
* :heavy_check_mark: <a href="library/polynomial/formalpowerseries.cpp.html">polynomial/formalpowerseries.cpp</a>
* :heavy_check_mark: <a href="library/polynomial/hash.cpp.html">polynomial/hash.cpp</a>
* :heavy_check_mark: <a href="library/polynomial/polynomial.cpp.html">polynomial/polynomial.cpp</a>


### segtree/basic
* :heavy_check_mark: <a href="library/segtree/basic/chien.cpp.html">segtree/basic/chien.cpp</a>
* :heavy_check_mark: <a href="library/segtree/basic/dual.cpp.html">segtree/basic/dual.cpp</a>
* :heavy_check_mark: <a href="library/segtree/basic/ushi.cpp.html">segtree/basic/ushi.cpp</a>


### segtree/cht
* :heavy_check_mark: <a href="library/segtree/cht/lichao.cpp.html">segtree/cht/lichao.cpp</a>


### segtree/count
* :heavy_check_mark: <a href="library/segtree/count/dynamic_offline.cpp.html">segtree/count/dynamic_offline.cpp</a>
* :heavy_check_mark: <a href="library/segtree/count/static.cpp.html">segtree/count/static.cpp</a>


### segtree/persistent
* :heavy_check_mark: <a href="library/segtree/persistent/ushi.cpp.html">segtree/persistent/ushi.cpp</a>


### segtree/types
* :warning: <a href="library/segtree/types/offline.cpp.html">segtree/types/offline.cpp</a>
* :warning: <a href="library/segtree/types/online.cpp.html">segtree/types/online.cpp</a>


### string
* :heavy_check_mark: <a href="library/string/ahocorasick.cpp.html">string/ahocorasick.cpp</a>
* :heavy_check_mark: <a href="library/string/knuth_morris_pratt.cpp.html">string/knuth_morris_pratt.cpp</a>
* :heavy_check_mark: <a href="library/string/longestcommonprefix.cpp.html">string/longestcommonprefix.cpp</a>
* :heavy_check_mark: <a href="library/string/longestcommonsubstring.cpp.html">string/longestcommonsubstring.cpp</a>
* :heavy_check_mark: <a href="library/string/manacher.cpp.html">string/manacher.cpp</a>
* :heavy_check_mark: <a href="library/string/palindromictree.cpp.html">string/palindromictree.cpp</a>
* :heavy_check_mark: <a href="library/string/parse.cpp.html">string/parse.cpp</a>
* :heavy_check_mark: <a href="library/string/rectanglehash.cpp.html">string/rectanglehash.cpp</a>
* :heavy_check_mark: <a href="library/string/rollinghash.cpp.html">string/rollinghash.cpp</a>
* :heavy_check_mark: <a href="library/string/split.cpp.html">string/split.cpp</a>
* :heavy_check_mark: <a href="library/string/suffixarray.cpp.html">string/suffixarray.cpp</a>
* :heavy_check_mark: <a href="library/string/trie.cpp.html">string/trie.cpp</a>
* :heavy_check_mark: <a href="library/string/zalgorithm.cpp.html">string/zalgorithm.cpp</a>


### tools
* :heavy_check_mark: <a href="library/tools/all_permutations.cpp.html">tools/all_permutations.cpp</a>
* :heavy_check_mark: <a href="library/tools/bfs.cpp.html">tools/bfs.cpp</a>
* :heavy_check_mark: <a href="library/tools/bigint.cpp.html">tools/bigint.cpp</a>
* :heavy_check_mark: <a href="library/tools/chminmax.cpp.html">tools/chminmax.cpp</a>
* :heavy_check_mark: <a href="library/tools/compress.cpp.html">tools/compress.cpp</a>
* :heavy_check_mark: <a href="library/tools/dice.cpp.html">tools/dice.cpp</a>
* :heavy_check_mark: <a href="library/tools/drop.cpp.html">tools/drop.cpp</a>
* :heavy_check_mark: <a href="library/tools/fastio.cpp.html">tools/fastio.cpp</a>
* :heavy_check_mark: <a href="library/tools/fixpoint.cpp.html">tools/fixpoint.cpp</a>
* :heavy_check_mark: <a href="library/tools/int128.cpp.html">tools/int128.cpp</a>
* :warning: <a href="library/tools/iskado.cpp.html">tools/iskado.cpp</a>
* :heavy_check_mark: <a href="library/tools/precision.cpp.html">tools/precision.cpp</a>
* :warning: <a href="library/tools/trio.cpp.html">tools/trio.cpp</a>
* :heavy_check_mark: <a href="library/tools/vec.cpp.html">tools/vec.cpp</a>
* :warning: <a href="library/tools/zip.cpp.html">tools/zip.cpp</a>


### tree
* :heavy_check_mark: <a href="library/tree/centroid.cpp.html">tree/centroid.cpp</a>
* :warning: <a href="library/tree/construct_from_distances_to_farthest_vertex.cpp.html">tree/construct_from_distances_to_farthest_vertex.cpp</a>
* :heavy_check_mark: <a href="library/tree/diameterforedge.cpp.html">tree/diameterforedge.cpp</a>
* :heavy_check_mark: <a href="library/tree/diameterforvertex.cpp.html">tree/diameterforvertex.cpp</a>
* :heavy_check_mark: <a href="library/tree/eulertourforedge.cpp.html">tree/eulertourforedge.cpp</a>
* :heavy_check_mark: <a href="library/tree/eulertourforvertex.cpp.html">tree/eulertourforvertex.cpp</a>
* :heavy_check_mark: <a href="library/tree/heavylightdecomposition.cpp.html">tree/heavylightdecomposition.cpp</a>
* :heavy_check_mark: <a href="library/tree/lca.cpp.html">tree/lca.cpp</a>
* :heavy_check_mark: <a href="library/tree/levelancestor.cpp.html">tree/levelancestor.cpp</a>
* :heavy_check_mark: <a href="library/tree/lowestcommonancestor.cpp.html">tree/lowestcommonancestor.cpp</a>
* :heavy_check_mark: <a href="library/tree/rerooting.cpp.html">tree/rerooting.cpp</a>
* :warning: <a href="library/tree/sack.cpp.html">tree/sack.cpp</a>


## Verify Files
* :heavy_check_mark: <a href="verify/test/aoj/0109.test.cpp.html">test/aoj/0109.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0168.test.cpp.html">test/aoj/0168.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0233.test.cpp.html">test/aoj/0233.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0314.test.cpp.html">test/aoj/0314.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0367.linkcuttree.test.cpp.html">test/aoj/0367.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0377.test.cpp.html">test/aoj/0377.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0391.test.cpp.html">test/aoj/0391.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0403.test.cpp.html">test/aoj/0403.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0415.test.cpp.html">test/aoj/0415.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0423.test.cpp.html">test/aoj/0423.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0424.test.cpp.html">test/aoj/0424.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0425.test.cpp.html">test/aoj/0425.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0502.test.cpp.html">test/aoj/0502.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0558.test.cpp.html">test/aoj/0558.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0563.test.cpp.html">test/aoj/0563.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/0613.test.cpp.html">test/aoj/0613.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1069.test.cpp.html">test/aoj/1069.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1197.test.cpp.html">test/aoj/1197.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1254.test.cpp.html">test/aoj/1254.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1293.test.cpp.html">test/aoj/1293.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1308.test.cpp.html">test/aoj/1308.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1312.test.cpp.html">test/aoj/1312.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1328.test.cpp.html">test/aoj/1328.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1338.test.cpp.html">test/aoj/1338.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1508.test.cpp.html">test/aoj/1508.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1549.test.cpp.html">test/aoj/1549.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1579.test.cpp.html">test/aoj/1579.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1595.linkcuttree.test.cpp.html">test/aoj/1595.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1595.test.cpp.html">test/aoj/1595.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1599.test.cpp.html">test/aoj/1599.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1607.test.cpp.html">test/aoj/1607.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1615.test.cpp.html">test/aoj/1615.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/1630.test.cpp.html">test/aoj/1630.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2060.test.cpp.html">test/aoj/2060.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2187.test.cpp.html">test/aoj/2187.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2212.test.cpp.html">test/aoj/2212.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2222.test.cpp.html">test/aoj/2222.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2230.test.cpp.html">test/aoj/2230.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2235.test.cpp.html">test/aoj/2235.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2257.test.cpp.html">test/aoj/2257.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2286.test.cpp.html">test/aoj/2286.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2292.test.cpp.html">test/aoj/2292.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2294.test.cpp.html">test/aoj/2294.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2309.tarjan.test.cpp.html">test/aoj/2309.tarjan.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2309.test.cpp.html">test/aoj/2309.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2313.test.cpp.html">test/aoj/2313.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2324.test.cpp.html">test/aoj/2324.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2328.test.cpp.html">test/aoj/2328.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2359.test.cpp.html">test/aoj/2359.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2397.test.cpp.html">test/aoj/2397.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2415.test.cpp.html">test/aoj/2415.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2444.test.cpp.html">test/aoj/2444.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2450.linkcuttree.test.cpp.html">test/aoj/2450.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2450.test.cpp.html">test/aoj/2450.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2488.test.cpp.html">test/aoj/2488.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2513.test.cpp.html">test/aoj/2513.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2560.test.cpp.html">test/aoj/2560.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2603.test.cpp.html">test/aoj/2603.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2624.test.cpp.html">test/aoj/2624.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2627.test.cpp.html">test/aoj/2627.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2644.test.cpp.html">test/aoj/2644.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2646.test.cpp.html">test/aoj/2646.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2647.test.cpp.html">test/aoj/2647.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2659.test.cpp.html">test/aoj/2659.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2667.test.cpp.html">test/aoj/2667.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2674.count.test.cpp.html">test/aoj/2674.count.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2674.test.cpp.html">test/aoj/2674.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2679.test.cpp.html">test/aoj/2679.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2711.test.cpp.html">test/aoj/2711.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2720.test.cpp.html">test/aoj/2720.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp.html">test/aoj/2725.nonmonotonicconvexhulltrick.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2725.test.cpp.html">test/aoj/2725.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2790.test.cpp.html">test/aoj/2790.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2842.2D_BIT.test.cpp.html">test/aoj/2842.2D_BIT.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2842.test.cpp.html">test/aoj/2842.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2871.test.cpp.html">test/aoj/2871.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2872.test.cpp.html">test/aoj/2872.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2890.test.cpp.html">test/aoj/2890.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2934.test.cpp.html">test/aoj/2934.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2948.test.cpp.html">test/aoj/2948.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2959.test.cpp.html">test/aoj/2959.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2970.test.cpp.html">test/aoj/2970.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2971.test.cpp.html">test/aoj/2971.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2975.test.cpp.html">test/aoj/2975.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2977.test.cpp.html">test/aoj/2977.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2983.test.cpp.html">test/aoj/2983.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2985.garner.test.cpp.html">test/aoj/2985.garner.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/2985.test.cpp.html">test/aoj/2985.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3024.test.cpp.html">test/aoj/3024.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3033.test.cpp.html">test/aoj/3033.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3035.test.cpp.html">test/aoj/3035.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3047.test.cpp.html">test/aoj/3047.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3053.test.cpp.html">test/aoj/3053.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3058.test.cpp.html">test/aoj/3058.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3062.test.cpp.html">test/aoj/3062.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3063.test.cpp.html">test/aoj/3063.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3069.lichao.test.cpp.html">test/aoj/3069.lichao.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3069.test.cpp.html">test/aoj/3069.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3072.test.cpp.html">test/aoj/3072.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3073.test.cpp.html">test/aoj/3073.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3074.test.cpp.html">test/aoj/3074.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3102.test.cpp.html">test/aoj/3102.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/3112.test.cpp.html">test/aoj/3112.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/ALDS1_10_C.test.cpp.html">test/aoj/ALDS1_10_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/ALDS1_14_B.knuth_morris_pratt.test.cpp.html">test/aoj/ALDS1_14_B.knuth_morris_pratt.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/ALDS1_14_B.test.cpp.html">test/aoj/ALDS1_14_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/ALDS1_14_C.test.cpp.html">test/aoj/ALDS1_14_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/ALDS1_14_D.test.cpp.html">test/aoj/ALDS1_14_D.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/ALDS1_1_C.test.cpp.html">test/aoj/ALDS1_1_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/ALDS1_9_C.test.cpp.html">test/aoj/ALDS1_9_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_3_B.test.cpp.html">test/aoj/DPL_3_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_3_C.test.cpp.html">test/aoj/DPL_3_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_5_A.test.cpp.html">test/aoj/DPL_5_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_5_B.test.cpp.html">test/aoj/DPL_5_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_5_C.test.cpp.html">test/aoj/DPL_5_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_5_D.test.cpp.html">test/aoj/DPL_5_D.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_5_E.test.cpp.html">test/aoj/DPL_5_E.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_5_F.test.cpp.html">test/aoj/DPL_5_F.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_5_G.test.cpp.html">test/aoj/DPL_5_G.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_5_H.test.cpp.html">test/aoj/DPL_5_H.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_5_I.test.cpp.html">test/aoj/DPL_5_I.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_5_J.test.cpp.html">test/aoj/DPL_5_J.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_5_K.test.cpp.html">test/aoj/DPL_5_K.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DPL_5_L.test.cpp.html">test/aoj/DPL_5_L.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_1_A.quickfind.test.cpp.html">test/aoj/DSL_1_A.quickfind.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_1_A.test.cpp.html">test/aoj/DSL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_1_B.test.cpp.html">test/aoj/DSL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_A.bbst.test.cpp.html">test/aoj/DSL_2_A.bbst.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_A.test.cpp.html">test/aoj/DSL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_B.binarytrie.test.cpp.html">test/aoj/DSL_2_B.binarytrie.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_B.test.cpp.html">test/aoj/DSL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_C.test.cpp.html">test/aoj/DSL_2_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_D.bbst.test.cpp.html">test/aoj/DSL_2_D.bbst.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_D.test.cpp.html">test/aoj/DSL_2_D.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_E.bbst.test.cpp.html">test/aoj/DSL_2_E.bbst.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_E.test.cpp.html">test/aoj/DSL_2_E.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_F.bbst.test.cpp.html">test/aoj/DSL_2_F.bbst.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_F.test.cpp.html">test/aoj/DSL_2_F.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_G.bbst.test.cpp.html">test/aoj/DSL_2_G.bbst.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_G.test.cpp.html">test/aoj/DSL_2_G.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_H.bbst.test.cpp.html">test/aoj/DSL_2_H.bbst.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_H.test.cpp.html">test/aoj/DSL_2_H.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_I.bbst.test.cpp.html">test/aoj/DSL_2_I.bbst.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_2_I.test.cpp.html">test/aoj/DSL_2_I.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_3_D.cartesiantree.test.cpp.html">test/aoj/DSL_3_D.cartesiantree.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_3_D.disjointsparsetable.test.cpp.html">test/aoj/DSL_3_D.disjointsparsetable.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp.html">test/aoj/DSL_3_D.slidingwindowaggregation.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_3_D.sparsetable.test.cpp.html">test/aoj/DSL_3_D.sparsetable.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/DSL_3_D.test.cpp.html">test/aoj/DSL_3_D.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_1_A.test.cpp.html">test/aoj/GRL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_1_B.test.cpp.html">test/aoj/GRL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_2_A.test.cpp.html">test/aoj/GRL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_2_B.tarjan.test.cpp.html">test/aoj/GRL_2_B.tarjan.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_2_B.test.cpp.html">test/aoj/GRL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_3_A.test.cpp.html">test/aoj/GRL_3_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_3_B.test.cpp.html">test/aoj/GRL_3_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_3_C.test.cpp.html">test/aoj/GRL_3_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_4_A.test.cpp.html">test/aoj/GRL_4_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_5_A.linkcuttree.test.cpp.html">test/aoj/GRL_5_A.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_5_A.test.cpp.html">test/aoj/GRL_5_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_5_C.lca.test.cpp.html">test/aoj/GRL_5_C.lca.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_5_C.lowestcommonancestor.test.cpp.html">test/aoj/GRL_5_C.lowestcommonancestor.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_5_C.test.cpp.html">test/aoj/GRL_5_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_5_D.linkcuttree.test.cpp.html">test/aoj/GRL_5_D.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_5_D.test.cpp.html">test/aoj/GRL_5_D.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_5_E.linkcuttree.test.cpp.html">test/aoj/GRL_5_E.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_6_A.fordfulkerson.test.cpp.html">test/aoj/GRL_6_A.fordfulkerson.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_6_A.test.cpp.html">test/aoj/GRL_6_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_6_B.test.cpp.html">test/aoj/GRL_6_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_7_A.hopcroft_karp.test.cpp.html">test/aoj/GRL_7_A.hopcroft_karp.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/GRL_7_A.test.cpp.html">test/aoj/GRL_7_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/ITP1_11_A.test.cpp.html">test/aoj/ITP1_11_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/ITP1_11_B.test.cpp.html">test/aoj/ITP1_11_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/ITP1_11_C.test.cpp.html">test/aoj/ITP1_11_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/ITP1_11_D.test.cpp.html">test/aoj/ITP1_11_D.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/NTL_1_A.test.cpp.html">test/aoj/NTL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/NTL_1_B.test.cpp.html">test/aoj/NTL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/NTL_1_D.test.cpp.html">test/aoj/NTL_1_D.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/NTL_1_E.test.cpp.html">test/aoj/NTL_1_E.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/NTL_2_A.test.cpp.html">test/aoj/NTL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/NTL_2_B.test.cpp.html">test/aoj/NTL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/NTL_2_C.test.cpp.html">test/aoj/NTL_2_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/NTL_2_D.test.cpp.html">test/aoj/NTL_2_D.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/NTL_2_E.test.cpp.html">test/aoj/NTL_2_E.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/NTL_2_F.test.cpp.html">test/aoj/NTL_2_F.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/2334.test.cpp.html">test/aoj/geometry/2334.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/2448.test.cpp.html">test/aoj/geometry/2448.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/2454.test.cpp.html">test/aoj/geometry/2454.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/3049.test.cpp.html">test/aoj/geometry/3049.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/3056.test.cpp.html">test/aoj/geometry/3056.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_1_A.test.cpp.html">test/aoj/geometry/CGL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_1_B.test.cpp.html">test/aoj/geometry/CGL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_1_C.test.cpp.html">test/aoj/geometry/CGL_1_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_2_A.test.cpp.html">test/aoj/geometry/CGL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_2_B.test.cpp.html">test/aoj/geometry/CGL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_2_C.test.cpp.html">test/aoj/geometry/CGL_2_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_2_D.test.cpp.html">test/aoj/geometry/CGL_2_D.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_3_A.test.cpp.html">test/aoj/geometry/CGL_3_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_3_B.test.cpp.html">test/aoj/geometry/CGL_3_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_3_C.test.cpp.html">test/aoj/geometry/CGL_3_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_4_A.test.cpp.html">test/aoj/geometry/CGL_4_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_4_B.test.cpp.html">test/aoj/geometry/CGL_4_B.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_4_C.test.cpp.html">test/aoj/geometry/CGL_4_C.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_5_A.test.cpp.html">test/aoj/geometry/CGL_5_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_6_A.test.cpp.html">test/aoj/geometry/CGL_6_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_7_A.test.cpp.html">test/aoj/geometry/CGL_7_A.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_7_D.test.cpp.html">test/aoj/geometry/CGL_7_D.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_7_E.test.cpp.html">test/aoj/geometry/CGL_7_E.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_7_F.test.cpp.html">test/aoj/geometry/CGL_7_F.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_7_G.test.cpp.html">test/aoj/geometry/CGL_7_G.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/aoj/geometry/CGL_7_H.test.cpp.html">test/aoj/geometry/CGL_7_H.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/bernoulli_number.test.cpp.html">test/yosupo/bernoulli_number.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/bipartitematching.test.cpp.html">test/yosupo/bipartitematching.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/convolution_mod.test.cpp.html">test/yosupo/convolution_mod.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/discrete_logarithm_mod.test.cpp.html">test/yosupo/discrete_logarithm_mod.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/exp_of_formal_power_series.test.cpp.html">test/yosupo/exp_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/inv_of_formal_power_series.test.cpp.html">test/yosupo/inv_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/lca.test.cpp.html">test/yosupo/lca.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/log_of_formal_power_series.test.cpp.html">test/yosupo/log_of_formal_power_series.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/matrix_det.test.cpp.html">test/yosupo/matrix_det.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/maximum_independent_set.test.cpp.html">test/yosupo/maximum_independent_set.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/number_of_substrings.test.cpp.html">test/yosupo/number_of_substrings.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/partition_function.test.cpp.html">test/yosupo/partition_function.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/point_add_range_sum.test.cpp.html">test/yosupo/point_add_range_sum.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/point_set_range_composite.test.cpp.html">test/yosupo/point_set_range_composite.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/rectangle_sum.test.cpp.html">test/yosupo/rectangle_sum.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/scc.test.cpp.html">test/yosupo/scc.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/sqrt_mod.test.cpp.html">test/yosupo/sqrt_mod.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/staticrmq.disjointsparsetable.test.cpp.html">test/yosupo/staticrmq.disjointsparsetable.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/staticrmq.sparsetable.test.cpp.html">test/yosupo/staticrmq.sparsetable.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/suffixarray.test.cpp.html">test/yosupo/suffixarray.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/unionfind.test.cpp.html">test/yosupo/unionfind.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/vertex_add_path_sum.test.cpp.html">test/yosupo/vertex_add_path_sum.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp.html">test/yosupo/vertex_add_subtree_sum.linkcuttree.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html">test/yosupo/vertex_add_subtree_sum.test.cpp</a>
* :heavy_check_mark: <a href="verify/test/yosupo/zalgorithm.test.cpp.html">test/yosupo/zalgorithm.test.cpp</a>


