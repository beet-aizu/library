#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
struct Dice{
  int s[6];
  int &top()   {return s[0];}
  int &south() {return s[1];}
  int &east()  {return s[2];}
  int &west()  {return s[3];}
  int &north() {return s[4];}
  int &bottom(){return s[5];}
  void roll(char c){
    //the view from above
    // N
    //W E
    // S
    string b("EWNSRL");
    int v[6][4]={{0,3,5,2},
                 {0,2,5,3},
                 {0,1,5,4},
                 {0,4,5,1},
                 {1,2,4,3},
                 {1,3,4,2}};
    for(int k=0;k<6;k++){
      if(b[k]!=c) continue;
      int t=s[v[k][0]];
      s[v[k][0]]=s[v[k][1]];
      s[v[k][1]]=s[v[k][2]];
      s[v[k][2]]=s[v[k][3]];
      s[v[k][3]]=t;
    }
  }
  using ll = long long;
  ll hash(){
    ll res=0;
    for(int i=0;i<6;i++) res=res*256+s[i];
    return res;
  }
  bool operator==(const Dice &d) const{
    for(int i=0;i<6;i++) if(s[i]!=d.s[i]) return 0;
    return 1;
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
  verified on 2019/06/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A&lang=jp
*/

int ITP1_11_B(){
  Dice d;
  for(int i=0;i<6;i++) cin >> d.s[i];
  int n;cin >> n;
  while(n--){
    int a,b;cin >> a >> b;
    if(d.west()==a) d.roll('E');
    if(d.east()==a) d.roll('W');
    while(d.top()!=a) d.roll('N');
    while(d.south()!=b) d.roll('R');
    cout << d.east() << endl;
  }
  return 0;
}
/*
  verified on 2019/06/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_B&lang=jp
*/

int ITP1_11_C(){
  Dice d[2];
  for(int j=0;j<2;j++)
    for(int i=0;i<6;i++)
      cin >> d[j].s[i];
  bool f=false;
  auto vd=makeDices(d[1]);
  for(auto e:vd) f|=d[0]==e;
  cout << (f?"Yes":"No") << endl;
  return 0;
}
/*
  verified on 2019/06/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_C&lang=jp
*/

int ITP1_11_D(){
  int n;
  cin>>n;
  vector<Dice> ds(n);
  for(int j=0;j<n;j++)
    for(int i=0;i<6;i++)
      cin >> ds[j].s[i];
  bool ff=true;
  for(int i=0;i<n;i++){
    auto vd=makeDices(ds[i]);
    for(int j=0;j<i;j++){
      bool f=false;
      for(auto d:vd) f|=d==ds[j];
      ff&=!f;
    }
  }
  cout << (ff?"Yes":"No") << endl;
  return 0;
}
/*
  verified on 2019/06/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D&lang=jp
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
  verified on 2019/06/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502
*/

signed AOJ_1197(){
  vector<int> ts(6);
  do{
    for(int i=0;i<6;i++) cin>>ts[i];
    int sum=0;
    for(int t:ts) sum+=t;
    if(sum==0) break;

    auto check=
      [&](Dice d)->int{
        for(int i=0;i<6;i++)
          if(d.s[i]<0) return 0;
        int a=d.top()+d.bottom();
        int b=d.east()+d.west();
        int c=d.south()+d.north();
        if(a>b+c) return 0;
        if(b>(a+1)+c) return 0;
        if(c>(a+1)+b) return 0;
        return 1;
      };

    string ans(sum,'Z');
    sort(ts.begin(),ts.end());
    do{
      Dice d;
      for(int i=0;i<6;i++) d.s[i]=ts[i];
      if(!check(d)) continue;

      string res(sum,'Z');
      int flg=0;
      for(int i=0;i<sum;i++){
        string B="ENSW";
        string R="WSNE";
        for(int j=0;j<4;j++){
          d.roll(B[j]);
          d.bottom()--;
          if(check(d)){
            res[i]=B[j];
            break;;
          }
          d.bottom()++;
          d.roll(R[j]);
        }
        flg|=res[i]<ans[i];
        if(flg) continue;
        if(res[i]>ans[i]) break;
      }

      if(flg) ans=res;
    }while(next_permutation(ts.begin(),ts.end()));

    int p,q;
    cin>>p>>q;
    p--;
    if(ans[0]!='Z') cout<<ans.substr(p,q-p)<<endl;
    else cout<<"impossible"<<endl;
  }while(1);
  return 0;
}
/*
  verified on 2019/06/19
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1197&lang=jp
*/

signed main(){
  //ITP1_11_A();
  //ITP1_11_B();
  //ITP1_11_C();
  //ITP1_11_D();
  //AOJ_0502();
  //AOJ_1197();
  return 0;
}
