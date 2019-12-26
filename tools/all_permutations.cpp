#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename F>
void all_permutations(int n,F f){
  vector<int> vs(n);
  iota(vs.begin(),vs.end(),0);
  do f(vs); while(next_permutation(vs.begin(),vs.end()));
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
