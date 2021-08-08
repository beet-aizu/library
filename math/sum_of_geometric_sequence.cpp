#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// first: sum_{i=0}^{n-1} r^i
// second: r^n
template<typename T>
pair<T, T> sum_of_geometric_sequence_impl(T r,long long n){
  if(n==1) return {T(1),r};
  auto p=sum_of_geometric_sequence_impl(r,n/2);
  T sum=p.first*(T(1)+p.second);
  T pow=p.second*p.second;
  if(n&1) sum+=pow,pow*=r;
  return {sum,pow};
}
// sum_{i=0}^{n-1} r^i
template<typename T>
T sum_of_geometric_sequence(T r,long long n){
  return sum_of_geometric_sequence_impl(r,n).first;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
