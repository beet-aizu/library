#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef pair<int, pair<int,int> > data;
int main(){
  int n,m;
  cin >> n >> m ;
  int i,j,k;
  while((n+m)!=0){
    int ns[20010]={};
    vector <data> ds;
    data d;
    for(i=0;i<m;i++){
      cin >> d.first >> d.second.first >> d.second.second;
      ds.push_back(d);
    }
    sort(ds.begin(),ds.end());
    int o=1;
    ns[1]=1;
    for(i=0;i<m;i++){
      if(ns[ds[i].second.first]==1&&ns[ds[i].second.second]==0) {
	ns[ds[i].second.second]=1;
	o++;
      }
    }
    cout << o << endl;
    cin >> n >> m ;
  }
  return 0;
}
