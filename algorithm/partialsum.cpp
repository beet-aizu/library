#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
// O(n sqrt(n) / w)
// w: wordsize
template<size_t N>
bitset<N+1> partial_sum(vector<int> vs){
  int sum=0;
  for(int v:vs) sum+=v;
  assert(sum<=N);
  vector<int> cnt(sum+1,0);
  for(int v:vs) cnt[v]++;
  for(int i=1;i*2<=sum;i++){
    int num=(cnt[i]-1)/2;
    cnt[i]-=num*2;
    cnt[i*2]+=num;
  }
  bitset<N+1> dp;
  dp[0]=1;
  for(int i=1;i<=sum;i++)
    for(int t=0;t<cnt[i];t++)
      dp|=dp<<i;
  return dp;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
