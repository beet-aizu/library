#include<iostream>
#include<string>
using namespace std;
int main(){
  int board[8][8]={{}};
  string buf;
  int i,j,k;
  char cs[]={'.','o','x'};
  for(i=0;i<8;i++){
    cin>>buf;
    for(j=0;j<8;j++){
      if(buf[j]=='.') board[j][i]=0;
      if(buf[j]=='o') board[j][i]=1;
      if(buf[j]=='x') board[j][i]=2;
    }
  }
  int f=1;
  int ax[]={ 1, 1, 1, 0, 0,-1,-1,-1};
  int ay[]={ 0, 1,-1, 1,-1,-1, 1, 0};
  while(f!=0){
    f=0;
    int x,y,bx,by,m=0,c,s;
    for(j=0;j<8;j++){
      for(i=0;i<8;i++){
	c=0;s=0;
	x=i;
	y=j;
	if(board[x][y]!=0) continue;
	for(k=0;k<8;k++){
	  s=0;
	  x=i;
	  y=j;
	  //cout << x+ax[k];
	  while(0<=x+ax[k]&&x+ax[k]<8&&
		0<=y+ay[k]&&y+ay[k]<8){
	    //cout << board[x+ax[k]][y+ay[k]];
	    if(board[x+ax[k]][y+ay[k]]==2){
	      s++;
	      //cout << s << endl;
	      x+=ax[k];y+=ay[k];
	    }
	    else if(board[x+ax[k]][y+ay[k]]==1) {
	      c+=s;
	      break;
	    }else break;
	    
	  }	  
	}
	if(m<c){
	  bx=i;
	  by=j;
	  m=c;
	}
      }
    }
    
    //cout << m << " "<<bx << " " << by<< endl;
    if(m!=0){
      for(k=0;k<8;k++){
	s=0;
	x=bx;
	y=by;
	while(0<=x+ax[k]&&x+ax[k]<8&&
	      0<=y+ay[k]&&y+ay[k]<8){
	  if(board[x+ax[k]][y+ay[k]]==2){
	    s++;
	    x+=ax[k];y+=ay[k];
	  }else if(board[x+ax[k]][y+ay[k]]==1) {
	    for(int a=0;a<=s;a++) board[bx+ax[k]*a][by+ay[k]*a]=1;
	    break;
	  }else break;
	  
	}
      }
      f=1;
    }
    m=0;
    for(j=7;j>=0;j--){
      for(i=7;i>=0;i--){
	c=0;s=0;
	x=i;
	y=j;
	
	if(board[x][y]!=0) continue;
	for(k=0;k<8;k++){
	  s=0;
	  x=i;
	  y=j;
	  while(0<=x+ax[k]&&x+ax[k]<8&&
		0<=y+ay[k]&&y+ay[k]<8){
	    if(board[x+ax[k]][y+ay[k]]==1){
	      s++;
	      //cout << s << endl;
	      x+=ax[k];y+=ay[k];
	    }
	    else if(board[x+ax[k]][y+ay[k]]==2) {
	      c+=s;
	      break;
	    }else break;
	  }
	}
	if(m<c){
	  bx=i;
	  by=j;
	  m=c;
	}
      }
    }
    if(m!=0){
      for(k=0;k<8;k++){
	s=0;
	x=bx;
	y=by;
	while(0<=x+ax[k]&&x+ax[k]<8&&
	      0<=y+ay[k]&&y+ay[k]<8){
	  if(board[x+ax[k]][y+ay[k]]==1){
	    s++;
	    x+=ax[k];y+=ay[k];
	  }else if(board[x+ax[k]][y+ay[k]]==2) {
	    for(int a=0;a<=s;a++) board[bx+ax[k]*a][by+ay[k]*a]=2;
	    break;
	  }else break;
	  
	}
      }
      f=1;
    }
    //cout << m << " "<<bx << " " << by<< endl;
    //f*=0;
  }
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      cout << cs[board[j][i]];
    }
    cout << endl;
  }
}
