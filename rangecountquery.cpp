#include<bits/stdc++.h>
using namespace std;
#define int long long
//BEGIN CUT HERE
struct RCQ{
  int n;
  vector<vector<int> > dat;
  RCQ(){}
  RCQ(int n_,int* c){init(n_,c);}
  void init(int n_,int *c){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1);
    build(n_,c);
  }
  void build(int n_,int *c){
    for(int i=0;i<n_;i++)
      dat[n-1+i].push_back(c[i]);
    for(int i=n-2;i>=0;i--){
      for(int j:dat[i*2+1]) dat[i].push_back(j);
      for(int j:dat[i*2+2]) dat[i].push_back(j);
      sort(dat[i].begin(),dat[i].end());
    }
  }
  int query(int a,int b,int x,int k,int l,int r){
    if(r<=a||b<=l) return 0;
    if(a<=l&&r<=b){
      int res=0;
      auto latte=
	lower_bound(dat[k].begin(),dat[k].end(),x);
      res=dat[k].end()-latte;
      return res;
    }
    int vl=query(a,b,x,k*2+1,l,(l+r)/2);
    int vr=query(a,b,x,k*2+2,(l+r)/2,r);
    return vl+vr;
  }
  int query(int a,int b,int x){
    return query(a,b,x,0,0,n);
  }
};
//END CUT HERE

signed main(){
  int n,k;
  cin>>n>>k;
  int a[n],c[n];
  for(int i=0;i<n;i++) cin>>a[i];
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=a[i];
    c[i]=sum-k*(i+1);
  }
  RCQ rcq(n,c);
  int ans=0,tmp=0;
  for(int i=0;i<n;i++){
    ans+=rcq.query(i,n,tmp);
    tmp+=a[i]-k;
  }
  cout<<ans<<endl;
  return 0;
}
/*
  not verified 
  http://arc075.contest.atcoder.jp/tasks/arc075_c
*/
