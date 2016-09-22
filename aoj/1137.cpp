#include <iostream>
#include <string>
using namespace std;
string co(int n);
int re(string str);
int main(){
  
  int n,i;
  cin >> n;
  for(i=0;i<n;i++){
    string str1,str2;
    cin >> str1 >> str2;
    cout << co(re(str1)+re(str2)) << endl;
  }
  return 0;
}

string co(int n){
  string b="";
  int k=n/1000;
  string c;
  c[0]=(k+'0');
  if(k==1) b+="m";
  if(1<k&&k<=9) {b+= c[0];b+="m";}
  k=(n%1000)/100;
  c[0]=(k+'0');
  if(k==1) b+="c";
  if(1<k&&k<=9) {b+= c[0];b+="c";}
  k=(n%100)/10;
  c[0]=(k+'0');
  if(k==1) b+="x";
  if(1<k&&k<=9){b+= c[0];b+="x";}
  k=n%10;
  c[0]=(k+'0');
  if(k==1) b+="i";
  if(1<k&&k<=9){b+= c[0];b+="i";}
  return b;
}

int re(string str){
  int n=0;
  int p=str.find("m");
  if(p!=-1){
    if(p==0) n+=1000;
    else n+=(str[p-1]-'0')*1000;
  }
  p=str.find("c");
  if(p!=-1){
    if(p==0||str[p-1]=='m') n+=100;
    else n+=(str[p-1]-'0')*100;
  }
  p=str.find("x");
  
  if(p!=-1){
    if(p==0||str[p-1]=='m'||str[p-1]=='c') n+=10;
    else n+=(str[p-1]-'0')*10;
  }
  p=str.find("i");
  if(p!=-1){
    if(p==0||str[p-1]=='m'||str[p-1]=='c'||str[p-1]=='x') n+=1;
    else n+=(str[p-1]-'0')*1;
  }
  return n;
}
