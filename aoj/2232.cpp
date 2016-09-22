#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct xy{int x,y;};
int main(){
  int h,w,n;
  cin >> h >> w >> n;
  int bl[30][30]={{}};
  int bbl[30][30]={{}};
  int abl[30][30]={{}};
  int i,j,k;
  string str;
  for(i=0;i<h;i++){
    cin >> str;
    for(j=0;j<w;j++){
      if(str[j]=='.') bl[j][i]=0;
      else bl[j][i]=str[j]-'A'+1;
    }
  }
  int f=0;
  /*
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      cout << bl[j][i];
    }
    cout << endl;
  }
  cout << endl;
  */
  for(i=0;i<h;i++){
    for(j=0;j<w;j++){
      abl[j][i]=bl[j][i];
    }
  }
  
  int o=1;
  for(int a=0;a<w-1;a++){
    for(int c=0;c<h;c++){
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	bl[j][i]=abl[j][i];
      }
    }

    //if(bl[a][c]==0||bl[a+1][c]==0) continue;
    bl[a][c]=abl[a+1][c];
    bl[a+1][c]=abl[a][c];
    for(j=0;j<w;j++){
      vector <int> vx;
      for(i=0;i<h;i++) if(bl[j][i]!=0) vx.push_back(bl[j][i]);
      int vs=vx.size();
      for(i=0;i<h-vs;i++) {
	bl[j][i]=0;
      }
      for(i=h-vs;i<h;i++) {
	bl[j][i]=vx[i+vs-h];
      }
      
    }
    /*
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	cout << bl[j][i];
      }
      cout << endl;
    }
    cout << "a" << endl;
    */
    f=0;
    while(f==0){
      f=1;
      vector <xy> v;
      xy bxy;
      for(i=0;i<h;i++){
	for(j=0;j<w;j++){
	  bbl[j][i]=bl[j][i];
	}
      }
      int l,b;
      for(i=0;i<h;i++){
	l=1;b=bbl[0][i];
	bxy.y=i;
	for(j=1;j<w;j++){
	  if(b==bbl[j][i]) l++;
	  else{
	    b=bbl[j][i];
	    if(l>=n) {
	      for(k=1;k<=l;k++){
		bxy.x=j-k;
		v.push_back(bxy);
	      }
	    }
	    l=1;
	  }
	  if(j==w-1){
	    if(l>=n) {
	      for(k=0;k<l;k++){
		bxy.x=j-k;
		v.push_back(bxy);
	      }
	    }
	  }
	}
      }
      
      for(j=0;j<w;j++){
	l=1;b=bbl[j][0];
	bxy.x=j;
	for(i=1;i<h;i++){
	  if(b==bbl[j][i]) l++;
	  else{
	    
	    if(l>=n) {
	      //if(b!=0) cout << l << endl;
	      for(k=1;k<=l;k++){
		bxy.y=i-k;
		v.push_back(bxy);
	      }
	    }
	    b=bbl[j][i];
	    l=1;
	  }
	  if(i==h-1){
	    if(l>=n) {
	      //if(b!=0) cout << l << endl;
	      for(k=0;k<l;k++){
		bxy.y=i-k;
		v.push_back(bxy);
	      }
	    }
	  }
	}
      }
      
      for(i=0;i<v.size();i++){
	if(bl[v[i].x][v[i].y]!=0) f=0;
	bl[v[i].x][v[i].y]=0;
      }
      
      
      for(j=0;j<w;j++){
	vector <int> vx;
	for(i=0;i<h;i++) if(bl[j][i]!=0) vx.push_back(bl[j][i]);
	int vs=vx.size();
	for(i=0;i<h-vs;i++) {
	  bl[j][i]=0;
	}
	for(i=h-vs;i<h;i++) {
	  bl[j][i]=vx[i+vs-h];
	}
	
      }
      
      /*
      for(i=0;i<h;i++){
	for(j=0;j<w;j++){
	  cout << bl[j][i];
	}
	cout << endl;
      }
      cout <<"e" <<  endl;
      */
    }
    int x=0;
    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
	x+=bl[j][i];
      }
    }
    if(x==0) o=0;
  }
  }
  if(o==0) cout << "YES" << endl;
  else cout << "NO" << endl; 
  return 0;
}
