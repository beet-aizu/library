#include<bits/stdc++.h>
using namespace std;
int isPrime(int x){
  for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
  return 1;
}
int main(){
  int m,n;
  int st[1005][1005]={{}};
  int p[1000005]={};
  int x=501,y=501;
  int idx,idy;
  int i=1,j,k=1;
  st[x][y]=i;
  i++;
  while(1){
    for(j=0;j<2*k;j++){
      st[x+1][y-j]=i;
      i++;
    }
    for(j=0;j<2*k;j++){
      st[x-j][y-(k-1)*2-1]=i;
      i++;
    }
    for(j=0;j<2*k;j++){
      st[x-(k-1)*2-1][y-(k-1)*2+j]=i;
      i++;
    }
    for(j=0;j<2*k;j++){
      st[x-(k-1)*2+j][y+1]=i;
      i++;
    }
    if(i>1000005) break;
    k++;x++;y++;
  }
  for(i=2;i<1000005;i++) p[i]=isPrime(i);
  
  
  while(cin >> m >> n,m||n){
    int ans=0,id=0;
    int dp[2][1005]={};
    for(i=0;i<1005;i++){
      for(j=0;j<1005;j++){
	if(st[i][j]==n){
	  idx=i;idy=j;
	  if(p[n]){
	    ans=1;id=n;
	    dp[0][i]=1;
	  }
	  break;
	}
      }
    }
    //cout << n << ":" << p[n] << endl;
    for(i=0;i+idy<1005;i++){
      for(j=-i;j<=i;j++){
	if(idx+j<0||idx+j>1004) continue;
	if(st[idx+j][idy+i]>m) continue;
	if(idx+j-1>=0&&idx+j-1<1005){
	  if(st[idx+j-1][idy+i+1]<=m){
	    dp[(i+1)%2][idx+j-1]=
	      max(dp[(i+1)%2][idx+j-1],dp[i%2][idx+j]+p[st[idx+j-1][idy+i+1]]);
	    if(p[st[idx+j-1][idy+i+1]]){
	      if(ans<dp[(i+1)%2][idx+j-1]||
		 (ans==dp[(i+1)%2][idx+j-1]&&id<st[idx+j-1][idy+i+1])){
		ans=dp[(i+1)%2][idx+j-1];
		id=st[idx+j-1][idy+i+1];
	      }
	    }
	  }
	}
	if(idx+j>=0&&idx+j<1005){
	  if(st[idx+j][idy+i+1]<=m){
	    dp[(i+1)%2][idx+j]=
	      max(dp[(i+1)%2][idx+j],dp[i%2][idx+j]+p[st[idx+j][idy+i+1]]);
	    if(p[st[idx+j][idy+i+1]]){
	      if(ans<dp[(i+1)%2][idx+j]||
		 (ans==dp[(i+1)%2][idx+j]&&id<st[idx+j][idy+i+1])){
		ans=dp[(i+1)%2][idx+j];
		id=st[idx+j][idy+i+1];
	      }
	    }
	  }
	}
	if(idx+j+1>=0&&idx+j+1<1005){
	  if(st[idx+j+1][idy+i+1]<=m){
	    dp[(i+1)%2][idx+j+1]=
	      max(dp[(i+1)%2][idx+j+1],dp[i%2][idx+j]+p[st[idx+j+1][idy+i+1]]);
	    if(p[st[idx+j+1][idy+i+1]]){
	      if(ans<dp[(i+1)%2][idx+j+1]||
		 (ans==dp[(i+1)%2][idx+j+1]&&id<st[idx+j+1][idy+i+1])){
		ans=dp[(i+1)%2][idx+j+1];
		id=st[idx+j+1][idy+i+1];
	      }
	    }
	  }
	}
      }    
    }
    cout << ans << " " << id << endl;
  }
  return 0;
}
