#include<iostream>
#include<string>
#include<map>
using namespace std;
typedef pair<int,int> i_i;
int suit(char c){
  if(c=='#') return -1;
  if(c=='S') return 0;
  if(c=='H') return 1;
  if(c=='D') return 2;
  if(c=='C') return 3;
  return -1;
}
int num(char c){
  if(c=='A') return 14;
  if(c=='2') return 2;
  if(c=='3') return 3;
  if(c=='4') return 4;
  if(c=='5') return 5;
  if(c=='6') return 6;
  if(c=='7') return 7;
  if(c=='8') return 8;
  if(c=='9') return 9;
  if(c=='T') return 10;
  if(c=='J') return 11;
  if(c=='Q') return 12;
  if(c=='K') return 13;
  return -1;
}
int main(){
  char trump;
  int i,j,k;
  cin >> trump;
  int t = suit(trump);
  
  while(t!=-1){
    i_i player[4][13];
    string b;
    for(i=0;i<4;i++){
      for(j=0;j<13;j++){
	cin >> b;
	//cout << b << " ";
	player[i][j].first=num(b[0]);
	player[i][j].second=suit(b[1]);
      }
      //cout << endl;
    }
    /*
    for(i=0;i<4;i++){
      j=5;
	cout << player[i][j].first << ":" << player[i][j].second <<  " ";
      
      cout << endl;
    }
    */
    //cout << t << endl;
    int f1,m1,m2,id,fc;
    int ew=0,ns=0;
    int p;
    for(j=0;j<13;j++){
      f1=0;m1=0;m2=0;id=0;
      fc=player[p%4][j].second;
      //cout << p%4 ;
      for(i=0;i<4;i++){
	if(t==fc){
	  if(player[(i+p)%4][j].second==fc){
	    if(m1<player[(i+p)%4][j].first) {
	      m1=player[(i+p)%4][j].first;
	      id=(i+p)%4;
	    }
	  }
	}else if(player[(i+p)%4][j].second==t){
	  f1=1;
	  if(m2<player[(i+p)%4][j].first) {
	    m2=player[(i+p)%4][j].first;
	    id=(i+p)%4;
	  }
	}else if(f1==0&&player[(i+p)%4][j].second==fc){
	  if(m1<player[(i+p)%4][j].first) {
	    m1=player[(i+p)%4][j].first;
	    id=(i+p)%4;
	  }
	}	
      }
      if(id==0||id==2) ns++;
      else ew++;
      //cout << id ;
      p=id;
    }
    //cout << endl;
    if(ew>ns) cout << "EW " << (ew-6) << endl;
    else cout << "NS " << (ns-6) << endl;
    cin >> trump;
    t=suit(trump);
  }

}
