#include <iostream>
#include <string>
using namespace std;
int main(){
  string str;
  getline(cin,str);
  int ro,so,i,j,k,b[1000]={},p=0;
  while(str.size()!=1||str[0]!='.'){
    ro=0;so=0;k=0;p=0;
    for(i=0;i<str.size();i++){
      if(str[i]=='(') {
	ro++;
	p++;
	b[p]=1;
      }
      if(str[i]=='[') {
	so++;
	p++;
	b[p]=2;
      }	  
      if(str[i]==')') {
	if(b[p]==1) {
	  ro--;
	  p--;
	}
	else k=1;
      }
      if(str[i]==']') {
	if(b[p]==2) {
	  so--;
	  p--;
	}
	else k=1;
      }

      if(ro<0||so<0) k=1;
    }
    if(k==0&&ro==0&&so==0) cout << "yes" << endl;
    else cout << "no" << endl;
    getline(cin,str);
  }
  return 0;
}
