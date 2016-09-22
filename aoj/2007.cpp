#include<iostream>
using namespace std;
int main(){
  int n,a,b,c,d,i,j,k,l,ba,bb,bc,bd,o,bo,s;
  cin >> n;
  while(n!=0){
    cin >> a >> b >> c >> d;
    o=100000;
    for(i=0;i<=a;i++){
      for(j=0;j<=b;j++){
	for(k=0;k<=c;k++){
	  for(l=0;l<=d;l++){
	    bo=a+b+c+d;
	    if(i*10+j*50+k*100+l*500>=n){
	      bo-=i+j+k+l;
	      s=(i*10+j*50+k*100+l*500)-n;
	      bo+=(s/500)+(s%500)/100+(s%100)/50+(s%50)/10;
	      if(bo<o){
		o=bo;ba=i;bb=j;bc=k;bd=l;
	      }
	    }
	  }
	}
      }
    }
    if(ba!=0) cout << 10 <<  " " << ba << endl;
    if(bb!=0) cout << 50 <<  " " << bb << endl;
    if(bc!=0) cout << 100 <<  " " << bc << endl;
    if(bd!=0) cout << 500 <<  " " << bd << endl;
    
    cin >> n;
    if(n!=0)cout << endl;
  }
  return 0;
}
