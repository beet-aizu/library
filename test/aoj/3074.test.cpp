#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3074"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../mod/mint.cpp"
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../convolution/convolution2D.cpp"
#include "../../linearalgebra/squarematrix.cpp"
#undef call_from_test

NTT<2> ntt;
using M = NTT<2>::M;
auto tran=[](auto &as,bool f){ntt.ntt(as,f);};
Convolution2D<M, decltype(tran)> conv(tran);

struct Ring{
  vector<M> dat;
  Ring(){};
  Ring(vector<M> dat):dat(dat){};
  static Ring add_identity();
  static Ring mul_identity();
  Ring operator*(const Ring &a)const{
    auto res=Ring(dat);
    for(int i=0;i<(int)dat.size();i++) res.dat[i]*=a.dat[i];
    return res;
  }
  Ring operator+(const Ring &a)const{
    auto res=Ring(dat);
    for(int i=0;i<(int)dat.size();i++) res.dat[i]+=a.dat[i];
    return res;
  }
};

Ring add_id, mul_id;
Ring Ring::add_identity(){return add_id;};
Ring Ring::mul_identity(){return mul_id;};

signed main(){
  int h,w;
  long long k;
  cin>>h>>w>>k;
  h=1<<h;
  w=1<<w;
  vector< vector<int> > tt(h,vector<int>(w));
  vector< vector<int> > gg(h,vector<int>(w));
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin>>tt[i][j];
  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++)
      cin>>gg[i][j];

  using Matrix = vector< vector<M> >;
  Matrix T(h,vector<M>(w));
  Matrix G(h,vector<M>(w));
  Matrix W(h,vector<M>(w));
  Matrix H(h,vector<M>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      T[i][j]=tt[i][j]>=0?tt[i][j]:0;
      G[i][j]=gg[i][j]>=0?gg[i][j]:0;
      W[i][j]=tt[i][j]>=0?1:0;
      H[i][j]=T[i][j]*G[i][j];
    }
  }

  auto flatten=
    [&](Matrix A){
      conv.transform(A,false);
      vector<M> dat(h*w);
      for(int i=0;i<h*w;i++) dat[i]=A[i/w][i%w];
      return Ring(dat);
    };

  {
    Matrix id(h,vector<M>(w,M(0)));
    add_id=flatten(id);
    id[0][0]=1;
    mul_id=flatten(id);
  }

  using SM = SquareMatrix<Ring, 4>;
  SM P;
  P[0][0]=flatten(W);
  P[1][0]=flatten(T);P[1][1]=flatten(W);
  P[2][0]=flatten(H);P[2][1]=flatten(G);P[2][2]=flatten(W);
  P[3][0]=flatten(H);P[3][1]=flatten(G);P[3][2]=flatten(W);
  P[3][3]=Ring::mul_identity();

  auto val=P.pow(k)[3][0];

  Matrix res(h,vector<M>(w));
  for(int i=0;i<h*w;i++) res[i/w][i%w]=val.dat[i];
  conv.transform(res,true);

  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(j) cout<<" ";
      cout<<res[i][j];
    }
    cout<<"\n";
  }
  cout<<flush;
  return 0;
}
