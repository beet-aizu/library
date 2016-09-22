#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;
typedef pair<int,int> P;
int main(){
  string st[15],s;
  while(cin>>s){
    int i,j,k;
    st[0]="00000000000000";
    st[1]="0"+s+"0";
    for(i=0;i<11;i++){
      cin >> s;
      st[i+2]="0"+s+"0";
    }
    st[13]="00000000000000";
    int ans=0;
    for(i=1;i<=12;i++){
      for(j=1;j<=12;j++){
	if(st[i][j]=='1'){
	  ans++;
	  queue<P> q;
	  P p;
	  q.push(P(i,j));
	  while(!q.empty()){
	    p=q.front();q.pop();
	    if(st[p.first][p.second]=='0') continue;
	    st[p.first][p.second]='0';
	    int ax[]={1,-1,0,0};
	    int ay[]={0,0,1,-1};
	    for(k=0;k<4;k++){
	      if(st[p.first+ay[k]][p.second+ax[k]]=='1')
		q.push(P(p.first+ay[k],p.second+ax[k]));
	    }
	  }
	}
      }
    }
    cout << ans << endl;
  }
}
