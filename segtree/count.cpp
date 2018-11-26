#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
using P = pair<int, int>;
struct SegmentTree{
  int n;
  vector<P> v;
  vector<vector<int> > dat;
  SegmentTree(){};
  SegmentTree(int n,vector<P> v):v(v){init(n);build();};
  
  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,vector<int>());
  }  
  void build(){
    for(auto p:v)
      dat[p.first+n].emplace_back(p.second);    
    for(int i=0;i<n;i++)
      sort(dat[i+n].begin(),dat[i+n].end());
    
    for(int i=n-1;i;i--){
      merge(dat[(i<<1)|0].begin(),dat[(i<<1)|0].end(),
            dat[(i<<1)|1].begin(),dat[(i<<1)|1].end(),
            back_inserter(dat[i]));
    }
  }
  // [a,b) * [c,d)
  inline int query(int a,int b,int c,int d){
    int res=0;
    auto calc=[a,b,c,d](vector<int> &x){
                auto latte=lower_bound(x.begin(),x.end(),d);
                auto malta=lower_bound(x.begin(),x.end(),c);
                return int(latte-malta);
              };
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) res+=calc(dat[l++]);
      if(r&1) res+=calc(dat[--r]);
    }
    return res;
  }
  
};

//END CUT HERE
signed ABC106_D(){
  int n,m,q;
  scanf("%d %d %d",&n,&m,&q);
  vector<int> x(m),y(m);
  for(int i=0;i<m;i++) scanf("%d %d",&x[i],&y[i]);
 
  vector<P> vp;
  for(int i=0;i<m;i++) vp.emplace_back(x[i],y[i]);
 
  SegmentTree seg(n+1,vp);
 
  for(int i=0;i<q;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",seg.query(a,b+1,a,b+1));    
  }
  return 0;
}

signed main(){
  ABC106_D();
  return 0;
}
