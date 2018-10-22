#include<bits/stdc++.h>
using namespace std;
using Int = long long;
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

signed main(){
  int n;
  cin>>n;
  while(n--){
    string s;
    int p=0;
    cin>>s;s.pop_back();
    cout<<expression(s,p)<<endl;
  }
  return 0;
}

/*
  verified on 2017/11/20
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?lang=jp&id=0109
*/
