#define PROBLEM "https://yukicoder.me/problems/831"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/bigint.cpp"
#include "../../linearalgebra/squarematrix.cpp"
#undef call_from_test

signed main(){
  using ll = long long;
  ll l;
  cin>>l;

  if(l==2){
    cout<<3<<endl;
    cout<<"INF"<<endl;
    return 0;
  }
  cout<<l<<endl;

  using M = SquareMatrix<bigint, 2>;
  M A;
  A[0][0]=1;A[0][1]=1;
  A[1][0]=1;A[1][1]=0;
  if(l&1) cout<<A.pow(l)[1][0]<<endl;
  else{
    auto B=A.pow(l/2);
    auto X=(B*B)[1][0];
    auto Y=B[1][0];
    cout<<X-Y*Y<<endl;
  }
  return 0;
}
