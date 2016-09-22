#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct team{
  int point,penalty,wrong[11],id;
  bool operator<(const team& a)  const{
    return point == a.point ? (penalty == a.penalty ? id < a.id : penalty < a.penalty) : point > a.point; 
  }
};
int main(){
  int t,p,r,i,j,k,b,o,tid,pid,time;
  string str;
  cin >> t >> p >> r;
  while(t!=0||p!=0||r!=0){
    vector <team> teams;
    for(i=1;i<=t;i++){
      team t;
      t.id=i;
      t.point=0;
      for(j=0;j<11;j++)
      t.wrong[j]=0;
      t.penalty=0;
      teams.push_back(t);
    }
    for(i=0;i<r;i++){
      cin >> tid >> pid >> time >> str;
      if(str[0]=='C'){
	teams[tid-1].point++;
	teams[tid-1].penalty+=teams[tid-1].wrong[pid]*1200+time;
      }else{
	teams[tid-1].wrong[pid]++;
      }
    }
    sort(teams.begin(),teams.end());
    for(i=0;i<t;i++){
      cout << teams[i].id << " " << teams[i].point << " " << teams[i].penalty << endl;
    }
    cin >> t >> p >> r;
  }
  return 0;
}
