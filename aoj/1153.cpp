#include <iostream>
using namespace std;

int main(){
  int n,m,i,j,st,sh,sa,bt,bh;
  int taro[101],hanako[101];
  cin >> n >> m;

  while(n!=0||m!=0){
    st=0;sh=0;bt=-1;bh=-1;
    for(i=0;i<n;i++){
      cin >> taro[i];
      st+=taro[i];
    }
    for(i=0;i<m;i++){
      cin >> hanako[i];
      sh+=hanako[i];
    }
    sa=st-sh;
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
	if((taro[i]-hanako[j])*2==sa){
	  if(bt==-1){
	    bt=i;
	    bh=j;
	  }else{
	    if(taro[bt]+hanako[bh]>taro[i]+hanako[j]){
	      bt=i;
	      bh=j;
	    }					     
	  }
	}
      }
    }
    if(bt==-1) cout << -1 << endl;
    else cout << taro[bt] << " " << hanako[bh] << endl;
    cin >> n >> m;
  }
  return 0;
}
