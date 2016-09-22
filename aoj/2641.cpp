#include<iostream>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
struct Point{
  ll x,y,z;
  Point(){};
  Point(ll x,ll y,ll z):x(x),y(y),z(z){}
  Point operator+(Point p){
    return Point(x+p.x,y+p.y,z+p.z);
  }
  Point operator-(Point p){
    return Point(x-p.x,y-p.y,z-p.z);
  }
};
ll dot(Point a,Point b){
  return (a.x*b.x+a.y*b.y+a.z*b.z);
}
struct ball{
  Point p;
  ll r;
  ull l;
};
typedef Point Vector;
ull check(ball ba,Point x,Point y){
  ull z=0;
  Vector v=y-x,c=ba.p-x;
  if(dot(v,c)<=0){
    if(dot(c,c)<=ba.r*ba.r) z=ba.l;
  }else{
    if(dot(v,c)>dot(v,v)){
      if(dot(ba.p-y,ba.p-y)<=ba.r*ba.r) z=ba.l;
    }else{
      if(dot(c,c)*dot(v,v)-(dot(v,c)*dot(v,c))<=ba.r*ba.r*dot(v,v))  z=ba.l;
    }
  }
  return z;
}
int main(){
  ll n,q;
  cin >> n >> q;
  ball bs[51];
  int i,j,k;
  
  ll x,y,z;
  for(i=0;i<n;i++){
    cin >>  x >>  y >>  z >> bs[i].r >> bs[i].l;
    bs[i].p=Point(x,y,z);
  }
  for(i=0;i<q;i++){
    Point p,b;
    cin >> x >> y >> z;
    p=Point(x,y,z);
    cin >> x >> y >> z;
    b=Point(x,y,z);
    ull o=0;
    for(j=0;j<n;j++){
      o+=check(bs[j],p,b);
    }
    cout << o << endl;
  }
  return 0;
}
