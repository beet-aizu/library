#include<iostream>
using namespace std;
int par[51];
int ra[51];
void init(int n){
  for(int i=0;i<n;i++){
    par[i]=i;
    ra[i]=0;
  }
}
int find(int x){
  if(par[x]==x) return x;
  else return par[x]=find(par[x]);
}
void unite(int x,int y){
  x=find(x);
  y=find(y);
  if(x==y) return;
  if(ra[x]<ra[y]) par[x]=y;
  else {
    par[y]=x;
    if(ra[x]==ra[y]) ra[x]++;
  }
}
bool same(int x,int y){
  return find(x)==find(y);
}
int main(){
  int n,m,a;
  cin >> n;
  while(n!=0){
    int i,j,k;
    int v[51][31]={{}};
    for(i=0;i<n;i++){
      cin >> m;
      for(j=0;j<m;j++){
	cin >> a;
	v[i][a]=1;
      }
    }
    init(n);
    bool f =false,x;
    for(i=1;i<31;i++){
      for(j=0;j<n;j++){
	if(v[j][i]==0) continue;
	for(k=j+1;k<n;k++){
	  if(v[k][i]==0) continue;
	  unite(j,k);
	}
      }
      x=false;
      for(j=1;j<n;j++){
	if(!same(0,j)) x=true;
      }
      if(!x) {
	cout << i << endl;
	f=true;
	break;
      }
    }
    if(!f) cout << -1 << endl;
    cin >> n;
  }
}
