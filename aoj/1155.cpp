#include<iostream>
#include<string>
using namespace std;
int o=0;
void rec(string str){
  //cout << str << endl;
  string next,buf;
  if('0'<=str[0]&&str[0]<='2'){
    //cout << str << endl;
    if(str[0]=='2') o++;
    return;
  }
  for(int i=1;i<str.size();i++){
    if('0'<=str[i]&&str[i]<='2') {
      if(str[i-1]=='-') {
	if(str[i]=='0')  str[i]='2';
	else if(str[i]=='2')  str[i]='0';
	str[i-1]=' ';
      }else if(str[i-1]=='*') {
	if(str[i-3]=='('){
	if(str[i]=='0'||str[i-2]=='0') {
	  str[i-3]=' ';
	  str[i-2]=' ';
	  str[i-1]=' ';
	  str[i]='0';
	  str[i+1]=' ';
	}else if(str[i]=='2'&&str[i-2]=='2') {
	  str[i-3]=' ';
	  str[i-2]=' ';
	  str[i-1]=' ';
	  str[i]='2';
	  str[i+1]=' ';
	}else if('0'<=str[i-2]&&str[i-2]<='2'){
	  str[i-3]=' ';
	  str[i-2]=' ';
	  str[i-1]=' ';
	  str[i]='1';
	  str[i+1]=' ';
	}
	}
      }else if(str[i-1]=='+') {
	if(str[i-3]=='('){
	if(str[i]=='2'||str[i-2]=='2') {
	  str[i-3]=' ';
	  str[i-2]=' ';
	  str[i-1]=' ';
	  str[i]='2';
	  str[i+1]=' ';
	}else if(str[i]=='0'&&str[i-2]=='0') {
	  str[i-3]=' ';
	  str[i-2]=' ';
	  str[i-1]=' ';
	  str[i]='0';
	  str[i+1]=' ';
	}else if('0'<=str[i-2]&&str[i-2]<='2'){
	  str[i-3]=' ';
	  str[i-2]=' ';
	  str[i-1]=' ';
	  str[i]='1';
	  str[i+1]=' ';
	}
	}
      }
    }
  }
  for(int i=0;i<str.size();i++){
    if(str[i]!=' ') next+=str[i];
  }
  rec(next);
}
int main(){
  string str,buf;
  cin >> str;
  while(str!="."){
    int p[]={0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2};
    int q[]={0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2,0,1,2};
    int r[]={0,0,0,1,1,1,2,2,2,0,0,0,1,1,1,2,2,2,0,0,0,1,1,1,2,2,2};
    o=0;
    for(int i=0;i<27;i++){
      buf=str;
      for(int j=0;j<str.size();j++){
	if(buf[j]=='P') buf[j]=p[i]+'0';
	if(buf[j]=='Q') buf[j]=q[i]+'0';
	if(buf[j]=='R') buf[j]=r[i]+'0';
      }
      rec(buf);
    }
    cout << o << endl;
    cin >> str;
  }
  
}
