#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1254"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../graph/chromatic.cpp"
#undef call_from_test

const double EPS = 1e-10;

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
  cin.tie(0);
  ios::sync_with_stdio(0);

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
