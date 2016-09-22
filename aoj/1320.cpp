#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  while(cin >> n,n){
    vector<string> v;
    int d[15][15]={{}};
    int l[15]={};
    int ans;
    int dp[1<<14][14];
    int inf = 1 << 20;
    string s;
    int i,j,k;
    for(i=0;i<n;i++){
      cin >> s;
      v.push_back(s);
    }
    
    bool f;
    for(i=0;i<n;i++){
      f=false;
      for(j=0;j<n;j++){
	if(i==j) continue;
	if(v[j].find(v[i])!=-1) f=true;	
      }
      if(f){
	v.erase(v.begin()+i);
	i--;n--;
      }
    }
    for(i=0;i<n;i++) l[i]=v[i].size();
    
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	if(i==j) continue;
	for(k=1;k<=v[i].size();k++){
	  if(v[i].substr(v[i].size()-k,k)==v[j].substr(0,k))
	    d[i][j]=max(d[i][j],k);
	}
      }
    }
    memset(dp,-1,sizeof(dp));
    for(i=0;i<n;i++){
      dp[1<<i][i]=l[i];
    }
    for(int bit=1;bit<(1<<n);bit++){
      for(i=0;i<n;i++){
	if(bit>>i&1) continue;
	for(j=0;j<n;j++){
	  if(~dp[bit][j]){
	    if(~dp[bit|(1<<i)][i])
	      dp[bit|(1<<i)][i]=min(dp[bit|(1<<i)][i],dp[bit][j]+l[i]-d[j][i]);
	    else
	      dp[bit|(1<<i)][i]=dp[bit][j]+l[i]-d[j][i];
	  }
	}
      }
    }
    ans=inf;
    for(i=0;i<n;i++) if(~dp[(1<<n)-1][i]) ans=min(ans,dp[(1<<n)-1][i]);
    cout << ans << endl;
    
  }
  return 0;
}
