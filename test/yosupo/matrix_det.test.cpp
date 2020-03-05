#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../linearalgebra/matrix.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using M = Mint<int, 998244353>;
  using Mat = Matrix<M>;
  int n;
  cin>>n;

  Mat A(n,n);
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>A[i][j].v;

  cout<<A.determinant()<<endl;
  return 0;
}
