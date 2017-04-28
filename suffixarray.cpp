#include<bits/stdc++.h>
using namespace std;
#define int long long
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
  int a=0,b=S.length()+1;
  while(b-a>1){
    int c=(a+b)/2;
    if(S.compare(sa[c],T.length(),T)<0) a=c;
    else b=c;
  }
  return S.compare(sa[b],T.length(),T)==0;
}

int count(string &S,int *sa,string T){
  int sl=S.length(),tl=T.length();
  int a[2],b[2];
  for(int i=0;i<2;i++){
    a[i]=0;
    b[i]=sl;
    while(a[i]+1<b[i]){
      int c=(a[i]+b[i])/2;
      if(S.compare(sa[c],tl,T)<0||
	 (i&&S.compare(sa[c],tl,T)==0)) a[i]=c;
      else b[i]=c;
    }
  }
  if(S.compare(sa[b[0]],tl,T)!=0) return 0;
  if(a[1]<sl&&S.compare(sa[a[1]+1],tl,T)==0) a[1]++;
  if(b[0]> 0&&S.compare(sa[b[0]-1],tl,T)==0) b[0]--;
  return a[1]-b[0]+1;
}

struct RMQ{
  int n;
  vector<int> dat;
  const int def=INT_MAX;
  RMQ(){}
  RMQ(int n_){init(n_);}
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1,def);
  }
  void update(int k,int a){
    k+=n-1;
    dat[k]=a;
    while(k>0){
      k=(k-1)/2;
      dat[k]=min(dat[k*2+1],dat[k*2+2]);
    }
  }
  int query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return def;
    if(a<=l&&r<=b) return dat[k];
    else{
      int vl=query(a,b,k*2+1,l,(l+r)/2);
      int vr=query(a,b,k*2+2,(l+r)/2,r);
      return min(vl,vr);
    }
  }
  int query(int a,int b){
    return query(a,b,0,0,n);
  }
};

int getlcp(string &S,int p,string &T,int d){
  int i=0;
  int len=min((int)T.length()-d,(int)S.length()-p-d);
  while(i<len&&S[p+d+i]==T[d+i]) i++;
  return i;
}


int count(string &S,int *sa,string T,RMQ &rmq){
  int a[2],b[2];
  int sl=S.length(),tl=T.length();
  for(int i=0;i<2;i++){
    int p,l,r;
    p=tl;
    a[i]=0;
    b[i]=sl;
    l=getlcp(S,sa[a[i]],T,0);
    r=getlcp(S,sa[b[i]],T,0);
    while(b[i]-a[i]>1){
      int c=(a[i]+b[i])/2;
      //cout<<a[i]<<" "<<b[i]<<" "<<c<<endl;
      if(l>=r){
	int m=rmq.query(a[i],c);
	if(m<l) b[i]=c,r=m;
        else{
	  int k=l+getlcp(S,sa[c],T,l);
	  if(i){
	    if(k==p||S[sa[c]+k]<T[k]) a[i]=c,l=k;
	    else b[i]=c,r=k;
	  }else{
	    if(k==p) b[i]=c,r=k;
	    else if(S[sa[c]+k]<T[k]) a[i]=c,l=k;
	    else b[i]=c,r=k;
	  }
	}
      }else{
	int m=rmq.query(c,b[i]);
	if(m<r) a[i]=c,l=m;
        else{
	  int k=r+getlcp(S,sa[c],T,r);
	  if(i){
	    if(k==p||S[sa[c]+k]<T[k]) a[i]=c,l=k;
	    else b[i]=c,r=k;
	  }else{
	    if(k==p) b[i]=c,r=k;
	    else if(S[sa[c]+k]<T[k]) a[i]=c,l=k;
	    else b[i]=c,r=k;
	  }
	}
      }
    }
  }
  
  if(a[1]<sl&&getlcp(S,sa[a[1]+1],T,0)==tl) a[1]++;
  if(b[0]> 0&&getlcp(S,sa[b[0]-1],T,0)==tl) b[0]--;
  
  if(getlcp(S,sa[b[0]],T,0)!=tl) return 0;
  
  return a[1]-b[0]+1;
}

signed main(){
  return 0;
}
