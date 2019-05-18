#include<bits/stdc++.h>
using namespace std;
using Int = long long;
//BEGIN CUT HERE
int chromatic(vector< vector<int> > &G){
  int n=G.size();
  if(n==0) return 0;
  assert(n<=30);
  
  vector<int> es(n,0);  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      es[i]|=G[i][j]<<j;
  
  int s=1<<n;
  vector<int> dp(s);
  for(int b=0;b<s;b++)
    dp[b]=((n-__builtin_popcount(b))&1?-1:1);

  auto calc=
    [&](const int MOD){
      vector<int> res(s);
      res[0]=1;
      for(int b=1;b<s;b++){
        int ctz=__builtin_ctz(b);
        res[b]=res[b-(1<<ctz)]+res[(b-(1<<ctz))&~es[ctz]];
        if(res[b]>=MOD) res[b]-=MOD;
      }
      return res;
    };
  
  constexpr int MOD1 = 1077563119;
  constexpr int MOD2 = 1e9+7;
  vector<int> ind1=calc(MOD1);
  vector<int> ind2=calc(MOD2);
  
  using ll = long long;
  vector<int> dp1=dp,dp2=dp;
  for(int i=1;i<n;i++){
    ll sum1=0,sum2=0;
    for(int b=0;b<s;b++){
      dp1[b]=((ll)dp1[b]*ind1[b])%MOD1;
      sum1+=dp1[b];
      
      dp2[b]=((ll)dp2[b]*ind2[b])%MOD2;
      sum2+=dp2[b];
    }
    if(sum1%MOD1!=0) return i;
    if(sum2%MOD2!=0) return i;
  }
  return n;
}
//END CUT HERE

struct FastIO{
  FastIO(){
    cin.tie(0);
    ios::sync_with_stdio(0);
  }
}fastio_beet;

//INSERT ABOVE HERE

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
    vector<Polygon> p(n);
    vector<string> name(n);
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
    
    vector<vector<int> > G(m.size(),vector<int>(m.size(),0));
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        if(name[i]==name[j]) continue;
        for(int k=0;k<(int)p[i].size();k++){
          for(int l=0;l<(int)p[j].size();l++){
            G[m[name[i]]][m[name[j]]]|=
              calc(p[i][k],p[i][(k+1)%p[i].size()],
                   p[j][l],p[j][(l+1)%p[j].size()]);
            G[m[name[j]]][m[name[i]]]|=
              calc(p[i][k],p[i][(k+1)%p[i].size()],
                   p[j][l],p[j][(l+1)%p[j].size()]);
          }
        }
      }
    }
    cout<<chromatic(G)<<endl;
  }
  return 0;
}

/*
  verified on 2017/12/12
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1254
*/
