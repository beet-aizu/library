#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n;
  int i,j,k;
  while(cin >> n,n){
    map<string,vector<string> > m;
    map<string,bool> b;
    string s,key,f;
    for(i=0;i<n;i++){
      cin >> s;
      for(j=0;j<s.size();j++) if(s[j]==':'||s[j]==','||s[j]=='.') s[j]=' ';
      stringstream ss(s);
      ss >> key;
      if(i==0) f=key;
      while(ss>>s) m[key].push_back(s);
    }
    vector<string> d(m[f]);
    for(i=0;i<d.size();i++) {
      //cout << d[i] << endl;
      if(m[d[i]].size()==0) continue;
      if(b[d[i]]) {
	d.erase(d.begin()+i);
	i--;
	continue;
      }
      b[d[i]]=true;
      //cout << d[i] << endl;
      for(j=0;j<m[d[i]].size();j++){
	d.push_back(m[d[i]][j]);
      }
      d.erase(d.begin()+i);
      i--;
    }
    
    sort(d.begin(),d.end());
    
    //for(i=0;i<d.size();i++) cout << d[i] << endl;
    
    d.erase(unique(d.begin(),d.end()),d.end());
    cout << d.size() << endl;
  }
  return 0;
}
