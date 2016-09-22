#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct tree{
  vector <int> children;
  string str;
  int d;
};

vector <tree> ts;
int v[1005]={};
void saiki(int n){
  if(v[n]==0){
    string buf="";
    for(int i=0;i<ts[n].d;i++) buf+=".";
    cout << buf << ts[n].str << endl;
    v[n]=1;
    for(int i=0;i<ts[n].children.size();i++){
      saiki(ts[n].children[i]);
    }
  }
}
int main(){
  int n;
  int b;
  string buf;
  tree t;
  
  int i,j,k;
  cin >> n;
  cin >> k;
  cin >> t.str;
  t.d=0;
  ts.push_back(t);
  for(i=1;i<n;i++){
    cin >> k;
    k--;
    cin >> t.str;
    t.d=ts[k].d+1;
    ts[k].children.push_back(i);
    ts.push_back(t);
  }
  for(i=0;i<n;i++){
    saiki(i);
  }
}
