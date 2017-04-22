#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[300][114514];
int ad[300];
#define BS 400
signed main(){
  int n,m,q;
  cin>>n>>m>>q;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  int l[q],r[q],d[q];
  for(int i=0;i<q;i++) cin>>l[i]>>r[i]>>d[i];

  for(int i=0;i<n;i++)
    dp[i/BS][(a[i]%=m)]++;
  for(int i=0;i<q;i++){
    l[i]--;
    int ans=0,k=0;
    while(BS*k<l[i]) k++;
    for(int j=l[i];j<min(r[i],BS*k);j++){
      dp[j/BS][a[j]]--;
      (a[j]+=d[i])%=m;
      dp[j/BS][a[j]]++;
      if((a[j]+ad[j/BS])%m==0) ans++;
    }
    for(;BS*(k+1)<=r[i];k++){
      (ad[k]+=d[i])%=m;
      ans+=dp[k][(m-ad[k])%m];
    }
    for(int j=BS*k;j<r[i];j++){
      dp[j/BS][a[j]]--;
      (a[j]+=d[i])%=m;
      dp[j/BS][a[j]]++;
      if((a[j]+ad[j/BS])%m==0) ans++;
    }
    cout<<ans<<endl;
  }
  return 0;
}
