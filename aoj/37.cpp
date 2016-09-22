#include<iostream>
#include<string>
using namespace std;
struct man{int x,y,d;};
int main(){
  string st[9];
  int i,j,k;
  for(i=0;i<9;i++) cin >> st[i];
  bool f=false,mo=false;
  man m;
  m.x=0;m.y=0;m.d=0;
  int c=0;
  while(c<50){
    c++;
    mo=false;
    if(m.x==0&&m.y==0&&f) break;
    f=true;
    //cout << m.x<<":"<<m.y<<":"<<m.d << endl;
    if(m.d==0){
      if(st[m.y*2][m.x]=='1') {
	m.x++;
	cout << "R";
	mo=true;
	//continue;
      }
      if(m.y>0){
	if(st[m.y*2-1][m.x]=='1') {
	  m.d=3;
	  continue;
	}
      }
      
      if(st[m.y*2+1][m.x]=='1') {
	m.d=1;
	continue;
      }
      //m.d=2;
      //continue;
    }
    if(m.d==1){
      
      if(st[m.y*2+1][m.x]=='1') {
	m.y++;
	cout << "D" ;
	mo=true;
	//continue;
      }
      if(m.x<4){
	if(st[m.y*2][m.x]=='1') {
	  m.d=0;
	  continue;
	}
      }
      if(st[m.y*2][m.x-1]=='1') {
	m.d=2;
	continue;
      }
      //m.d=3;
      //continue;
    }
    if(m.d==2){
      
      if(st[m.y*2][m.x-1]=='1') {
	m.x--;
	cout << "L" ;
	mo=true;
	//continue;
      }
      if(m.y<4){
	if(st[m.y*2+1][m.x]=='1') {
	  m.d=1;
	  continue;
	}
      }
      if(st[m.y*2-1][m.x]=='1') {
	m.d=3;
	continue;
      }
      //m.d=0;
      //continue;
    }
    if(m.d==3){
      
      if(st[m.y*2-1][m.x]=='1') {
	m.y--;
	cout << "U" ;
	mo=true;
	//continue;
      }
      if(m.x>0){
	if(st[m.y*2][m.x-1]=='1') {
	  m.d=2;
	  continue;
	}
      }
      if(st[m.y*2][m.x]=='1') {
	m.d=0;
	continue;
      }
      //m.d=1;
      //continue;
    }
    if(!mo)m.d=(m.d+2)%4;
  }
  cout << endl;
  return 0;
}
