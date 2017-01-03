#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 200050
int n,k;
int r[MAX_N+1],r2[MAX_N+1];
int t[MAX_N+1];
bool compare_sa(int i,int j){
  if(r[i]!=r[j]) return r[i]<r[j];
  else{
    int ri=i+k<=n?r[i+k]:-1;
    int rj=j+k<=n?r[j+k]:-1;
    return ri<rj;
  }
}
void constract_sa(string S, int *sa){
  n=S.length();
  for(int i=0;i<=n;i++){
    sa[i]=i;
    r[i]=i<n?S[i]:-1;
  }
  for(k=1;k<=n;k*=2){
    sort(sa,sa+n+1,compare_sa);
    t[sa[0]]=0;
    for(int i=0;i<=n;i++){
      t[sa[i]]=t[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
    }
    for(int i=0;i<=n;i++){
      r[i]=t[i];
    }
  }
}
void constract_lcp(string S,int *sa,int *lcp){
  for(int i=0;i<=n;i++) r2[sa[i]]=i;
  int h=0;
  lcp[0]=0;
  for(int i=0;i<n;i++){
    int j=sa[r2[i]-1];
    if(h>0) h--;
    for(;j+h<n&&i+h<n;h++){
      if(S[j+h]!=S[i+h]) break;
    }
    lcp[r2[i]-1]=h;
  }
}
bool contains(string S,int *sa,string T){
  int a=0,b=S.length();
  while(b-a>1){
    int c=(a+b)/2;
    if(S.compare(sa[c],T.length(),T)<0) a=c;
    else b=c;
  }
  return S.compare(sa[b],T.length(),T)==0;
}

int main(){
  return 0;
}
