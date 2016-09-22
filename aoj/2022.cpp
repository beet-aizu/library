#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<string> v;
int n;
int d[10][10]={{}};
string ans;

void solve(vector<int> l){
  string b;
  b=v[l[0]];
  for(int i=1;i<n;i++){
    b+=v[l[i]].substr(d[l[i-1]][l[i]],v[l[i]].size()-d[l[i-1]][l[i]]);
    if(b.size()>ans.size()) return;
  }
  //cout << b << endl;
  if(ans.size()>b.size()) ans=b;
  if(ans.size()==b.size()&&b<ans) ans=b;
}

int main(){
  while(cin >> n,n){
    string s;
    int i,j,k;
    v.clear();
    for(i=0;i<n;i++){
      cin >> s;
      v.push_back(s);
    }

    
    for(i=0;i<10;i++){
      for(j=0;j<10;j++){
	d[i][j]=0;
      }
    }
    
    bool f;
    for(i=0;i<n;i++){
      f=false;
      for(j=0;j<n;j++){
	if(i==j) continue;
	if(v[j].find(v[i])!=-1) f=true;	
      }
      if(f){
	v.erase(v.begin()+i);
	i--;n--;
      }
    }
    
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	if(i==j) continue;
	for(k=1;k<=v[i].size();k++){
	  if(v[i].substr(v[i].size()-k,k)==v[j].substr(0,k))
	    d[i][j]=max(d[i][j],k);
	}
      }
    }

    
    vector<int> l;
    l.clear();
    ans="";
    for(i=0;i<n;i++) {
      l.push_back(i);
      ans+=v[i];
    }

    do{
      solve(l);
    }while(next_permutation(l.begin(),l.end()));
    
    cout << ans << endl;
    
  }
  return 0;
}
