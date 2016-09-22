#include<iostream>
using namespace std;
int main(){
  int n,k,s;
  int i,j,l,o=0,sum;
  int a[10];
  cin >> n >> k >> s;
  while(n!=0){
    o=0;
    for(a[0]=n;a[0]>0;a[0]--){
      if(k==1){
	sum=0;
	for(i=0;i<1;i++) sum+=a[i];
	if(sum==s) o++;
      }else{
	for(a[1]=a[0]-1;a[1]>0;a[1]--){
	  if(k==2){
	    sum=0;
	    for(i=0;i<2;i++) sum+=a[i];
	    if(sum==s) o++;
	  }else{
	    for(a[2]=a[1]-1;a[2]>0;a[2]--){
	      if(k==3){
		sum=0;
		for(i=0;i<3;i++) sum+=a[i];
		if(sum==s) o++;
	      }else{
		for(a[3]=a[2]-1;a[3]>0;a[3]--){
		  if(k==4){
		    sum=0;
		    for(i=0;i<4;i++) sum+=a[i];
		    if(sum==s) o++;
		  }else{
		    for(a[4]=a[3]-1;a[4]>0;a[4]--){
		      if(k==5){
			sum=0;
			for(i=0;i<5;i++) sum+=a[i];
			if(sum==s) o++;
		      }else{
			for(a[5]=a[4]-1;a[5]>0;a[5]--){
			  if(k==6){
			    sum=0;
			    for(i=0;i<6;i++) sum+=a[i];
			    if(sum==s) o++;
			  }else{
			    for(a[6]=a[5]-1;a[6]>0;a[6]--){
			      if(k==7){
				sum=0;
				for(i=0;i<7;i++) sum+=a[i];
				if(sum==s) o++;
			      }else{
				for(a[7]=a[6]-1;a[7]>0;a[7]--){
				  if(k==8){
				    sum=0;
				    for(i=0;i<8;i++) sum+=a[i];
				    if(sum==s) o++;
				  }else{
				    for(a[8]=a[7]-1;a[8]>0;a[8]--){
				      if(k==9){
					sum=0;
					for(i=0;i<9;i++) sum+=a[i];
					if(sum==s) o++;
				      }else{
					for(a[9]=a[8]-1;a[9]>0;a[9]--){
					  sum=0;
					  for(i=0;i<10;i++) sum+=a[i];
					  if(sum==s) o++;
					}
				      }
				    }
				  }
				}
			      }
			    }
			  }
			}
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
	   
    cout << o << endl;
    cin >> n >> k >> s;
  }
}
