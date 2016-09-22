#include <iostream>
using namespace std;
struct Point{int x,y;};
int main(){
  int num,n,d,i,minx,miny,maxx,maxy;
  cin >> num;
  while(num!=0){
    Point ps[201];
    ps[0].x=0;ps[0].y=0;
    
    for(i=1;i<num;i++){
      cin >> n >> d;
      if(d==0) {
	ps[i].x=ps[n].x-1;
	ps[i].y=ps[n].y;
      }
      if(d==1) {
	ps[i].x=ps[n].x;
	ps[i].y=ps[n].y-1;
      }
      if(d==2) {
	ps[i].x=ps[n].x+1;
	ps[i].y=ps[n].y;
      }
      if(d==3) {
	ps[i].x=ps[n].x;
	ps[i].y=ps[n].y+1;
      }
    }
    minx=0;miny=0;maxx=0;maxy=0;
    for(i=0;i<num;i++){
      minx=min(minx,ps[i].x);
      maxx=max(maxx,ps[i].x);
      miny=min(miny,ps[i].y);
      maxy=max(maxy,ps[i].y);
    }
    cout << (maxx-minx+1) << " " << (maxy-miny+1) << endl;
    cin >> num;
  }
  
  return 0;
}
