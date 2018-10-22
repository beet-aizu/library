#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
#define MAX 11
bool e[MAX][MAX];
int mod_pow(int x,int n,int mod){
  int res=1;
  while(n>0){
    if(n&1) (res*=x)%=mod;
    (x*=x)%=mod;
    n>>=1;
  }
  return res;
}
int I[1<<MAX],bn[1<<MAX];
bool check(int n,int k){
  int g=0;
  int MOD=10009;
  for(int i=0;i<(1<<n);i++){
    if(bn[i]%2==0) g+=mod_pow(I[i],k,MOD);
    else g-=mod_pow(I[i],k,MOD);
  }
  return (g%MOD+MOD)%MOD!=0;
}
int paint(int n){
  vector<int> N(1<<n);
  for(int i=0;i<n;i++){
    int bit=(1<<i);
    for(int j=0;j<n;j++)
      if(e[i][j]) bit|=(1<<j);
    N[i]=bit;
  }
  memset(I,0,sizeof(I));
  I[0]=1;
  for(int S=1;S<(1<<n);S++){
    bn[S]=__builtin_popcountll(S);
    int v=0;
    while(!((S>>v)&1)) v++;
    I[S]=I[S-(1<<v)]+I[S&~N[v]];
  }
  int l=0,r=n;
  while(l+1<r){
    int m=(l+r)/2;
    if(check(n,m)) r=m;
    else l=m;
  }
  return r;
}
//END CUT HERE



#define EPS (1e-10)

struct Point{
  double x,y;
  Point(){}
  Point(double x,double y) :x(x),y(y){}
  Point operator+(Point p) {return Point(x+p.x,y+p.y);}
  Point operator-(Point p) {return Point(x-p.x,y-p.y);}
  Point operator*(double k){return Point(x*k,y*k);}
  Point operator/(double k){return Point(x/k,y/k);}
};

typedef Point Vector;
typedef vector<Point> Polygon;


double norm(Vector a){
  return a.x*a.x+a.y*a.y;
}
double abs(Vector a){
  return sqrt(norm(a));
}
double cross(Vector a,Vector b){
  return a.x*b.y-a.y*b.x;
}

bool calc(Point a1,Point a2,Point b1,Point b2){
  if(abs(cross(a2-a1,b1-a1))>EPS) return 0;
  if(abs(cross(a2-a1,b2-a1))>EPS) return 0;
  double ml=0;
  ml=max(ml,abs(a1-a2));
  ml=max(ml,abs(a1-b1));
  ml=max(ml,abs(a1-b2));
  ml=max(ml,abs(a2-b1));
  ml=max(ml,abs(a2-b2));
  ml=max(ml,abs(b1-b2));
  return (ml+EPS<abs(a1-a2)+abs(b1-b2));
}


signed main(){
  int n;
  while(cin>>n,n){
    Polygon p[n];
    string name[n];
    map<string,int> m;
    for(int i=0;i<n;i++){
      cin>>name[i];
      if(!m.count(name[i])){
        int k=m.size();
        m[name[i]]=k;
      }
      int x,y;
      while(cin>>x,~x){
        cin>>y;
        p[i].push_back(Point(x,y));
      }
    }
    memset(e,0,sizeof(e));
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(name[i]==name[j]) continue;
        for(int k=0;k<(int)p[i].size();k++){
          for(int l=0;l<(int)p[j].size();l++){
            e[m[name[i]]][m[name[j]]]|=
              calc(p[i][k],p[i][(k+1)%p[i].size()],
                   p[j][l],p[j][(l+1)%p[j].size()]);
            e[m[name[j]]][m[name[i]]]|=
              calc(p[i][k],p[i][(k+1)%p[i].size()],
                   p[j][l],p[j][(l+1)%p[j].size()]);
          }
        }
      }
    }
    cout<<paint(m.size())<<endl;
  }
  return 0;
}

/*
  verified on 2017/12/12
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1254
*/
