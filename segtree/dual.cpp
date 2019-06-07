#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
//BEGIN CUT HERE
template <typename E>
struct SegmentTree{
  using H = function<E(E,E)>;
  int n,height;
  H h;
  E ei;
  vector<E> laz;
  SegmentTree(H h,E ei):h(h),ei(ei){}  
  void init(int n_){
    n=1;height=0;
    while(n<n_) n<<=1,height++;
    laz.assign(2*n,ei);
  }
  inline void eval(int k){
    if(laz[k]==ei) return;
    laz[(k<<1)|0]=h(laz[(k<<1)|0],laz[k]);
    laz[(k<<1)|1]=h(laz[(k<<1)|1],laz[k]);
    laz[k]=ei;
  }
  inline void thrust(int k){
    for(int i=height;i;i--) eval(k>>i);
  }
  void update(int a,int b,E x){
    thrust(a+=n);
    thrust(b+=n-1);
    for(int l=a,r=b+1;l<r;l>>=1,r>>=1){
      if(l&1) laz[l]=h(laz[l],x),l++;
      if(r&1) --r,laz[r]=h(laz[r],x);
    }
  }
  E get_val(int a){
    thrust(a+=n);
    return laz[a];
  }
  void set_val(int a,E x){
    thrust(a+=n);
    laz[a]=x;
  }
};
//END CUT HERE

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE
signed AOJ_DSL_2_D(){
  int n,q;
  cin>>n>>q;
  auto h=[](int a,int b){(void)a;return b;};  
  int ei=INT_MAX;
  SegmentTree<int> seg(h,ei);
  seg.init(n);
  for(int i=0;i<q;i++){
    int tp;
    cin>>tp;
    if(tp==0){
      int s,t,x;
      cin>>s>>t>>x;
      seg.update(s,t+1,x);
    }
    if(tp==1){
      int s;
      cin>>s;
      cout<<seg.get_val(s)<<"\n";
    }    
  }
  cout<<flush;
  return 0;  
}
/*
  verified on 2019/06/07
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D&lang=jp
*/

signed AOJ_DSL_2_E(){
  int n,q;
  cin>>n>>q;
  auto h=[](int a,int b){return a+b;};  
  int ei=0;
  SegmentTree<int> seg(h,ei);
  seg.init(n);
  for(int i=0;i<q;i++){
    int tp;
    cin>>tp;
    if(tp==0){
      int s,t,x;
      cin>>s>>t>>x;
      s--;
      seg.update(s,t,x);
    }
    if(tp==1){
      int s;
      cin>>s;
      s--;
      cout<<seg.get_val(s)<<"\n";
    }    
  }
  cout<<flush;
  return 0;  
}
/*
  verified on 2019/06/07
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E&lang=jp
*/
signed main(){
  //AOJ_DSL_2_D();
  //AOJ_DSL_2_E();
  return 0;
}
