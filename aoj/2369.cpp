#include<iostream>
#include<string>
using namespace std;
string o;
void rec(string str){
  //cout << str << endl;
  string buf=str;
  if(buf.find("mmewe")!=-1){
    buf.replace(buf.find("mmewe"),5,"me");
    rec(buf);
  }else if(buf.find("emeww")!=-1){
    buf.replace(buf.find("emeww"),5,"ew");
    rec(buf);
  }else{
    if(buf==""||buf=="mew") o="Cat";
    else o="Rabbit";
  }
}
int main(){
  string str;
  cin >> str;
  rec(str);
  cout << o << endl;
  return 0;
}
