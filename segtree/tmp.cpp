#include<bits/stdc++.h>
using namespace std;
//BEGIN CUT HERE

template<typename T> 
struct BIT{
  vector<T> bit;
  int n;
  //1-indexed
  BIT(){init(-1,(T)0);}
  BIT(int n_,T d){init(n_,d);}
  void init(int n_,T d){
    n=n_;
    bit.clear();
    bit.resize(n+1,d);
  }
  T sum(int i){
    T s=0;
    for(int x=i;x>0;x-=(x&-x))
      s+=bit[x];
    return s;
  }
  void add(int i,T a){
    if(i==0) return;
    for(int x=i;x<=n;x+=(x&-x))
      bit[x]+=a;
  }
  T sum0(int i){
    return sum(i+1);
  }
  void add0(int i,T a){
    add(i+1,a);
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
  SegmentTree2D(int n_,C c,F f,G g,V v,R d1){
    this->f=f;
    this->g=g;
    this->v=v;
    this->d1=d1;
    init(n_,c);
  }
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
  typedef BIT<int> T;
  SegmentTree2D<T,int,int> beet(2048,
				[&](){return T(2048,0);},
				[](int a,int b){return a+b;},
				[](T& t,int k,int e){t.add(k,e);},
				[](T& t,int c,int d){
				  return t.sum(d-1)-t.sum(c-1);
				},
				0);
  SegmentTree2D<T,int,int> ushi(2048,
				[&](){return T(2048,0);},
				[](int a,int b){return a+b;},
				[](T& t,int k,int e){t.add(k,e);},
				[](T& t,int c,int d){
				  return t.sum(d-1)-t.sum(c-1);
				},
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
