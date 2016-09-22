#include<bits/stdc++.h>
using namespace std;
bool f;
bool e[26][26];
void dfs(int x,int d){
  //cout << x << ":" << d << endl;
  if(d>26) {
    f=false;
    return;
  }
  if(!f) return;
  for(int i=0;i<26;i++){
    if(e[x][i]) dfs(i,d+1);
  }
}
int main(){
  int n;
  while(cin>>n,n){
    int i,j,k;
    vector<string> v;
    string s;
    memset(e,false,sizeof(e));
    for(i=0;i<n;i++){
      cin >> s;
      v.push_back(s);
    }
    f=true;
    for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
	if(v[i].find(v[j])==0&&v[i].size()>v[j].size()) f=false;
	int x=min(v[i].size(),v[j].size());
	for(k=0;k<x;k++){
	  if(v[i][k]==v[j][k]) continue;
	  e[v[i][k]-'a'][v[j][k]-'a']=true;
	  break;
	}
      }
    }
    for(i=0;i<26;i++){
      if(f)dfs(i,0);
    }
    if(f) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
