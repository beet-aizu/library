#include<iostream>
#include<vector>
using namespace std;
class Disjointset {
public:
  vector<int> rank,p;
  Disjointset(){}
  Disjointset(int size){
    rank.resize(size,0);
    p.resize(size,0);
    for(int i=0;i<size;i++) makeSet(i);
  }
  void makeSet(int x){
    p[x]=x;
    rank[x]=0;
  }
  bool same(int x,int y){
    return findSet(x)==findSet(y);
  }
  void unite(int x,int y){
    link(findSet(x),findSet(y));
  }
  void link(int x,int y){
    if(rank[x]>rank[y]) {
      p[y]=x;
    }else {
      p[x]=y;
      if(rank[x]==rank[y]) rank[y]++;
    }
  }
  int findSet(int x){
    if(x!=p[x]) p[x]=findSet(p[x]);
    return p[x];
  }
  
};

int main(){
  int n,q,i;
  cin >> n >> q;
  Disjointset ds = Disjointset(n);
  for(i=0;i<q;i++){
    int com,x,y;
    cin >> com >> x >> y;
    if(com==1) cout << (ds.same(x,y) ? 1:0) << endl;
    else ds.unite(x,y);
  }
}
