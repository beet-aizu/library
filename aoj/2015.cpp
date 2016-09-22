#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  
  int w,h;
  cin >> w >> h;
  int wl[1501]={},hl[1501]={};
  int wb,hb;
  int i,j,k;
  while(w!=0){
    for(i=0;i<w;i++) {
      cin >> wb;
      wl[i+1]=wl[i]+wb;
      
    }
    for(i=0;i<h;i++) {
      cin >> hb;
      hl[i+1]=hl[i]+hb;
    }
    vector <int> ws,hs;
    
    for(i=0;i<=w;i++){
      for(j=i+1;j<=w;j++){
	ws.push_back(wl[j]-wl[i]);
      }
    }
    for(i=0;i<=h;i++){
      for(j=i+1;j<=h;j++){
	hs.push_back(hl[j]-hl[i]);
      }
    }
    
    sort(ws.begin(),ws.end());
    sort(hs.begin(),hs.end());
    /*
    for(i=0;i<ws.size();i++) cout << ws[i] << ",";
    cout << endl;
    for(i=0;i<hs.size();i++) cout << hs[i] << ",";
    cout << endl;
    */
    int wc=0,hc=0;
    int x,y;
    int o=0;
    while(!(wc>=ws.size()||hc>=hs.size())){
      
      if(ws[wc]==hs[hc]){
	x=0;y=0;
	while(ws[wc+x]==ws[wc]&&wc+x<ws.size()) x++;
	while(hs[hc+y]==hs[hc]&&hc+y<hs.size()) y++;
	//cout << x*y << endl;
	o+=x*y;
	wc+=x;hc+=y;
      }else if(ws[wc]>hs[hc]){
	while(ws[wc]>hs[hc]&&hc<hs.size()) hc++;
      }else{
	while(ws[wc]<hs[hc]&&wc<ws.size()) wc++;
      }
      //cout << wc<<":"<<hc<<endl;
    }
    cout << o << endl;
    
    cin >> w >> h;
  }
  return 0;
}
