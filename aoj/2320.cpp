#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
int main(){
  ll h,w,l;
  ll i,j,k;
  ll dp[200][200][4]={{{}}};
  string st[200];
  char c[]={'E','S','W','N'};
  ll rx,ry,rd;
  ll ax[]={1,0,-1,0};
  ll ay[]={0,1,0,-1};
  bool f;
  ll s;
  while(cin>>h>>w>>l,h||w||l){
    for(i=0;i<=h+1;i++) st[i]="";
    for(i=0;i<w+2;i++) st[0]+="#";
    for(i=1;i<=h;i++) {
      cin >> st[i];
      st[i]="#"+st[i]+"#";
    }
    for(i=0;i<w+2;i++) st[h+1]+="#";
    rx=0;ry=0;rd=0;
    for(i=1;i<=h;i++){
      for(j=1;j<=w;j++){
	for(k=0;k<4;k++){
	  if(st[i][j]==c[k]){
	    st[i][j]='.';
	    ry=i;rx=j;rd=k;
	  }
	}
      }
    }
    fill(dp[0][0],dp[104][104],-1);
    f = true;
    for(i=1;i<=l;i++){
      while(st[ry+ay[rd]][rx+ax[rd]]=='#'){
	rd=(rd+1)%4;
      }
      if(st[ry+ay[rd]][rx+ax[rd]]=='.'){
	rx+=ax[rd];ry+=ay[rd];
      }
      if(dp[ry][rx][rd]==-1){
	dp[ry][rx][rd]=i;
      }else if(f){
	s = i - dp[ry][rx][rd];
	l=i+(l-i)%s;
	f=false;
      }
    }
    cout << ry << ' ' << rx << ' ' << c[rd] << endl;
  }
  return 0;
}
