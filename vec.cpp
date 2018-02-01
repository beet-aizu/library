#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T>
vector<vector<T> > make_v(size_t a,size_t b){
  return vector<vector<T> >(a,make_v<T>(b));
}
template<typename T>
vector<vector<vector<T> > > make_v(size_t a,size_t b,size_t c){
  return vector<vector<vector<T> > > (a,make_v<T>(b,c));
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
  auto v=make_v<int>(10,10);
  fill_v(v,-1);
  
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      cout<<v[i][j]<<" \n"[j==9];
  
  using P = pair<int, int>;
  auto G=make_v<P>(10,0);
  vector<vector<P> > G(n); 
  for(int i=0;i<10;i++) G[i].emplace_back(i,100);
  for(int i=0;i<10;i++)
    for(auto[u,c]:G[i])
      cout<<i<<":"<<u<<" "<<c<<endl;
  return 0;
}
