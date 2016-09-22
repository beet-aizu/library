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
  m.x=1;m.y=0;m.d=0;
  int c=0;
  cout << "R";
  while(1){
    c++;
    mo=false;
    
    if(m.x==1&&m.y==1&&m.d==2) {
      //cout << "L";
      break;
    }
    if(m.x==0&&m.y==1&&f) {
      //cout << "U";
      break;
    }
    f=true;
    
    //cout << m.x<<":"<<m.y<<":"<<m.d << endl;
    if(m.d==0){
      if(m.y>0){
	if(st[m.y*2-1][m.x]=='1') {
	  cout << "U";
	  m.d=3;
	  continue;
	}
      }
      if(m.y<5){
	if(st[m.y*2][m.x]=='1') {
	  m.x++;
	  cout << "R";
	  continue;
	}
      }
      if(m.y<4){
	if(st[m.y*2+1][m.x]=='1') {
	  m.x++;
	  m.y++;
	  cout << "D";
	  m.d=1;
	  continue;
	}
      }
      m.y++;
      cout << "L";
      m.d=2;
      continue;
    }
    
    if(m.d==1){
      if(m.y<5){
	if(st[m.y*2][m.x-1]=='1') {
	  cout <<"R";
	  m.d=0;
	  continue;
	}
      }
      if(m.x>0&&m.y<4){
	if(st[m.y*2+1][m.x-1]=='1') {
	  m.y++;
	  cout << "D" ;
	  mo=true;
	  continue;
	}
      }
      if(m.x>1&&m.y<5){
	if(st[m.y*2][m.x-2]=='1') {
	  m.x--;
	  m.y++;
	  cout << "L";
	  m.d=2;
	  continue;
	}
      }
      m.x--;
      cout << "U";
      m.d=3;
      continue;
    }
    if(m.d==2){
      if(m.x>0){
	if(st[m.y*2-1][m.x-1]=='1') {
	  cout << "D";
	  m.d=1;
	  continue;
	}
      }
      if(m.x>1&&m.y>0){
	if(st[(m.y-1)*2][m.x-2]=='1') {
	  m.x--;
	  cout << "L" ;
	  mo=true;
	  continue;
	}
      }
      if(m.x>0&&m.y>1){
	if(st[(m.y-1)*2-1][m.x-1]=='1') {
	  m.x--;
	  m.y--;
	  cout << "U";
	  m.d=3;
	  continue;
	}
      }
      m.y--;
      cout << "R";
      m.d=0;
      continue;
    }
    if(m.d==3){

      if(m.y>0){
	if(st[(m.y-1)*2][m.x-1]=='1') {
	  cout << "L";
	  m.d=2;
	  continue;
	}
      }
      if(m.y>1){
	if(st[(m.y-1)*2-1][m.x]=='1') {
	  m.y--;
	  cout << "U" ;
	  mo=true;
	  continue;
	}
      }
      if(m.y>0){
	if(st[(m.y-1)*2][m.x]=='1') {
	  m.x++;
	  m.y--;
	  cout << "R";
	  m.d=0;
	  continue;
	}
      }
      m.x++;
      cout << "D";
      m.d=1;
      continue;
    }
    //if(!mo)m.d=(m.d+2)%4;
  }
  
  cout  << endl;
  return 0;
}
