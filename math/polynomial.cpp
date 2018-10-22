#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct Polynomial{
  using P = Polynomial;
  vector<int> co;
  Polynomial():co(1,1){}
  Polynomial(int s):co(s,0){}
  Polynomial(vector<int> co):co(co){}
  
  size_t size() const{
    return co.size();
  };

  void shrink(){
    while(co.size()>1u&&!co.back())
      co.pop_back();
  }

  void reduce(){
    int g=abs(co.back());
    if(!g) return;
    for(int c:co)
      if(c!=0) g=__gcd(g,abs(c));
    if(co.back()<0) g*=-1;
    for(int &c:co) c/=g;
  }

  void print(){
    shrink();
    reduce();
    int n=size(),flg=0;
    for(int i=n-1;i>0;i--){
      if(!co[i]) continue;
      flg=1;
      if(i!=n-1&&co[i]>0) cout<<"+";
      if(co[i]==-1) cout<<"-";
      else if(co[i]!=1) cout<<co[i];
      
      cout<<"x";
      if(i!=1) cout<<"^"<<i;
    }
    if(co[0]){
      if(flg&&co[0]>0) cout<<"+";
      cout<<co[0];
    }
    cout<<endl;
  }

  int operator[](int i) const{
    return co[i];
  }

  int &operator[](int i){
    return co[i];
  }

  P operator-() const{
    P res=*this;
    for(int &c:res.co) c*=-1;
    return res;
  }

  P operator+(const P &a) const{
    int n=size(),m=a.size();
    P res(max(n,m));
    for(int i=0;i<n;i++) res[i]+=co[i];
    for(int i=0;i<m;i++) res[i]+=a[i];
    return res;
  }
  P operator-(const P &a) const{return *this+(-a);};

  P operator*(const P &a) const{
    int n=size(),m=a.size();
    P res(n+m);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        res[i+j]+=co[i]*a[j];
    res.shrink();
    return res;
  }

  P pow(const P &a,int k) const{
    P res;
    for(int i=0;i<k;i++) res=res*a;
    return res;
  }
  
  pair<P, P> divide(const P &a) const{
    int n=size(),m=a.size(),s=n-m+1;
    if(s<0) return make_pair(P(1),*this);
    P div(s);
    P rest=*this;
    for(int i=0;i<s;i++){
      if(rest[n-(i+1)]%a[m-1]!=0)
        for(int &c:rest.co) c*=a[m-1];
      int d=rest[n-(i+1)]/a[m-1];
      div[s-(i+1)]=d;
      for(int j=m;j>0;j--) rest[n-(i+j)]-=a[m-j]*d;
    }
    return make_pair(div,rest);
  }
  
  P operator/(const P &a) const{return divide(a).first;};
  P operator%(const P &a) const{return divide(a).second;};  
};

Polynomial gcd(Polynomial a,Polynomial b){
  a.shrink();a.reduce();
  b.shrink();b.reduce();
  if(a.size()<b.size()) swap(a,b);
  if(b.size()==1u&&!b[0]) return a;
  return gcd(b,a%b);
}

//END CUT HERE

Polynomial expr(string s,int &p);
Polynomial factor(string s,int &p);
Polynomial term(string s,int &p);
int number(string s,int &p);

Polynomial expr(string s,int &p){
  //cout<<"expr"<<endl;
  Polynomial res;
  if(s[p]=='-'){
    p++;
    res=-factor(s,p);
  }else res=factor(s,p);
  
  while(p<(int)s.size()){
    //res.print();
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
  //res.print();
  return res;
}
Polynomial factor(string s,int &p){
  //cout<<"factor"<<endl;
  Polynomial res=term(s,p);
  while(p<(int)s.size()){
    //res.print();
    if(s[p]=='+') break;
    if(s[p]=='-') break;
    if(s[p]==')') break;
    res=res*term(s,p);
  }
  return res;
}
Polynomial term(string s,int &p){
  //cout<<"term"<<endl;
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
    //res.print();
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
      //res.print();
      return res;
    }
    Polynomial res(2);
    res[1]=v;
    //res.print();
    return res;
  }
  Polynomial res;
  res[0]=v;
  //res.print();
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

//INSERT ABOVE HERE
signed main(){
  string s,t;
  while(cin>>s,s!="."){
    cin>>t;
    Polynomial ps=calc(s);
    Polynomial pt=calc(t);
    if(0){
      cout<<endl;
      ps.print();
      pt.print();
      cout<<endl;
    }
    Polynomial ans=gcd(ps,pt);
    ans.print();
  }
  return 0;
}
