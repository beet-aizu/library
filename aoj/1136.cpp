#include<iostream>
#include<vector>
using namespace std;
struct Point{
  int x,y;
  Point& operator=(Point & p){
    x=p.x;y=p.y;
    return *this;
  }
};
struct Polygon{
  vector<int> ls;
  vector<int> ps;
  bool operator==(const Polygon & a)const{
    if(ls.size()!=a.ls.size()) return false;
    int i,j,k;
    int f=0;
    for(i=0;i<ls.size();i++){
      if(ls[i]!=a.ls[i])f=1;
    }
    for(i=0;i<ps.size();i++){
      if(ps[i]!=a.ps[i])f=1;
    }
    if(f==0) return true;
    f=0;
    for(i=0;i<ls.size();i++){
      if(ls[i]!=a.ls[ls.size()-(i+1)])f=1;
    }
    for(i=0;i<ps.size();i++){
      if(ps[i]==a.ps[ps.size()-(i+1)])f=1;
    }
    if(f==0) return true;
    return false;
  }
};
int main(){
  int n,m;
  int i,j,k;
  cin >> n;
  while(n!=0){
    Polygon base;
    Point buf,bef;
    Point b,c;
    
    
    cin >> m;
    cin >> bef.x >> bef.y;
    b.x=0;b.y=0;
    for(j=0;j<m-1;j++){
      cin >> buf.x >> buf.y;
      int l=(buf.x-bef.x)+(buf.y-bef.y);
      if(l<0) l*=-1;
      base.ls.push_back(l);
      if(buf.x>bef.x) {
	c.x=1;c.y=0;
      }else if(buf.x<bef.x){
	c.x=-1;c.y=0;
      }else if(buf.y>bef.y){
	c.x=0;c.y=1;
      }else if(buf.y<bef.y){
	c.x=0;c.y=-1;
      }
      
      if(b.x==1){
	if(c.y==1) base.ps.push_back(-1);
	else if(c.y==-1) base.ps.push_back(1);
      }else if(b.x==-1){
	if(c.y==1) base.ps.push_back(1);
	else if(c.y==-1) base.ps.push_back(-1);
      }else if(b.y==1){
	if(c.x==1) base.ps.push_back(1);
	else if(c.x==-1) base.ps.push_back(-1);
      }else if(b.y==-1){
	if(c.x==1) base.ps.push_back(-1);
	else if(c.x==-1) base.ps.push_back(1);
      }
      
      b=c;
      bef=buf;
    }
    //cout << endl;
    vector<Polygon> ps;
    for(i=0;i<n;i++){
      cin >> m;
      Polygon p;
      cin >> bef.x >> bef.y;
      b.x=0;b.y=0;
      for(j=0;j<m-1;j++){
	cin >> buf.x >> buf.y;
	int l=(buf.x-bef.x)+(buf.y-bef.y);
	if(l<0) l*=-1;
	p.ls.push_back(l);
	//cout << l << endl;
	
	if(buf.x>bef.x) {
	  c.x=1;c.y=0;
	}else if(buf.x<bef.x){
	  c.x=-1;c.y=0;
	}else if(buf.y>bef.y){
	  c.x=0;c.y=1;
	}else if(buf.y<bef.y){
	  c.x=0;c.y=-1;
	}

	int t=1;
	if(b.x==1){
	  if(c.y==1) t=-1;
	  else if(c.y==-1) t=1;
	}else if(b.x==-1){
	  if(c.y==1) t=1;
	  else if(c.y==-1) t=-1;
	}else if(b.y==1){
	  if(c.x==1) t=1;
	  else if(c.x==-1) t=-1;
	}else if(b.y==-1){
	  if(c.x==1) t=-1;
	  else if(c.x==-1) t=1;
	}

	if(j!=0) {
	  p.ps.push_back(t);
	  //cout << j << ":" << t << endl;
	}
	
	b=c;
	//cout << bef.x << bef.y << endl;
	bef=buf;
	//cout << bef.x << bef.y << endl;
      }
      ps.push_back(p);
      //cout << endl;
    }
    //cout << ps.size() << endl;
    for(i=0;i<n;i++){
      if(base==ps[i]) cout << (i+1) << endl;
    }
    cout << "+++++" << endl;
    //cout << n;
    cin >> n;
    //cout << n;
  }
  return 0;
}
