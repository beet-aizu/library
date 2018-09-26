#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
template <typename T,typename E>
struct SegmentTree{
  typedef function<T(T,T)> F;
  typedef function<T(T,E)> G;
  int n;
  F f;
  G g;
  T d1;
  E d0;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(int n_,F f,G g,T d1,
	      vector<T> v=vector<T>()):f(f),g(g),d1(d1){
    init(n_);
    if(n_==(int)v.size()) build(n_,v);
  }
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1,d1);
  }
  void build(int n_, vector<T> v){
    for(int i=0;i<n_;i++) dat[i+n-1]=v[i];
    for(int i=n-2;i>=0;i--)
      dat[i]=f(dat[i*2+1],dat[i*2+2]);
  }
  void update(int k,E a){
    k+=n-1;
    dat[k]=g(dat[k],a);
    while(k>0){
      k=(k-1)/2;
      dat[k]=f(dat[k*2+1],dat[k*2+2]);
    }
  }
  T query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return d1;
    if(a<=l&&r<=b) return dat[k];
    T vl=query(a,b,k*2+1,l,(l+r)/2);
    T vr=query(a,b,k*2+2,(l+r)/2,r);
    return f(vl,vr);
  }
  T query(int a,int b){
    return query(a,b,0,0,n);
  }
};

template <typename T,typename E,typename R>
struct SegmentTree2D{
  typedef function<T(void)> C;
  typedef function<R(R,R)> F;
  typedef function<void(T&,int,E)> G;
  typedef function<R(T&,int,int)> V;
  int n;
  F f;
  G g;
  V v;
  R d1;
  vector<T> dat;
  SegmentTree2D(int n_,C c,F f,G g,V v,R d1):
    f(f),g(g),v(v),d1(d1){init(n_,c);}
  
  void init(int n_,C c){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1);
    for(int i=0;i<2*n-1;i++) dat[i]=c();
  }
  
  void update(int x,int y,E e){
    x+=n-1;
    g(dat[x],y,e);
    while(x>0){
      x=(x-1)/2;
      g(dat[x],y,e);
    }
  }
  
  R query(int a,int b,int c,int d,int k,int l,int r){
    if(r<=a||b<=l) return d1;
    if(a<=l&&r<=b) return v(dat[k],c,d);
    R vl=query(a,b,c,d,k*2+1,l,(l+r)/2);
    R vr=query(a,b,c,d,k*2+2,(l+r)/2,r);
    return f(vl,vr);
  }
  
  // [a,b) * [c,d)
  R query(int a,int b,int c,int d){
    return query(a,b,c,d,0,0,n);
  }
};

//END CUT HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int h,w,t,q;
  cin>>h>>w>>t>>q;
  typedef SegmentTree<int,int> T;
  SegmentTree2D<T,int,int> beet(2048,
				[&](){return T(2048,
					       [](int a,int b){return a+b;},
					       [](int a,int b){return a+b;},
					       0);},
				[](int a,int b){return a+b;},
				[](T& t,int k,int e){t.update(k,e);},
				[](T& t,int c,int d){return t.query(c,d);},
				0);
  SegmentTree2D<T,int,int> ushi(2048,
				[&](){return T(2048,
					       [](int a,int b){return a+b;},
					       [](int a,int b){return a+b;},
					       0);},
				[](int a,int b){return a+b;},
				[](T& t,int k,int e){t.update(k,e);},
				[](T& t,int c,int d){return t.query(c,d);},
				0);
  
  typedef pair<int,int> P;
  typedef pair<int,P> PP;
  queue<PP> qq; 
  for(int i=0;i<q;i++){
    int a,c,x1,y1;
    cin>>a>>c>>x1>>y1;
    while(!qq.empty()&&qq.front().first<=a){
      P p=qq.front().second;qq.pop();
      int x=p.first,y=p.second;
      assert(beet.query(x,x+1,y,y+1)==1);
      beet.update(x,y,-1);
      assert(ushi.query(x,x+1,y,y+1)==0);
      ushi.update(x,y,1);
    }
    if(c==0){
      assert(beet.query(x1,x1+1,y1,y1+1)==0);
      beet.update(x1,y1,1);
      qq.push(PP(a+t,P(x1,y1)));
    }
    if(c==1){
      if(ushi.query(x1,x1+1,y1,y1+1)==0) continue;
      ushi.update(x1,y1,-1);
    }
    if(c==2){
      int x2,y2;
      cin>>x2>>y2;
      x2++;y2++;
      cout<<ushi.query(x1,x2,y1,y2)<<" "<<beet.query(x1,x2,y1,y2)<<endl;
    }
  }
  return 0;
}

/*
verified on 2017/10/29
http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=ACPC2017Day3&pid=E
*/
