#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<char,ll> P;
int main(){
  vector <P> a,b,c;
  ll i,j,k;
  char ch;
  while(cin>>ch,ch!='$'){
    cin >> k;
    a.push_back(P(ch,k));
  }
  while(cin>>ch,ch!='$'){
    cin >> k;
    b.push_back(P(ch,k));
  }
  while(cin>>ch,ch!='$'){
    cin >> k;
    c.push_back(P(ch,k));
  }
  if(b.size()==1){
    for(i=0;i+b.size()<=a.size();i++){
      if(a[i].first!=b[0].first||a[i].second<b[0].second) continue;
      a[i].second-=b[0].second;
      a.insert(a.begin()+i,c.begin(),c.end());
      break;
    }
  }else{
    for(i=0;i+b.size()<=a.size();i++){
      if(a[i].first!=b[0].first||a[i].second<b[0].second) continue;
      bool f = true;
      k=b.size()-1;
      for(j=1;j<k;j++){
	if(a[i+j].first!=b[j].first||a[i+j].second!=b[j].second) {
	  f=false;
	  break;
	}
      }
      if(a[i+k].first!=b[k].first||a[i+k].second<b[k].second) continue;
      if(f){
	//cout << i << endl;
	for(j=0;j<k+1;j++){
	  a[i+j].second-=b[j].second;
	}
	a.insert(a.begin()+i+1,c.begin(),c.end());
	//i+=b.size()+c.size()-1;
	break;
      }
    }
  }

  bool ff=true;
  while(ff){
    ff=false;
    k=0;
    while(k<a.size()){
      if(a[k].second==0) {
	a.erase(a.begin()+k);
	ff=true;
      }else k++;
    }
    for(i=0;i<a.size()-1;i++){
      if(a[i].first==a[i+1].first){
	a[i+1].second+=a[i].second;
	a[i].second=0;
      }
    }
  }
  
  for(i=0;i<a.size();i++){
    if(a[i].second==0) continue;
    cout << a[i].first << " " << a[i].second << " ";
  }
  cout << "$" << endl;
}
