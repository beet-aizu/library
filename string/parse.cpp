#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
int expression(string,int&);
int term(string,int&);
int factor(string,int&);
int number(string,int&);

bool f;

int expression(string s,int& p){
  int res=term(s,p);
  while(p<(int)s.size()){
    if(s[p]=='+'){
      p++;
      res+=term(s,p);
      continue;
    }
    if(s[p]=='-'){
      p++;
      res-=term(s,p);
      continue;
    }
    break;
  }
  return res;
}

int term(string s,int& p){
  int res=factor(s,p);
  while(p<(int)s.size()){
    if(s[p]=='*'){
      p++;
      res*=factor(s,p);
      continue;
    }
    if(s[p]=='/'){
      p++;
      int tmp=factor(s,p);
      if(tmp==0){
        f=1;
        break;
      }
      res/=tmp;
      continue;
    }
    break;
  }
  return res;
}

int factor(string s,int& p){
  int res;
  if(s[p]=='('){
    p++;
    res=expression(s,p);
    p++;
  }else{
    res=number(s,p);
  }
  return res;
}

int number(string s,int& p){
  int res=0;
  while(p<(int)s.size()&&isdigit(s[p]))
    res=res*10+s[p++]-'0';
  return res;
}
//END CUT HERE
#ifndef call_from_test
signed main(){
  return 0;
}
#endif
