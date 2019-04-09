#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}

//END CUT HERE
//INSERT ABOVE HERE
signed main(){
  auto v=make_v<int>(10,10);  
  fill_v<int>(v,-1);

  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      v[i][j]=i+j;
  
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      cout<<v[i][j]<<" \n"[j==9];

  auto vt=make_v<tuple<int, double> >(3,3);
  fill_v<tuple<int, double> >(vt,2,0.5);
  cout<<get<0>(vt[0][0])<<endl;
  cout<<get<1>(vt[2][2])<<endl;
  return 0;
}
