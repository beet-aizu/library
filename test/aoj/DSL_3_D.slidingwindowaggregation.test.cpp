#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../datastructure/slidingwindowaggregation.cpp"
#undef call_from_test

signed main(){
  int n,l;
  cin>>n>>l;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  auto f=[](int a,int b){return min(a,b);};
  SWAG<int, int> swag(f,INT_MAX);

  for(int i=0;i<l;i++) swag.push(as[i]);
  for(int i=0;i+l<=n;i++){
    if(i) cout<<" ";
    swag.fold([](int a,int b){cout<<min(a,b);});
    if(i+l<n){
      swag.pop();
      swag.push(as[i+l]);
    }
  }
  cout<<endl;
  return 0;
}
