#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T, typename U, typename V>
struct trio{
  T first;
  U second;
  V third;
  trio(){}
  trio(T first,U second,V third):
    first(first),second(second),third(third){}
  operator tuple<T&, U&, V&>(){
    return forward_as_tuple(first,second,third);
  }
  using X = tuple<T, U, V>;
  operator X() const{return make_tuple(first,second,third);}
  bool operator==(const trio&a) const{return (X)(*this)==(X)a;}
  bool operator!=(const trio&a) const{return (X)(*this)!=(X)a;}
  bool operator< (const trio&a) const{return (X)(*this)< (X)a;}
  bool operator<=(const trio&a) const{return (X)(*this)<=(X)a;}
  bool operator> (const trio&a) const{return (X)(*this)> (X)a;}
  bool operator>=(const trio&a) const{return (X)(*this)>=(X)a;}
};
template<typename T, typename U, typename V>
trio<T, U, V> make_trio(T first,U second,V third){
  return trio<T, U, V>(first,second,third);
}
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "fastio.cpp"
#include "fixpoint.cpp"
#include "chminmax.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed CPSCO2019_SESSION1_H(){
  using ll = long long;

  int n,sum;
  cin>>n>>sum;
  vector<int> as(n);
  for(int i=0;i<n;i++) cin>>as[i];

  const int MAX = 1e5+10;
  ll ans=0;
  MFP([&](auto dfs,int l,int r)->void{
        if(l+1==r){
          if(as[l]*3==sum) ans++;
          return;
        }
        int m=(l+r)>>1;
        dfs(l,m);
        dfs(m,r);
        using T = trio<int, int, int>;
        vector<T> vx,vy;
        {
          vx.reserve(r-m);
          int res=-1,cnt=0;
          for(int i=m;i<r;i++){
            if(res<as[i]) res=as[i],cnt=0;
            if(res==as[i]) cnt++;
            vx.emplace_back(res,cnt,as[i]);
          }
        }
        {
          vy.reserve(m-l);
          int res=-1,cnt=0;
          for(int i=m-1;i>=l;i--){
            if(res<as[i]) res=as[i],cnt=0;
            if(res==as[i]) cnt++;
            vy.emplace_back(res,cnt,as[i]);
          }
        }
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());

        map<int, int> cx,cy;
        int sx=vx.size(),sy=vy.size();
        int i=0,j=0;
        while(i<sx||j<sy){
          int k=MAX;
          if(i<sx) chmin(k,vx[i].first);
          if(j<sy) chmin(k,vy[j].first);

          vector<int> tx,ty;
          while(i<sx&&k==vx[i].first){
            cx[vx[i].third]++;
            tx.emplace_back(i++);
          }
          while(j<sy&&k==vy[j].first){
            cy[vy[j].third]++;
            ty.emplace_back(j++);
          }

          for(int x:tx)
            ans+=(ll)vx[x].second*cy[sum-(k+vx[x].third)];

          for(int y:ty)
            ans+=(ll)vy[y].second*cx[sum-(k+vy[y].third)];
        }
      })(0,n);

  cout<<ans<<endl;
  return 0;
}
/*
  verified on 2019/05/09
  https://atcoder.jp/contests/cpsco2019-s1/tasks/cpsco2019_s1_h
*/

signed main(){
  //CPSCO2019_SESSION1_H();
  return 0;
}
#endif
