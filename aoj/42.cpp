#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#define pb(a) push_back(a)
using namespace std;
typedef pair<int,int> P;
int main(){
  int c=0;
  int w,n,i,j,k;;
  while(cin >> w,w){
    c++;
    cout << "Case "<<c<<":"<<endl;
    cin >> n;
    string s;
    vector<P> v;
    v.clear();
    P p,ans;
    for(k=0;k<n;k++){
      cin >> s;
      for(i=0;i<s.size();i++) if(s[i]==',') s[i]=' ';
      stringstream ss(s);
      ss>>p.first >>p.second;
      v.pb(p);
    }
    int dp[1005][1005]={{}};
    int inf = 1 << 20;
    fill(dp[0],dp[1004],-inf);
    dp[0][0]=0;
    for(i=0;i<n;i++){
      //cout << v[i].first << ":" << v[i].second << endl;
      for(j=0;j<=w;j++){
	if(dp[i][j]==-inf) continue;
	dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
	if(j+v[i].second<=w)
	  dp[i+1][j+v[i].second]=max(dp[i+1][j],dp[i][j]+v[i].first);
	//cout << dp[i+1][j]<<endl;
      }
    }
    ans.first=0;ans.second=0;
    /*
    for(i=0;i<=n;i++)
      for(j=0;j<=w;j++)
	if(dp[i][j]!=-inf)cout << i << ":" << j << ":" << dp[i][j] << endl;
    */
    for(i=0;i<=w;i++){
      //cout << i << ":" << dp[1][i] << endl;
      if(dp[n][i]>ans.first){
	ans.first=dp[n][i];
	ans.second=i;
      }
    }
    cout << ans.first << endl << ans.second << endl;
  }
  return 0;
}
