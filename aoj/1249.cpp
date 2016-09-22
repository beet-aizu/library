#include<iostream>
using namespace std;
int main(){
  int n,m,p;
  int i,j,k,l;
  int x,y,z;
  int bx[]={1,0,0,1,1,0, 1, 1, 0,1,-1, 1, 1};
  int by[]={0,1,0,1,0,1,-1, 0, 1,1, 1,-1, 1};
  int bz[]={0,0,1,0,1,1, 0,-1,-1,1, 1, 1,-1};
  int ln;
  cin >> n >> m >> p;
  while(n+m+p!=0){
    int d[8][8][8]={{{}}};
    int step=0;
    int winner=0;
    int ax,ay,az;
    for(i=0;i<p;i++){
      cin >> x >> y;
      x--;y--;
      //cout << i << endl;
      if(winner == 0){
	z=0;
	while(d[x][y][z]!=0) z++;
	
	if(i%2==0){
	  d[x][y][z]=1;
	  for(j=0;j<13;j++){
	    ln=0;
	    ax=x;ay=y;az=z;
	    while(d[ax][ay][az]==1){
	      ln++;
	      ax+=bx[j];
	      ay+=by[j];
	      az+=bz[j];
	      if(ax<0||ax>=n||ay<0||ay>=n||az<0||az>=n) break;
	    }
	    ax=x;ay=y;az=z;
	    while(d[ax][ay][az]==1){
	      ln++;
	      ax-=bx[j];
	      ay-=by[j];
	      az-=bz[j];
	      if(ax<0||ax>=n||ay<0||ay>=n||az<0||az>=n) break;
	    }
	    //cout << ln << endl;
	    
	    if(ln>m) {
	      winner = 1;
	      step = i+1;
	    }
	  }
	}else{
	  d[x][y][z]=2;
	  for(j=0;j<13;j++){
	    ln=0;
	    ax=x;ay=y;az=z;
	    while(d[ax][ay][az]==2){
	      ln++;
	      ax+=bx[j];
	      ay+=by[j];
	      az+=bz[j];
	      if(ax<0||ax>=n||ay<0||ay>=n||az<0||az>=n) break;
	    }
	    ax=x;ay=y;az=z;
	    while(d[ax][ay][az]==2){
	      ln++;
	      ax-=bx[j];
	      ay-=by[j];
	      az-=bz[j];
	      if(ax<0||ax>=n||ay<0||ay>=n||az<0||az>=n) break;
	    }
	    if(ln>m) {
	      winner = 2;
	      step = i+1;
	    }
	  }
	}
      }
    }
    /*
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	for(k=0;k<n;k++){
	  cout << d[j][k][i];
	}
	cout << endl;
      }
      cout << endl;
    }
    */
    if(winner==0) cout << "Draw" << endl;
    else if(winner==1) cout << "Black" <<  " " << step << endl;
    else cout << "White" <<  " " << step << endl;
    cin >> n >> m >> p;
  }
  return 0;
}
