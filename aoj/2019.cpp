#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
  int n,m,d,p,o;
  typedef pair<int,int> ma;
  
  int i,j,k;
  cin >> n >> m;
  while(n!=0||m!=0){
    vector <ma> map;
    ma b;
    for(i=0;i<n;i++) {
      cin >> d >> p;
      b.first=p;b.second=d;
      map.push_back(b);
    }
    sort(map.begin(),map.end(),greater<ma>());
    o=0;
    for(i=0;i<map.size();i++){
      if(m>=map[i].second) m-=map[i].second;
      else if(m>0) {
	o+=(map[i].second-m)*map[i].first;
	m=0;
      }else o+=map[i].first*map[i].second;
    }
    cout << o << endl;
    cin >> n >> m;
  }
  return 0;
}
