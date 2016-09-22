#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
struct era{
  ll s,e;
  string name;
  bool operator<(const era&e)const{
    return s < e.s;
  }
};
int main(){
  ll n,q;
  int i,j,k;
  era e;
  string str;
  ll b,w;
  cin >> n >> q;
  while(n+q!=0){
    vector<era> v;
    for(i=0;i<n;i++){
      cin >> str >> b >> w;
      e.name=str;
      e.s=w-b+1;e.e=w;
      //cout << e.s << " " << e.e  << endl;
      v.push_back(e);
    }
    sort(v.begin(),v.end());
    for(i=0;i<q;i++){
      cin >> b;
      ll st=0,en=v.size(),no;
      no=(st+en)/2;
      for(j=0;j<100;j++){
	if(v[no].s<=b&&b<=v[no].e) break;
	if(v[no].s<=b) st = no;
	else en=no;
	no=(st+en)/2;
      }
      //cout << v[no].s << " " << v[no].e  << endl;
      if(v[no].s<=b&&b<=v[no].e) cout << v[no].name <<" "<<  (b-v[no].s+1) << endl;
      else cout << "Unknown" << endl;
    }
    
    cin >> n >> q;
  }
  return 0;
}
