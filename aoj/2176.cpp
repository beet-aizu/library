#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,d,m;
  while(cin>>n>>d,n||d){
    int i,j,k;
    vector<int> v[n];
    int sum[n];
    int ma=0,mi=1000000000;
    for(i=0;i<n;i++){
      cin >> m;
      sum[i]=0;
      for(j=0;j<m;j++){
	cin >> k;
	sum[i]+=k;
	v[i].push_back(k);
      }
      ma=max(ma,sum[i]);
      mi=min(mi,sum[i]);
    }
    bool f=true,ff=false;
    while(f){
      f=false;
      ff=true;
      for(i=0;i<n;i++){
	if(v[i].size()==0) continue;
	ff=false;
	k=v[i][v[i].size()-1];
	ma=0;mi=1000000000;
	for(j=0;j<n;j++){
	  if(i==j) continue;
	  ma=max(ma,sum[j]);
	  mi=min(mi,sum[j]);
	}
	if(abs(ma-(sum[i]-k))<=d&&abs(mi-(sum[i]-k))<=d){
	  sum[i]-=k;
	  v[i].pop_back();
	  f=true;
	  break;
	}
      } 
    }
    if(ff) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
