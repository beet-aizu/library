#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
#define MAX 1000005
int main(){
  bool e[2][MAX]={{}};
  //P s[2][MAX];
  //int sx[2][MAX]={{}};
  //int sy[2][MAX]={{}};
  int st[2][500][500]={{{}}};
  int n,u,v,m;
  int i,j,k;
  cin >> n >> u >> v >> m;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cin >> k;
      e[0][k]=true;
      st[0][i][j]=k;
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cin >> k;
      e[1][k]=true;
      st[1][i][j]=k;
    }
  }
  int col[2][500]={{}};
  int row[2][500]={{}};
  bool bcol[2][500]={{}};
  bool brow[2][500]={{}};
  int nnm[2][2]={{}};
  bool bnnm[2][2]={{}};
  int c[2]={};
  int ans=0;
  int x,y;
  for(i=0;i<m;i++){
    cin >> k;
    for(j=0;j<2;j++){
      if(e[j][k]){
	x=-1;
	for(int a=0;a<n;a++){
	  for(int b=0;b<n;b++){
	    if(st[j][a][b]==k){
	      x=a;y=b;break;
	    }
	  }
	  if(x!=-1) break;
	}
	if(!bcol[j][x]){
	  col[j][x]++;
	  if(col[j][x]==n){
	  c[j]++;
	  bcol[j][x]=true;
	  }
	}
	if(n>1){
	  if(!brow[j][y]){
	    row[j][y]++;
	    if(row[j][y]==n){
	      c[j]++;
	      brow[j][y]=true;
	    }
	  }
	  if(!bnnm[j][0]){
	    if(x==y) nnm[j][0]++;
	    if(nnm[j][0]==n){
	      c[j]++;
	      bnnm[j][0]=true;
	    }
	  }
	  if(!bnnm[j][1]){
	    if(x+y+1==n) nnm[j][1]++;
	    if(nnm[j][1]==n){
	      c[j]++;
	      bnnm[j][1]=true;
	    }
	  }
	}
      }
    }

    //cout << k <<":"<< c[0] << c[1] << endl;
    if(u<=c[0]&&v<=c[1]){
      break;
    }else if(u<=c[0]){
      ans=1;
      break;
    }else if(v<=c[1]){
      ans=2;
      break;
    }
      
  }
  if(ans==0) cout << "DRAW"  << endl;
  if(ans==1) cout << "USAGI" << endl;
  if(ans==2) cout << "NEKO"  << endl;
  return 0;
}
