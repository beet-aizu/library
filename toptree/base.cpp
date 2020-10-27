#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct Vertex{
  void* handle;
  Vertex():handle(nullptr){}
};
struct Cluster{
  Cluster(){}
  void toggle(){}
  static Cluster compress(Cluster x,Vertex *v,Cluster y){}
  static Cluster rake(Cluster x,Cluster y){}
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed main(){
  return 0;
}
#endif
