#include<bits/stdc++.h>
using namespace std;
/*
  multiprecision:
  #include <boost/multiprecision/cpp_int.hpp>
  using Int = boost::multiprecision::cpp_int;
*/
//BEGIN CUT HERE
using Int = __int128_t;
Int abs128(Int val){return val<0?-val:val;}

ostream &operator<<(ostream &os,Int val){
  if(ostream::sentry(os)){
    __uint128_t tmp=abs128(val);
    char buf[64];
    char *d=end(buf);
    do{
      --d;
      *d=char(tmp%10+'0');
      tmp/=10;
    }while(tmp);
    if(val<0) *--d='-';
    int len=end(buf)-d;
    if(os.rdbuf()->sputn(d,len)!=len){
      os.setstate(ios_base::badbit);
    }
  }
  return os;
}

istream &operator>>(istream &is,Int &val){
  string s;
  is>>s;
  val=0;
  for(int i=0;i<(int)s.size();i++)
    if(isdigit(s[i])) val=val*10+s[i]-'0';
  if(s[0]=='-') val*=-1;
  return is;
}

//END CUT HERE

Int extgcd(Int a,Int b,Int& x,Int& y){
  Int d=a;
  if(b!=0){
    d=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }else{
    x=1;y=0;
  }
  return d;
}
signed main(){
  Int n,R;
  Int cnt=0;
  while(cin>>n>>R,n){
    cout<<"Case #"<<++cnt<<":";
    Int r=R;
    vector<Int> v(n);
    for(Int i=0;i<n;i++){
      Int k;
      cin>>k;
      v[i]=k;
    }
    Int g=v[0];
    for(Int i=0;i<n;i++) g=__gcd(g,v[i]);
    if(abs128(r)%g){
      cout<<" Stupid keypad!"<<endl;
      continue;
    }
    vector<Int> ans(n,0);
    auto print=[&](){
                 Int tmp=0;
                 for(Int i=0;i<n;i++) tmp+=v[i]*ans[i];
                 assert(tmp==r);
                 for(Int i=0;i<n;i++) cout<<" "<<ans[i];
                 cout<<endl;
               };
    bool f=0;
    for(Int i=0;i<n;i++){
      if(abs128(r)%v[i]==0){
        ans[i]=r/v[i];
        f=1;
        break;
      }
    }
    if(f){
      print();
      continue;
    }
 
    //cout<<endl;
    Int res=v[0];
    ans[0]=1;
    for(Int i=1;i<n;i++){
      Int k=__gcd(res,v[i]);
      if(k==res) continue;
      Int x,y;
      extgcd(res,v[i],x,y);
      //cout<<res<<" "<<v[i]<<":"<<x<<" "<<y<<endl;
      for(Int j=0;j<i;j++) ans[j]*=x;
      ans[i]=y;
      res=k;
    }
    for(Int i=0;i<n;i++) ans[i]*=(r/res);
    print();
  }
   
  return 0;
}

/*
  verified on 2017/10/29
  http://rhodon.u-aizu.ac.jp:8080/arena/room.jsp?id=3753
*/
