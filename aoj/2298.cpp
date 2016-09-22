#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,t,u,v,l;
  cin>>n>>k>>t>>u>>v>>l;
  int i,j;
  set<int> s;
  for(i=0;i<n;i++){
    cin >> j;
    s.insert(j);
  }
  int p=0,h=0,x=0;
  double ans=0;
  for(i=1;i<=l;i++){
    if(x==0){
      if(h>0){
	x=v*t-1;h--;
	ans+=1.0/v;
      }else ans+=1.0/u;
    }else{
      ans+=1.0/v;
      x--;
    }
    if(s.find(i)!=s.end())
      if(h<k) h++;
      else x=v*t;
  }
  printf("%.9lf\n",ans);
  return 0;
}
