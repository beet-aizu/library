#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;


struct RangeTypes{  
  template <typename T>
  using gtree = tree<T, null_type, less<T>, rb_tree_tag,
                     tree_order_statistics_node_update>;
  struct range{
    int l,r,c;
    range(){}
    range(int l,int r,int c):l(l),r(r),c(c){}
    bool operator<(const range &a)const{
      return l<a.l;
    }
  };
  
  int n,m,time;
  vector<int> nxt,dat,upd;
  set<int> sx;

  set<range> sr;
  vector<set<range> > se;
  vector<gtree<int> > rc;
  
  RangeTypes(int n_,int m):m(m),time(0),se(m+1){
    n=1;
    while(n<n_+1) n<<=1;

    nxt.assign(n,0);
    iota(nxt.begin(),nxt.end(),1);

    sr.emplace(0,n,m);
    se[m].emplace(0,n,m);
    
    dat.assign(n<<1,0);
    upd.assign(n<<1,0);
    
    rc.resize(n<<1);
    for(int i=0;i<n;i++)
      for(int k=i+n;k;k>>=1)
        rc[k].insert(nxt[i]);
    
    for(int i=0;i<n*2;i++)
      rc[i].insert(INT_MAX);
  }

  int get(int k) const{
    k+=n;
    int t=upd[k],c=dat[k];
    while(k>>=1)
      if(t<upd[k]) t=upd[k],c=dat[k]; 
    return c;
  }
  
  void reset(int a,int v){
    if(nxt[a]==v) return;
    int k=a+n;
    while(k){
      rc[k].erase(nxt[a]);
      rc[k].insert(v);
      k>>=1;
    }
    nxt[a]=v;
  }

  void update(const int a,const int b,const int c){
    assert(a<b);
    assert(c<m);
    time++;
    // gather information
    vector<int> vx,vc;
    if(a) vc.emplace_back(get(a-1));
    vc.emplace_back(c);
    for(auto it=sx.lower_bound(a);it!=sx.end();++it){
      if(*it>=b) break;
      vx.emplace_back(*it);
      vc.emplace_back(get(*it));
    }
    if(vx.empty()||vx.back()!=b-1){
      vx.emplace_back(b-1);
      vc.emplace_back(get(b-1));
    }
    
    vector<range> vr;
    {
      auto it=sr.lower_bound(range(a,0,0));
      if(it!=sr.begin()) --it;
      if(it->l<a&&a<it->r) vr.emplace_back(*it);
    }    
    for(auto it=sr.lower_bound(range(a,0,0));it!=sr.end();++it){
      if(it->l>=b) break;
      vr.emplace_back(*it);
    }
    
    // update information
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
      if(l&1) dat[l]=c,upd[l]=time,l++;
      if(r&1) --r,dat[r]=c,upd[r]=time;
    }
    
    for(auto r:vr){
      sr.erase(r);
      se[r.c].erase(r);
    }
    sr.emplace(a,b,c);
    se[c].emplace(a,b,c);
    
    {
      auto r=vr.front();
      if(r.l<a){
        sr.emplace(r.l,a,r.c);
        se[r.c].emplace(r.l,a,r.c);
      }
    }
    {
      auto r=vr.back();
      if(b<r.r){
        sr.emplace(b,r.r,r.c);
        se[r.c].emplace(b,r.r,r.c);
      }
    }
    
    for(int x:vx){
      if(x<b-1){
        if(sx.count(x)) sx.erase(x);
        reset(x,x+1);
      }
    }
    
    {
      int nb=n+(++time);
      auto it=se[c].upper_bound(range(a,0,0));
      if(it!=se[c].end()) nb=it->l;
      reset(b-1,nb);
      if(nb!=b) sx.emplace(b-1);
    }
        
    sort(vc.begin(),vc.end());
    vc.erase(unique(vc.begin(),vc.end()),vc.end());
    for(int x:vc){
      auto it=se[x].lower_bound(range(a,0,0));
      if(it==se[x].begin()) continue;
      int ny=(it==se[x].end()?n+(++time):it->l),y=(--it)->r-1;
      reset(y,ny);
      if(ny!=y+1) sx.emplace(y);
    }    
  }
  
  int query(const int a,const int b,const int c,const int d) const{
    int res=0;
    auto calc=[&](const gtree<int> &g){
                int lb=*g.lower_bound(c);
                int ub=*g.upper_bound(d);
                return g.order_of_key(ub)-g.order_of_key(lb);                
              };
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1){
      if(l&1) res+=calc(rc[l++]);
      if(r&1) res+=calc(rc[--r]);      
    }
    return res;
  }
  
  int count(const int a,const int b) const{
    return query(a,b,b,INT_MAX-1);
  }  
};


using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


struct EulerTour{
  int n,pos;
  vector<vector<int> > G;
  vector<int> ls,rs;
  
  EulerTour(){}
  EulerTour(int n):n(n),G(n),ls(n),rs(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void dfs(int v,int p){
    ls[v]=pos++;
    for(int u:G[v])
      if(u!=p) dfs(u,v);
    rs[v]=pos;
  }
  
  void build(int r=0){
    pos=0;
    dfs(r,-1);
  }
  
};

//INSERT ABOVE HERE
signed main(){
  int T;
  scanf("%d",&T);

  int casecnt=0;
  for(int t=1;t<=T;t++){
    printf("Case #%d:\n",t);    
    int n;
    scanf("%d",&n);
    EulerTour et(n);
    for(int i=1;i<n;i++){
      int u,v;
      scanf("%d %d",&u,&v);
      u--;v--;
      et.add_edge(u,v);
    }
    vector<int> c(n);
    for(int i=0;i<n;i++) scanf("%d",&c[i]);

    et.build();
    int q;
    scanf("%d",&q);

    if(n<=5000||q<=5000||casecnt>=2){
      vector<int> val(n),used(n+1,-1);
      for(int i=0;i<n;i++) val[et.ls[i]]=c[i];
      
      for(int i=0;i<q;i++){
        int type;
        scanf("%d",&type);
        if(type==0){
          int u,w;
          scanf("%d %d",&u,&w);
          u--;
          for(int j=et.ls[u];j<et.rs[u];j++) val[j]=w;
        }
        if(type==1){
          int u;
          scanf("%d",&u);
          u--;
          int cnt=0;          
          for(int j=et.ls[u];j<et.rs[u];j++){
            if(used[val[j]]!=i) cnt++;
            used[val[j]]=i;
          }          
          printf("%d\n",cnt);
        }
      }
      continue;
    }
    casecnt++;
    
    RangeTypes rt(n,n+10);
    function<void(int, int)> dfs=
      [&](int v,int p){
        rt.update(et.ls[v],et.rs[v],c[v]);
        for(int u:et.G[v])
          if(p!=u) dfs(u,v);
      };
    dfs(0, -1);
    
    for(int i=0;i<q;i++){
      int type;
      scanf("%d",&type);

      if(type==0){
        int u,w;
        scanf("%d %d",&u,&w);
        u--;
        rt.update(et.ls[u],et.rs[u],w);
      }
      if(type==1){       
        int u;
        scanf("%d",&u);
        u--;
        printf("%d\n",rt.count(et.ls[u],et.rs[u]));
      }
    }
  }
  return 0;
}
