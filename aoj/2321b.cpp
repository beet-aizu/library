#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<pair<int,int>,ll> i_i_l;
typedef pair<int,ll> i_l;
int main(){
  int n;
  cin >> n;
  int i,j,k,b,c;
  while(n!=0){
    vector <i_l> date;
    i_l buf;
    int x,y;
    for(i=0;i<n;i++){
      cin >> c >> buf.second;
      buf.first=0;
      for(j=0;j<c;j++){
	cin >> x >> y;
        x-=6;
        y-=6;
	for(k=x;k<y;k++) buf.first+=1<<k;
	
      }
      date.push_back(buf);
    }
    
    ll dp[1<<16]={};
    for(i=0;i<n;i++){
      for(int S=0;S<1<<16;S++){
	if((S&date[i].first)==date[i].first){
	  dp[S-date[i].first]=max(dp[S-date[i].first],dp[S]+date[i].second);
	}
      }
    }
    ll o=0;
    for(int S=0;S<1<<16;S++){
      o=max(o,dp[S]);
    }
    cout << o << endl;

    cin >> n;
  }
}
