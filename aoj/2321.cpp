#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<pair<int,int>,ll> i_i_l;
int main(){
  int n;
  cin >> n;
  int i,j,k,b,c;
  while(n!=0){
    vector <i_i_l> date;
    i_i_l buf;
    for(i=0;i<n;i++){
      cin >> c >> buf.second;
      for(j=0;j<c;j++){
	cin >> buf.first.first >> buf.first.second;
	date.push_back(buf);
      }
    }
    
    sort(date.begin(),date.end());
    ll dp[24]={};
    for(i=0;i<date.size();i++){
      dp[date[i].first.second]=
	max(dp[date[i].first.second],
	    dp[date[i].first.first]+date[i].second);
      for(j=date[i].first.second;j<24;j++){
	dp[j]=
	  max(dp[j],dp[date[i].first.second]);
      }
    }

    cout << dp[22] << endl;

    cin >> n;
  }
}
