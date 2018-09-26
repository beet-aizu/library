#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct Dice{
  int s[6];
  void roll(char c){
    //the view from above
    // N
    //W E
    // S
    //s[0]:top
    //s[1]:south
    //s[2]:east
    //s[3]:west
    //s[4]:north
    //s[5]:bottom
    int b;
    if(c=='E'){
      b=s[0];
      s[0]=s[3];
      s[3]=s[5];
      s[5]=s[2];
      s[2]=b;
    }
    if(c=='W'){
      b=s[0];
      s[0]=s[2];
      s[2]=s[5];
      s[5]=s[3];
      s[3]=b;
    }
    if(c=='N'){
      b=s[0];
      s[0]=s[1];
      s[1]=s[5];
      s[5]=s[4];
      s[4]=b;
    }
    if(c=='S'){
      b=s[0];
      s[0]=s[4];
      s[4]=s[5];
      s[5]=s[1];
      s[1]=b;
    }
    
    // migi neji 
    if(c=='R'){
      b=s[1];
      s[1]=s[2];
      s[2]=s[4];
      s[4]=s[3];
      s[3]=b;
    }
    
    if(c=='L'){
      b=s[1];
      s[1]=s[3];
      s[3]=s[4];
      s[4]=s[2];
      s[2]=b;
    }
    
  }
  int top() {
    return s[0];
  }
  int hash(){
    int res=0;
    for(int i=0;i<6;i++) res=res*256+s[i];
    return res;
  }
};
vector<Dice> makeDices(Dice d){
  vector<Dice> res;
  for(int i=0;i<6;i++){
    Dice t(d);
    if(i==1) t.roll('N'); 
    if(i==2) t.roll('S'); 
    if(i==3) t.roll('S'),t.roll('S');
    if(i==4) t.roll('L'); 
    if(i==5) t.roll('R'); 
    for(int k=0;k<4;k++){
      res.push_back(t);
      t.roll('E');
    }
  }
  return res;
}
//END CUT HERE

signed ITP1_11_A(){
  Dice d;
  for(int i=0;i<6;i++) cin >> d.s[i];
  string s;cin >> s;
  for(int i=0;i<(int)s.size();i++) d.roll(s[i]);
  cout << d.top() << endl;
  return 0;
}

/*
  verified on 2018/02/09
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A
*/

signed AOJ_0502(){
  Int n;
  while(cin>>n,n){
    Dice d;
    for(Int i=0;i<6;i++) d.s[i]=i+1;

    Int ans=d.top();
    for(Int i=0;i<n;i++){
      string s;
      cin>>s;
      d.roll(s[0]);
      ans+=d.top();
    }
    cout<<ans<<endl;
  }
  
  return 0;
}


/*
  verified on 2018/02/09
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502
*/

signed main(){
  ITP1_11_A();
  //AOJ_0502();
  return 0;
}
