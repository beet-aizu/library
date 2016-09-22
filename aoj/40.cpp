#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  int i,j,k,l;
  string s,o;
  getline(cin,s);
  while(n--){
    getline(cin,s);
    bool f =false;
    
    for(i=1;i<26;i++){
      if(f) break;
      if(i%2==0||i%13==0) continue;
      for(j=0;j<26;j++){
	o=s;
	for(k=0;k<s.size();k++){
	  if(s[k]==' ') continue;
	  o[k]=(((s[k]-'a')*i+j)%26)+'a';
	}
	
	if(o.find("this")!=-1||o.find("that")!=-1)
	  f=true;
	
	if(f){
	  cout << o << endl;
	  break;
	}
      }
    }
  }
  
  return 0;
}
