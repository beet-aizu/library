#include<iostream>
#include<vector>
using namespace std;
int n,m,a,b,c,t;
struct ary{
  int x[50][50]; 
  ary(){}
  ary(const ary &p){
    for(int i=0;i<50;i++){
      for(int j=0;j<50;j++){
	x[i][j]=p.x[i][j];
      }
    }
  }
};

ary mp,st;
ary multi(ary bmp1,ary bmp2){
  ary nmp;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      nmp.x[i][j]=0;
      for(int k=0;k<n;k++){
	nmp.x[i][j]+=(bmp1.x[i][k]*bmp2.x[k][j])%m;
      }
      nmp.x[i][j]%=m;
    }
  }
  return nmp;
}

ary rec(ary bmp,int ti){
  ary nmp(bmp);
  ti--;
  while(ti>0){
    if(ti&1) nmp=multi(nmp,bmp);
    bmp=multi(bmp,bmp);
    ti>>=1;
  }
  return nmp;
}
int main(){
  while(cin>>n>>m>>a>>b>>c>>t,n||m||a||b||c||t){
    int s[50]={},o[50]={};
    int i,j,k,p,q;
    for(i=0;i<n;i++){
      cin >> s[i]; 
    }
    fill(mp.x[0],mp.x[50],0);
    fill(st.x[0],st.x[50],0);
    mp.x[0][0]=b; mp.x[0][1]=c;
    for(i=1;i<n-1;i++){
      mp.x[i][i-1]=a;
      mp.x[i][i]=b;
      mp.x[i][i+1]=c;
    }
    mp.x[n-1][n-2]=a; mp.x[n-1][n-1]=b;
    mp=rec(mp,t);
    if(t==0){
      for(i=0;i<n;i++)
	cout << s[i] << (i==n-1?"\n":" ");
    }else{
      for(i=0;i<n;i++){
	o[i]=0;
	for(k=0;k<n;k++){
	  o[i]+=(mp.x[i][k]*s[k])%m;
	}
	o[i]%=m;
	cout << o[i] << (i==n-1?"\n":" ");
      }
    }
  }
  return 0;
}
