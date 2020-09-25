// verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2624

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../linearalgebra/binarymatrix.cpp"
#undef call_from_test

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  mat v(n,BS(0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int k;
      cin>>k;
      v[i][j]=k;
    }
  }
  BS w;
  for(int i=0;i<n;i++){
    int k;
    cin>>k;
    w[i]=k;
  }
  int t;
  cin>>t;
  v=mat_pow(v,t);

  int a=mrank(v,n);
  for(int i=0;i<n;i++) v[i][n]=w[i];
  int b=mrank(v,n+1);

  if(a!=b){
    cout<<"none"<<endl;
    return 0;
  }

  if(a!=n){
    cout<<"ambiguous"<<endl;
    return 0;
  }

  gauss(v);
  for(int i=0;i<n;i++) cout<<v[i][n]<<" \n"[i==n-1];

  return 0;
}
