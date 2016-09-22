#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
struct Point{int x,y;};
struct block{
  vector<Point> v;
};
int main(){
  int w,h;
  while(cin >> w >> h,w||h){
    string bu[75];
    int i,j,k;
    for(i=0;i<h;i++) cin >> bu[i];
    int st[70][70]={{}};
    int cr[70][70]={{}};
    int id[70][70]={{}};
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
        if(bu[i][j]=='.') {
          st[j][i]=0;
          cr[j][i]=0;
        }else {
          st[j][i]=bu[i][j]-'0';
          cr[j][i]=bu[i][j]-'0';
        }
      }
    }
    int c=0;
    queue<Point> q;
    Point p,b;
    int ax[]={1,-1,0,0};
    int ay[]={0,0,1,-1};
    vector<block> bs;
    block bl;
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
        if(cr[j][i]==0) continue;
        bl.v.clear();
        c=cr[j][i];
        p.x=j;p.y=i;
        q.push(p);
        while(!q.empty()){
          p=q.front();q.pop();
          if(cr[p.x][p.y]==0) continue;
          cr[p.x][p.y]=0;
          bl.v.push_back(p);
          for(k=0;k<4;k++) {
            b.x=p.x+ax[k];b.y=p.y+ay[k];
            if(b.x<0||b.x>w||b.y<0||b.y>=h) continue;
            if(c==cr[b.x][b.y]) q.push(b);
          }
        }
        bs.push_back(bl);
      }
    }
     
    fill(id[0],id[69],-1);
    for(i=0;i<bs.size();i++) {
      //cout << i << ":" << bs[i].v.size() << endl;
      for(j=0;j<bs[i].v.size();j++) {
        id[bs[i].v[j].x][bs[i].v[j].y] = i;
        //cout << bs[i].v[j].x << " " << bs[i].v[j].y << endl ;
      }
        //cout << endl;
    }
    bool f=true,h1=false;
    int idx=0;
    while(f){
      //cout << h << endl;
      f=false;
      queue<int> qi;
      for(i=h-1;i>=0;i--){
        if(f) break;
        for(j=0;j<w;j++){
          //cout << j << i << endl;
          if(id[j][i]!=-1) {
            //cout << j << i << endl;
            idx=id[j][i];
            //cout <<idx << ":" << endl;
            qi.push(idx);
            f=true;
            break;
          }
        }
      }
      int xl=w,xr=-1;
      for(i=0;i<bs[idx].v.size();i++){
         
        int bx=bs[idx].v[i].x,by=bs[idx].v[i].y;
         
        if(by==h-1){
          xl=min(xl,bx);
          xr=max(xr,bx);
          //cout << bx << xr << endl;
        }else if(st[bx][by+1]!=0&&id[bx][by+1]!=idx){
          xl=min(xl,bx);
          xr=max(xr,bx);
        }
      }
      int l=0,r=0,m=0;
      bool used[400];
      for(i=0;i<400;i++) used[i]=false;
      while(!qi.empty()){
        k=qi.front();qi.pop();
        //cout << k << endl;
        if(used[k]) continue;
        used[k]=true;
        for(i=0;i<bs[k].v.size();i++){
          int bx=bs[k].v[i].x,by=bs[k].v[i].y;
          if(by==0){
          }else if(id[bx][by-1]!=-1){
            qi.push(id[bx][by-1]);
          }
        }
      }
      double g=0;
      for(j=0;j<400;j++){
        if(!used[j]) continue;
        //cout << j;
        for(i=0;i<bs[j].v.size();i++){
          double bx=bs[j].v[i].x,by=bs[j].v[i].y;
          if(bx<xl) l++;
          else if(bx>xr) r++;
          else m++;
	  g+=bx+0.5;
        }
      }
      //cout << endl;
      //cout << xl << xr << endl;
      if(l+m+r==0) break;
      //cout << l <<":"<< m <<":"<< r << endl;
      //cout << xl <<":"<< xr<<endl;
      //cout << g/(l+m+r) << endl;
      //if(l+m<=r||r+m<=l) {
      if(g/(l+m+r)<=(double)xl||g/(l+m+r)>=(double)xr+1){
        h1=true;
        //cout << "x" << endl;
        break;
      } 
      for(i=0;i<bs[idx].v.size();i++){
        int bx=bs[idx].v[i].x,by=bs[idx].v[i].y;
        id[bx][by]=-1;
      }
      /*
      for(i=0;i<h;i++){
	for(j=0;j<w;j++) cout << id[j][i];
	cout << endl;
      }
      */
    }
     
    if(h1) cout << "UNSTABLE" << endl;
    else cout << "STABLE" << endl;
  }
  return 0;
}
