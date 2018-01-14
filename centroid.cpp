#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct Centroid{
  int n;
  vector<int> sz,centroid;
  vector<vector<int> > G;
  Centroid(){}
  Centroid(int n):n(n),sz(n),G(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void input(int m,int offset=0){
    for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      add_edge(u+offset,v+offset);
    }
  }
  
  void dfs(int v,int p) {
    int ok=1;
    for (int u:G[v]){
      if(u==p) continue;
      dfs(u,v);
      sz[v]+=sz[u];
      ok&=(sz[u]<=n/2);
    }
    ok&=(n-sz[v]<=n/2);
    if(ok) centroid.push_back(v);
  };
  
  vector<int> build(int r=0) {
    fill(sz.begin(),sz.end(),0);
    queue<int> q;
    sz[r]=1;
    q.emplace(r);
    while(!q.empty()){
      int v=q.front();q.pop();
      for(int u:G[v]){
	if(sz[u]) continue;
	sz[u]=1;
	q.emplace(u);
      }
    }
    n=accumulate(sz.begin(),sz.end(),0);
    centroid.clear();
    dfs(r,-1);
    return centroid;
  }
};
//END CUT HERE

signed DWANGO2018QUAL_E(){
  int n,q;
  cin>>n>>q;
  Centroid C(n);
  C.input(n-1,-1);
  
  int r=0;
  for(int l=0;l<q;l++){
    auto c=C.build(r);
    auto rmv=[](vector<int> &v,int x){
      v.erase(find(v.begin(),v.end(),x));
    };
    if(c.size()==2u){
      cout<<"? "<<c[0]+1<<" "<<c[1]+1<<endl;
      int x;
      cin>>x;
      if(x==c[0]+1){
	r=c[0];
	rmv(C.G[c[0]],c[1]);
      }
      if(x==c[1]+1){
	r=c[1];
	rmv(C.G[c[1]],c[0]);
      }
    }else{
      using P = pair<int, int>;
      vector<P> vp;
      for(int u:C.G[c[0]])
	vp.emplace_back(C.sz[u],u);
      sort(vp.rbegin(),vp.rend());
      if(vp.empty()){
	cout<<"! "<<c[0]+1<<endl;
	return 0;
      }
      if(vp.size()==1u){
	c.emplace_back(vp[0].second);
	cout<<"? "<<c[0]+1<<" "<<c[1]+1<<endl;
	int x;
	cin>>x;
	cout<<"! "<<x<<endl;
	return 0;
      }else{
	int a=vp[0].second;
	int b=vp[1].second;
	cout<<"? "<<a+1<<" "<<b+1<<endl;
	int x;
	cin>>x;
	if(x==0){
	  r=c[0];
	  rmv(C.G[c[0]],a);
	  rmv(C.G[c[0]],b);
	}
	if(x==a+1){
	  r=a;
	  rmv(C.G[a],c[0]);
	}
	if(x==b+1){
	  r=b;
	  rmv(C.G[b],c[0]);
	}
      }
    }
  }
  while(1);
}

/*
  verified on 2018/01/14
  https://beta.atcoder.jp/contests/dwacon2018-prelims/tasks/dwacon2018_prelims_e
*/


signed main(){
  DWANGO2018QUAL_E();
  return 0;
}
