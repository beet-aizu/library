#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1293"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../polynomial/polynomial.cpp"
#undef call_from_test

Polynomial expr(string s,int &p);
Polynomial factor(string s,int &p);
Polynomial term(string s,int &p);
int number(string s,int &p);

Polynomial expr(string s,int &p){
  Polynomial res;
  if(s[p]=='-'){
    p++;
    res=-factor(s,p);
  }else res=factor(s,p);

  while(p<(int)s.size()){
    if(s[p]=='+'){
      p++;
      res=res+factor(s,p);
      continue;
    }
    if(s[p]=='-'){
      p++;
      res=res-factor(s,p);
      continue;
    }
    break;
  }
  return res;
}

Polynomial factor(string s,int &p){
  Polynomial res=term(s,p);
  while(p<(int)s.size()){
    if(s[p]=='+') break;
    if(s[p]=='-') break;
    if(s[p]==')') break;
    res=res*term(s,p);
  }
  return res;
}

Polynomial term(string s,int &p){
  if(s[p]=='('){
    p++;
    Polynomial res=expr(s,p);
    assert(s[p]==')');
    p++;
    if(s[p]=='^'){
      p++;
      int k=number(s,p);
      res=res.pow(res,k);
    }
    return res;
  }
  int v=(s[p]=='x'?1:number(s,p));
  if(p<(int)s.size()&&s[p]=='x'){
    p++;
    if(p<(int)s.size()&&s[p]=='^'){
      p++;
      int k=number(s,p);
      Polynomial res(k+1);
      res[k]=v;
      return res;
    }
    Polynomial res(2);
    res[1]=v;
    return res;
  }
  Polynomial res;
  res[0]=v;
  return res;
}

int number(string s,int &p){
  int res=0;
  while(p<(int)s.size()&&isdigit(s[p]))
    res=res*10+(s[p++]-'0');
  return res;
}

Polynomial calc(string s){
  int p=0;
  return expr(s,p);
}

signed main(){
  string s,t;
  while(cin>>s,s!="."){
    cin>>t;
    Polynomial ps=calc(s);
    Polynomial pt=calc(t);
    Polynomial ans=gcd(ps,pt);
    ans.print();
  }
  return 0;
}
