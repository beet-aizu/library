#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/skewheap.cpp"
#undef call_from_test

#define IGNORE

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  using Heap=SkewHeap<int, int>;
  auto g=[](int a,int b){return a+b;};
  auto c=[](int a,int b){return a<b;};
  int INF = -1;
  Heap heap(g,g,c,INF,0);
  auto base=heap.push(0);

  string s;
  while(cin>>s,s!="end"){
    int x;
    if(s=="insert"){
      cin>>x;
      base=heap.meld(base,heap.push(x));
    }
    if(s=="extract"){
      x=heap.top(base);
      base=heap.pop(base);
      cout<<x<<"\n";
    }
  }
  cout<<flush;
  return 0;
}
