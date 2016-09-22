#include<iostream>
#include<stdio.h>
using namespace std;
double n,m,k;
double p,b;
void saiki(int d,int v){
  if(d==n) {
    if(v>k)
      p+=v-k;
    else
      p++;
  }
  else{
    for(int i=1;i<=m;i++){
      saiki(d+1,v+i);
    }
  }
}
int main(){
  
  int i,j;
  cin >> n >> m >> k;
  while(n!=0){
    p=0;
    b=1;
    for(i=0;i<n;i++) b*=m;
    //cout << b << endl;
    saiki(0,0);
    //cout << p/b << endl;
    printf("%.8f\n",p/b);
    cin >> n >> m >> k;
  }


  return 0;
}
