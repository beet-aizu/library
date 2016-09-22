#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){

  int n,a,b,c,i,j,p,q,r,s,flag;
  
  cin >> a >> b >> c;
  while(a!=0){
    flag=0;
    for(i=1;i<=a;i++){
      if(a%i==0){
	p=i;
	q=a/i;
	if(flag==0&&c==0) {
	  if(b>0)
	    printf("%d %d %d %d\n",a,b,1,0);
	  else
	    printf("%d %d %d %d\n",a,0,1,b);
	  flag=1;
	}else{
	  n=c;
	  if(n<0) n*=-1;
	  for(j=1;j<=n;j++){
	    if(n%j==0){
	      r=j;
	      s=n/j;
	      if(flag==0&&p*r==a&&p*s+q*r==b&&q*s==c){
		printf("%d %d %d %d\n",r,s,p,q);
		flag=1;
		
	      }
	      if(flag==0&&p*r==a&&p*s*(-1)+q*r*(-1)==b&&q*s==c){
		printf("%d %d %d %d\n",r,-s,p,-q);
		flag=1;
		
	      }
	      if(flag==0&&p*r==a&&p*s+q*r*(-1)==b&&q*s*(-1)==c){
		printf("%d %d %d %d\n",r,s,p,-q);
		flag=1;
		
	      }
	      if(flag==0&&p*r==a&&p*s*(-1)+q*r==b&&q*s*(-1)==c){
		printf("%d %d %d %d\n",r,-s,p,q);
		flag=1;
		
	      }
	    }
	  }
	}
      }
    }
    
  
    
    
    
    if(flag==0) printf("Impossible\n");
    cin >> a >> b >> c;
  }
  
  return 0;
}
