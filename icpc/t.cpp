#include<bits/stdc++.h>
using namespace std;
using Int = long long;
using ll = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}

const int DEBUG = 1;
template<typename ...Ts>
void debug(Ts... ts){
  if(!DEBUG) return;
  cout<<"#:";
  auto print=[](auto v){cout<<v<<" ";};
  initializer_list<int>{(void(print(ts)),0)...};
  cout<<endl;
}

#define F first
#define S second

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  return 0;
}
