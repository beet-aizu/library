#include<iostream>
using namespace std;
int main(){
  int a,b,d;
  while(cin >> a >> b >> d,a||b||d){
    int x=1,y=0;
    int ox=1<<20,oy=1<<20;
    while(a*x<d) x++;
    while((a*x-d)%b!=0) x++;
    y=(a*x-d)/b;
    //cout << x <<":"<<y<<endl;
    if(x+y<ox+oy){
      ox=x;oy=y;
    }else if(x+y==ox+oy){
      if(a*x+b*y<a*ox+b*oy){
	ox=x;oy=y;
      }
    }
    x=0;y=1;
    while(b*y<d) y++;
    while((b*y-d)%a!=0) y++;
    x=(b*y-d)/a;
    //cout << x <<":"<<y<<endl;
    if(x+y<ox+oy){
      ox=x;oy=y;
    }else if(x+y==ox+oy){
      if(a*x+b*y<a*ox+b*oy){
	ox=x;oy=y;
      }
    }
    x=1;y=0;
    while((d-a*x)%b!=0&&d>=a*x) x++;
    if(d>=a*x){
      y=(d-a*x)/b;
      //cout << x <<":"<<y<<endl;
      if(x+y<ox+oy){
	ox=x;oy=y;
      }else if(x+y==ox+oy){
	if(a*x+b*y<a*ox+b*oy){
	  ox=x;oy=y;
	}
      }
    }
    x=0;y=1;
    while((d-b*y)%a!=0&&d>=b*y) y++;
    if(d>=b*y){
      x=(d-b*y)/a;
      //cout << x <<":"<<y<<endl;
      if(x+y<ox+oy){
	ox=x;oy=y;
      }else if(x+y==ox+oy){
	if(a*x+b*y<a*ox+b*oy){
	  ox=x;oy=y;
	}
      }
    }
    cout << ox << " " << oy << endl;
  }
  return 0;
}
