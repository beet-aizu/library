#include<iostream>
#include<math.h>
#define MOD 256
using namespace std;
int main(){
  int n;
  int i,j,k,l;
  int s,a,c,bs,ba,bc;
  int r[16][16][16][260];
  for(s=0;s<16;s++){
    for(a=0;a<16;a++){
      for(c=0;c<16;c++){
	r[s][a][c][0]=s;
	for(i=0;i<260-1;i++){
	  r[s][a][c][i+1]=(a*r[s][a][c][i]+c)%MOD;
	}
      }
    }
  }
  cin >> n;
  while(n!=0){
    int inf = 1 << 5;
    double m=inf,o=0;
    int ma[260]={};
    for(i=0;i<n;i++) cin >> ma[i];
    float co[260]={};
    for(s=0;s<16;s++){
      for(a=0;a<16;a++){
	for(c=0;c<16;c++){
	  o=0;
	  for(i=0;i<260;i++) co[i]=0;
	  for(i=0;i<n;i++){
	    k=(ma[i]+r[s][a][c][i+1])%MOD;
	    co[k]+=1;;
	  }
	  for(i=0;i<260;i++){
	    if(co[i]!=0){
	      
	      o-=(co[i]/n)*log(co[i]/n);
	      //cout << i <<" "<<co[i]<< endl;
	    }
	  }
	  
	  if(m>o){
	    m=o;
	    bs=s;ba=a;bc=c;
	  }
	}
      }
    }
    cout << bs << " " << ba << " " << bc << endl;
    cin >> n;
  }
}
