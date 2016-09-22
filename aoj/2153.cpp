#include<iostream>
#include<string>
#include<map>
#include<queue>
#define MAX 50
using namespace std;
struct Point{int x,y;};
struct P{
  Point l,r;
  int cost;
  bool operator<(const P &a)const{
    return (l.x==a.l.x?
	    (l.y==a.l.y?
	     (r.x==a.r.x?
	      (r.y<a.r.y):r.x<a.r.x)
	     :l.y<a.l.y)
	    :l.x<a.l.x);
  }
};
int main(){
  int w,h;
  while(cin>>w>>h,w||h){
    int i,j,k;
    int inf = 1<<20;
    
    bool d[MAX+1][MAX+1][MAX+1][MAX+1];
    fill(d[0][0][0],d[MAX][MAX][MAX],0);
    
    //map<P,int> m;
    string sr[60],sl[60];
    for(i=0;i<h;i++){
      cin >> sl[i] >> sr[i];
    }
    
    Point pr,pl,br,bl;
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	if(sl[i][j]=='L'){
	  pl.x=j;pl.y=i;
	}
	if(sr[i][j]=='R'){
	  pr.x=j;pr.y=i;
	}
      }
    }
    //cout << pl.x << ":" << pl.y << endl;
    //cout << pr.x << ":" << pr.y << endl;
    //d[pl.x][pl.y][pr.x][pr.y]=
    P p,b;
    p.r=pr;
    p.l=pl;
    p.cost=0;
    //m[p]=p.cost;
    queue<P> q;
    q.push(p);
    bool f = false;
    while(!q.empty()){
      p=q.front();q.pop();
      pl=p.l;pr=p.r;
      /*
      if(m.find(p)!=m.end())
	if(p.cost>m[p]) continue;
      m[p]=p.cost;
      */
      if(d[pl.x][pl.y][pr.x][pr.y]) continue;
      d[pl.x][pl.y][pr.x][pr.y]=true;
      
      //cout << pl.x<<":"<<pl.y<<":"<<pr.x<<":"<<pr.y<<"/"<<p.cost<<endl;
      if(sl[pl.y][pl.x]=='%'&&sr[pr.y][pr.x]=='%'){
	f=true;
	break;
      }else if(sl[pl.y][pl.x]=='%') continue;
      else if(sr[pr.y][pr.x]=='%') continue;
      
      p.cost++;
      int lx[]={1,-1,0,0};int ly[]={0,0,1,-1};
      int rx[]={-1,1,0,0};int ry[]={0,0,1,-1};
      for(i=0;i<4;i++){
	bl=pl;br=pr;
	bl.x+=lx[i];bl.y+=ly[i];
	br.x+=rx[i];br.y+=ry[i];

	//cout << bl.x<<":"<<bl.y<<":"<<br.x<<":"<<br.y<<"/"<<p.cost<<endl;
	
	if(bl.x<0) bl.x=0;
	else if(bl.x>=w) bl.x=w-1;
	if(bl.y<0) bl.y=0;
	else if(bl.y>=h) bl.y=h-1;

	if(br.x<0) br.x=0;
	else if(br.x>=w) br.x=w-1;
	if(br.y<0) br.y=0;
	else if(br.y>=h) br.y=h-1;

	if(sl[bl.y][bl.x]=='#'){
	  bl.x-=lx[i];bl.y-=ly[i];
	}
	if(sr[br.y][br.x]=='#'){
	  br.x-=rx[i];br.y-=ry[i];
	}
	p.r=br;p.l=bl;
	q.push(p);
	//m[p]=p.cost;
      }
    }
    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;
    
  }
  return 0;
}
