#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename R>
struct Kitamasa{
  using VR = vector<R>;
  VR cs;
  vector<VR> rs;
  int m;

  Kitamasa(const VR &C)
    :cs(C),rs(1),m(C.size()){
    rs[0].assign(2*m+1,R::add_identity());
    rs[0][1]=R::mul_identity();
  }

  VR merge(const VR &xs,const VR &ys){
    VR zs(2*m+1,R::add_identity());
    for(int i=1;i<=m;i++)
      for(int j=1;j<=m;j++)
        zs[i+j]=zs[i+j]+(xs[i]*ys[j]);

    for(int i=2*m;i>m;zs[i--]=R::add_identity())
      for(int j=1;j<=m;j++)
        zs[i-j]=zs[i-j]+(cs[m-j]*zs[i]);
    return zs;
  }

  R calc(const VR &A,long long n){
    assert((int)A.size()==m);
    VR res(rs[0]);
    for(int i=0;n;i++,n>>=1){
      if(i>=(int)rs.size())
        rs.emplace_back(merge(rs[i-1],rs[i-1]));
      if(~n&1) continue;
      res=merge(res,rs[i]);
    }
    R ans=R::add_identity();
    for(int i=1;i<=m;i++) ans=ans+(res[i]*A[i-1]);
    return ans;
  }
};
//END CUT HERE
#ifndef call_from_test

#define call_from_test
#include "../mod/mint.cpp"
#undef call_from_test

//INSERT ABOVE HERE
signed ABC009_D(){
  int k,m;
  scanf("%d %d",&k,&m);

  struct M{
    uint32_t v;
    M(){*this=add_identity();}
    M(uint32_t v):v(v){}
    M operator+(const M &a)const{return M(v^a.v);}
    M operator*(const M &a)const{return M(v&a.v);}
    static M add_identity(){return M(0);}
    static M mul_identity(){return M(~0u);}
  };

  vector<M> as(k),cs(k);
  for(int i=0;i<k;i++) scanf("%u",&as[i].v);
  for(int i=0;i<k;i++) scanf("%u",&cs[k-(i+1)].v);
  Kitamasa<M> v(cs);

  printf("%u\n",v.calc(as,--m).v);
  return 0;
}
/*
  verified on 2019/12/10
  https://atcoder.jp/contests/abc009/tasks/abc009_4
*/

signed main(){
  //ABC009_D();
  return 0;
}
#endif
