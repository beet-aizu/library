#pragma once

#ifndef call_from_test
#include <bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
template<typename T,typename Transformer>
struct Convolution2D{
  using Matrix = vector< vector<T> >;
  const Transformer tran;
  Convolution2D(Transformer tran):tran(tran){}

  void transpose(Matrix &as){
    int n=as.size(),m=as[0].size();
    Matrix cs(as);
    as.assign(m,vector<T>(n));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        as[j][i]=cs[i][j];
  }

  void transform(Matrix &as,bool f){
    for(int t=0;t<2;t++){
      for(auto &a:as) tran(a,f);
      transpose(as);
    }
  }

  Matrix multiply(Matrix as,Matrix bs){
    int nt=as.size()+bs.size()-1;
    int mt=as[0].size()+bs[0].size()-1;
    int n=1,m=1;
    while(n<nt) n<<=1;
    while(m<mt) m<<=1;
    as.resize(n);bs.resize(n);
    for(int i=0;i<n;i++){
      as[i].resize(m,T(0));
      bs[i].resize(m,T(0));
    }
    transform(as,0);transform(bs,0);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        as[i][j]*=bs[i][j];
    transform(as,1);
    return as;
  }
};
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
#endif
