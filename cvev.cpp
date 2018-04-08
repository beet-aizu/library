#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T,size_t... es>
struct Vec{
  T v;
  T* begin(){return &v;};
  T* end(){return (&v)+1;};
  void fill(T x){v=x;};
  T& operator=(T x){return v=x;};
  operator T&(){return v;};
};

template<typename T,size_t e,size_t... es>
struct Vec<T,e,es...>{
  vector<Vec<T, es...> > v;
  Vec<T,e,es...>():v(e){};
  Vec<T, es...>& operator[](int i){return v[i];};
  typename vector<T>::iterator begin(){return v.begin();};
  typename vector<T>::iterator end(){return v.end();};
  void fill(T x){for(auto &a:v) a.fill(x);};
};

//END CUT HERE
//INSERT ABOVE HERE
signed main(){
  auto v=Vec<int,10,10>();
  v.fill(-1);

  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      v[i][j]=i+j;
      
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      cout<<v[i][j]<<" \n"[j==9];

  return 0;
}
