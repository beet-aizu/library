#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
struct rollinghash{
  string S;
  ull B;
  vector<ull> hash,p;
  int len;
  rollinghash(){}
  rollinghash(string S,ull B=1000000007LL):S(S),B(B){init();};
  void init(){
    len=S.length();
    hash.resize(len+1);
    p.resize(len+1);
    hash[0]=0;p[0]=1;
    for(int i=0;i<len;i++){
      hash[i+1]=hash[i]*B+S[i];
      p[i+1]=p[i]*B;
    }
  }
  //S[l,r)
  ull find(int l,int r){
    return hash[r]-hash[l]*p[r-l];
  }
};
int main(){
  return 0;
}
