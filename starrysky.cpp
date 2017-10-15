#include<bits/stdc++.h>
using namespace std;
#define int long long
//BEGIN CUT HERE
struct StarrySky{
  int n;
  const int def=0;
  vector<int> datm,data;
  StarrySky(){}
  StarrySky(int n_){init(n_);}
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    datm.clear();
    datm.resize(n*2-1,def);
    data.clear();
    data.resize(n*2-1,0);
  }
  void add(int a,int b,int x,int k,int l,int r){
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b){
      data[k]+=x;
      return;
    }
    add(a,b,x,k*2+1,l,(l+r)/2);
    add(a,b,x,k*2+2,(l+r)/2,r);
    datm[k]=max(datm[k*2+1]+data[k*2+1],
		datm[k*2+2]+data[k*2+2]);
  }
  int query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return def;
    if(a<=l&&r<=b) return datm[k]+data[k];
    int vl=query(a,b,k*2+1,l,(l+r)/2);
    int vr=query(a,b,k*2+2,(l+r)/2,r);
    return max(vl,vr)+data[k];
  }
  void add(int a,int b,int x){
    add(a,b,x,0,0,n);
  }
  int query(int a,int b){
    return query(a,b,0,0,n);
  }
};
//END CUT HERE

signed main(){
  int n,q;
  cin>>n>>q;
  StarrySky ss(n);
  for(int i=0;i<q;i++){
    int c,s,t,x;
    cin>>c;
    if(c){
      cin>>x;
      cout<<ss.query(x-1,x)<<endl;
    }else{
      cin>>s>>t>>x;
      ss.add(s-1,t,x);
    }
  }
  return 0;
}

/*
verified on 2017/02/24
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
*/

