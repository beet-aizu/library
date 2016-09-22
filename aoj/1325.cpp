#include<iostream>
using namespace std;
int sai(int a,int b){
  if(a==0||b==0) return 0;
  if(a<0) a*=-1;
  if(b<0) b*=-1;
  int buf;
  while(a%b!=0){
    buf=b;
    b=a%b;
    a=buf;
  }
  return b;
}
int main(){
  int q;
  cin >> q;
  int i,j,k;
  /*
  int ma[20001]={};
  for(i=0;i<151;i++){
    for(j=0;j<151;j++){
      int y=i*i+j*j;
      if(y==0||y>20000) continue;
      ma[y]=1;
    }
  }
  */
  for(i=0;i<q;i++){
    int n,m,o=0;
    cin >> m >> n;
    int x=m*m+n*n;
    int bm=m,bn=n;
    if(bm<0) bm*=-1;
    if(bn<0) bn*=-1;
    bm=max(bm,bn);
    //cout << bm <<endl;
    for(j=-bm;j<=bm;j++){
      for(k=-bm;k<=bm;k++){
	if(j==0&&k==0) continue;
	int y=(j*j+k*k);
	if(x%y==0) {
	  //cout << j << ":"<< k << endl;
	  int z=sai((j*m+k*n),(j*n-k*m));
	  //cout <<j*m+k*n<<":"<<j*n-k*m<< ":"<<y << ":"<<z<<endl;
	  //o++;
	  
	  if(z==y||j*m+k*n==0||j*n-k*m==0){
	    //cout << j <<":"<< k << endl;
	    //cout <<j*m+k*n<<":"<<j*n-k*m<< ":"<<y<<endl;
	    o++;
	  }
	  
	}
      }
    }
    //cout << o <<endl;
    if(o<=8) cout << "P" << endl;
    else cout << "C" << endl;
  }
  return 0;
}
