#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct bstr{
  string str;
  bstr(string s){str=s;}
  bool operator<(const bstr& a) const{
    return str.size()==a.str.size() ? (str.compare(a.str) < 0): str.size() > a.str.size();
  }
};
int main(){
  int h,w;
  int i,j,k;
  int ai[]={ 1, 1, 1, 0, 0,-1,-1,-1};
  int aj[]={ 1, 0,-1, 1,-1, 1, 0,-1};
  cin >> h >> w;
  while(h!=0){
    string str[10];
    for(i=0;i<h;i++) cin >> str[i];
    vector <bstr> li;
    vector <string> ans;
    int mal=1;
    for(i=0;i<h;i++){
      //cout << i << endl;
      for(j=0;j<w;j++){
	for(k=0;k<8;k++){
	  int bi=i,bj=j;
	  string buf;
	  buf += str[i][j];
	  bi+=ai[k];bj+=aj[k];
	  if(bi<0) bi=h-1;
	  if(bi>=h) bi=0;
	  if(bj<0) bj=w-1;
	  if(bj>=w) bj=0;
	  while(bi!=i||bj!=j){
	    buf+=str[bi][bj];
	    li.push_back(bstr(buf));
	    
	    bi+=ai[k];bj+=aj[k];
	    if(bi<0) bi=h-1;
	    if(bi>=h) bi=0;
	    if(bj<0) bj=w-1;
	    if(bj>=w) bj=0;
	  }
	}
      }
    }
    sort(li.begin(),li.end());
    for(i=0;i<li.size()-1;i++){
      if(li[i].str==li[i+1].str) {
	ans.push_back(li[i].str);
	break;
      }
    }
    //for(i=0;i<li.size();i++) cout << li[i] << endl;
    sort(ans.begin(),ans.end());
    //for(i=0;i<ans.size();i++) cout << ans[i] << endl;
    if(ans.size()!=0) cout << ans[0] << endl;
    else cout << 0 << endl;
    cin >> h >> w;
  }

  return 0;
}
