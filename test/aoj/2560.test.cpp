#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2560"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../convolution/numbertheoretictransform.cpp"
#include "../../convolution/convolution2D.cpp"
#undef call_from_test

#define ERROR "1e-8"

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout<<fixed<<setprecision(12);
  using ll = long long;
  using D = double;

  int n;
  cin>>n;

  vector< vector<int> > as(n,vector<int>(n));
  auto bs(as);

  int cnt=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>as[i][j];
      bs[n-(i+1)][n-(j+1)]=as[i][j];
      cnt+=as[i][j];
    }
  }

  NTT<1> ntt1;
  NTT<2> ntt2;
  using M1 = NTT<1>::M;
  using M2 = NTT<2>::M;
  auto tran1=[&](auto &as,bool f){ntt1.ntt(as,f);};
  auto tran2=[&](auto &as,bool f){ntt2.ntt(as,f);};

  Convolution2D<M1, decltype(tran1)> conv1(tran1);
  Convolution2D<M2, decltype(tran2)> conv2(tran2);

  vector< vector<M1> > as1(n,vector<M1>(n));
  auto bs1(as1);
  vector< vector<M2> > as2(n,vector<M2>(n));
  auto bs2(as2);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      as1[i][j]=M1(as[i][j]);
      as2[i][j]=M2(as[i][j]);
      bs1[i][j]=M1(bs[i][j]);
      bs2[i][j]=M2(bs[i][j]);
    }
  }

  auto cs1=conv1.multiply(as1,bs1);
  auto cs2=conv2.multiply(as2,bs2);

  D dom=(D)cnt*(cnt-1)/2;
  D sum=0;
  map<ll, ll> num;
  const int S = 10000;

  auto calc=
    [&](ll a,ll b){
      const ll r01 = M2(ntt1.md).inv().v;
      b = (b - a) * r01 % ntt2.md;
      if (b < 0) b += ntt2.md;
      a = (a + b * ntt1.md);
      return a;
    };

  for(int i=0;i<(int)cs1.size();i++){
    for(int j=0;j<(int)cs1[i].size();j++){
      ll dd=(ll)(i-(n-1))*(i-(n-1))+(ll)(j-(n-1))*(j-(n-1));
      ll cc=calc(cs1[i][j].v,cs2[i][j].v);
      if(dd==0) cc-=cnt;
      if(cc==0) continue;
      num[dd]+=cc;
      sum+=sqrt(dd)*cc;
      if((int)num.size()>S) num.erase(--num.end());
    }
  }

  cout<<sum/dom/2<<endl;
  for(auto p:num)
    cout<<p.first<<" "<<p.second/2<<"\n";
  cout<<flush;
  return 0;
}
