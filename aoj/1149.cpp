#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef pair<int,int> i_i;
int main(){
  int n,w,d;
  int b,c;
  cin >> n >> w >> d;
  while(n!=0||w!=0||d!=0){
    vector<i_i> v;
    i_i x;
    i_i a1,a2;
    x.first=w;x.second=d;
    v.push_back(x);
    for(int i=0;i<n;i++){
      cin >> b >> c;
      x=v[b-1];
      //cout << x.first <<":"<<x.second<<endl;
      v.erase(v.begin()+b-1);
      int k=c%(x.first+x.second);
      if(k<x.first){
	if(k<=x.first/2){
	  a1.first=k;a1.second=x.second;
	  a2.first=x.first-k;a2.second=x.second;
	}else{
	  a1.first=x.first-k;a1.second=x.second;
	  a2.first=k;a2.second=x.second;
	}
      }else{
	k-=x.first;
	if(k<=x.second/2){
	  a1.first=x.first;a1.second=k;
	  a2.first=x.first;a2.second=x.second-k;
	}else{
	  a1.first=x.first;a1.second=x.second-k;
	  a2.first=x.first;a2.second=k;
	}
      }
      //cout << a1.first <<":"<<a1.second<<endl;
      //cout << a2.first <<":"<<a2.second<<endl;
      v.push_back(a1);
      v.push_back(a2);
    }
    vector <int> s;
    for(int i=0;i<v.size();i++){
      //cout << v[i].first <<":"<<v[i].second<<endl;
      s.push_back(v[i].first*v[i].second);
    }
    sort(s.begin(),s.end());
    cout << s[0];
    for(int i=1;i<s.size();i++){
      cout << " " << s[i];
    }
    cout << endl;
    cin >> n >> w >> d;
  }
  return 0;
}
