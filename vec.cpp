#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}

template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}
//END CUT HERE
//INSERT ABOVE HERE
signed main(){
  auto v=make_v(10,10,(int)-1);
  
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      cout<<v[i][j]<<" \n"[j==9];
  
  return 0;
}
