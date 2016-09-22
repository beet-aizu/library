#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n,m;
  double l[21]={},a[21]={},b[21]={};
  cin >> n >> m;
  int i,j,k;
  for(i=0;i<n;i++){
    cin >> l[i] >> a[i] >> b[i];
  }
  double dp[21][21]={{}};
  vector<double> v;
  for(j=0;j<n;j++){
    for(k=j+1;k<n;k++){
      double d=(l[j]-l[k])*(l[j]-l[k])+
	(a[j]-a[k])*(a[j]-a[k])+
	(b[j]-b[k])*(b[j]-b[k]);
      v.push_back(d);
    }
  }
  double o=0;
  sort(v.begin(),v.end(),greater<double>());
  int t=m*(m-1)/2;
  for(i=0;i<t;i++){
    cout << v[i];
    o+=v[i];
  }
  cout << o << endl;
  return 0;
}
