#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
  string s,b,n;
  while(cin>>s,s!="."){
    bool f=true;
    int i,j,k,o,m;
    b="";
    while(f){
      f=false;
      o=0;m=0;
      for(i=0;i<s.size();i++){
	if(s[i]=='[') {
	  o++;
	  m=max(m,o);
	}
	if(s[i]==']') o--;
      }
      for(i=0;i<s.size();i++){
	if(s[i]>='A'&&s[i]<='Z'){
	  k=1;j=(s[i]-'A');
	  while(i-k>=0){
	    if(s[i-k]=='+') {
	      j++;
	      s[i-k]=' ';
	      k++;
	      continue;
	    }
	    if(s[i-k]=='-') {
	      j--;
	      s[i-k]=' ';
	      k++;
	      continue;
	    }
	    break;
	  }
	  s[i]='A'+(104+j)%26;
	}
	if(s[i]=='?'){
	  k=1;
	  while(i-k>=0){
	    if(s[i-k]=='+'||s[i-k]=='-') {
	      s[i-k]=' ';
	      k++;
	      continue;
	    }
	    break;
	  }
	  s[i]='A';
	}
      }
      b="";
      for(i=0;i<s.size();i++) if(s[i]!=' ') b+=s[i];
      if(s.size()>b.size()) f=true;
      s=b;

      o=0;
      for(i=0;i<s.size();i++){
	if(s[i]=='['){
	  o++;
	  if(o==m){
	    k=1;
	    while(s[i+k]!=']') k++;
	    n=s.substr(i+1,k-1);
	    //cout << n << endl;
	    reverse(n.begin(),n.end());
	    s.replace(i+1,k-1,n);
	    s[i]=' ';s[i+k]=' ';
	    o--;
	  }
	}
	if(s[i]==']') o--;
	
      }
      b="";
      for(i=0;i<s.size();i++) if(s[i]!=' ') b+=s[i];
      if(s.size()>b.size()) f=true;
      s=b;
      
      //cout << s << endl;
    }
    cout << s << endl;
    s="";
  }
  return 0;
}
