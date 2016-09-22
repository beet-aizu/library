#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n,m,a;
  cin >> n;
  while(n!=0){
    int i,j,k,l;
    int v[51][31]={{}};
    for(i=0;i<n;i++){
      cin >> m;
      for(j=0;j<m;j++){
	cin >> a;
	v[i][a]=1;
      }
    }
    vector <int> g[51];
    vector <int> p[51];
    for(i=0;i<n;i++) g[i].push_back(i);
    bool f =false,x;
    for(i=1;i<31;i++){
      //cout << "day" << i << endl;
      for(k=0;k<n;k++) {
	sort(g[k].begin(),g[k].end());
	g[k].erase(unique(g[k].begin(), g[k].end()), g[k].end());
	p[k].clear();
	for(l=0;l<g[k].size();l++) p[k].push_back(g[k][l]);
	//for(l=0;l<p[k].size();l++) cout << p[k][l] << " ";
	//cout << endl;
      }
      for(j=0;j<n;j++){
	if(v[j][i]==0) continue;
	for(k=j+1;k<n;k++){
	  if(v[k][i]==0) continue;
	  //cout << i << ":" << j << ":" << k << endl;
	  for(l=0;l<p[j].size();l++) g[k].push_back(p[j][l]);
	  for(l=0;l<p[k].size();l++) g[j].push_back(p[k][l]);
	}
      }
      bool li[51];
      for(j=0;j<n;j++) {
	for(k=0;k<n;k++) li[k]=false;
	for(k=0;k<g[j].size();k++) {
	  //cout << g[j][k] << " ";
	  li[g[j][k]]=true;
	}
	//cout << endl;
	x=true;
	for(k=0;k<n;k++) if(!li[k]) x=false;
	if(x){
	  f=true;
	  break;
	}
      }
      if(f) {
	cout << i << endl;
	break;
      }
    }
    if(!f) cout << -1 << endl;
    cin >> n;
  }
}
