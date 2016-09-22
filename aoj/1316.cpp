#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int h,w;
  int i,j,k;
  int ai[]={ 1, 1, 1, 0, 0,-1,-1,-1};
  int aj[]={ 1, 0,-1, 1,-1, 1, 0,-1};
  cin >> h >> w;
  while(h!=0){
    string str[10];
    for(i=0;i<h;i++) cin >> str[i];
    vector <string> li;
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
	    if(buf.size()>=mal){
	      if(find(li.begin(),li.end(),buf)!=li.end()) {
		mal=buf.size();
		if(buf.size()>mal) {
		  ans.clear();
		  ans.push_back(buf);
		  int a=0;
		  while(li[a].size()!=mal) a++;
		  li.erase(li.begin(),li.begin()+a-1);
		}else{
		  ans.push_back(buf);
		}
		
	      }else{
		li.push_back(buf);
	      }
	    }
	    bi+=ai[k];bj+=aj[k];
	    if(bi<0) bi=h-1;
	    if(bi>=h) bi=0;
	    if(bj<0) bj=w-1;
	    if(bj>=w) bj=0;
	  }
	}
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
