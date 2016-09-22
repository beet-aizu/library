#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
int main(){
  int n;
  while(cin>>n,n){
    vector<string> v;
    string s;
    int m=0;
    int i,j;
    for(i=0;i<n;i++){
      cin>>s;
      string b;
      b+=s[0];
      for(j=1;j<s.size();j++){
	if(s[j-1]=='a'||s[j-1]=='i'||s[j-1]=='u'||
	   s[j-1]=='e'||s[j-1]=='o'){
	  b+=s[j];
	}
      }
      m=max(m,(int)b.size());
      v.push_back(b);
    }
    bool f=false;
    for(i=1;i<=m;i++){
      set<string> ss;
      for(j=0;j<n;j++){
	string sub=v[j];
	if(sub.size()>i) sub=v[j].substr(0,i);
	//cout << sub << endl;
	if(ss.find(sub)==ss.end()) ss.insert(sub);
	else break;
      }
      if(ss.size()==n){
	f=true;
	break;
      }
    }
    if(f) cout << i << endl;
    else cout << -1 << endl;
  }
}
