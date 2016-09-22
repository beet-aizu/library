#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first1 ,
  BidirectionalIterator last1 ,
  BidirectionalIterator first2 ,
  BidirectionalIterator last2 )
{
  if (( first1 == last1 ) || ( first2 == last2 )) {
    return false ;
  }
  BidirectionalIterator m1 = last1 ;
  BidirectionalIterator m2 = last2 ; --m2;
  while (--m1 != first1 && !(* m1 < *m2 )){
  }
  bool result = (m1 == first1 ) && !(* first1 < *m2 );
  if (! result ) {
    while ( first2 != m2 && !(* m1 < * first2 )) {
      ++ first2 ;
    }
    first1 = m1;
    std :: iter_swap (first1 , first2 );
    ++ first1 ;
    ++ first2 ;
  }
  if (( first1 != last1 ) && ( first2 != last2 )) {
    m1 = last1 ; m2 = first2 ;
    while (( m1 != first1 ) && (m2 != last2 )) {
      std :: iter_swap (--m1 , m2 );
      ++ m2;
    }
    std :: reverse (first1 , m1 );
    std :: reverse (first1 , last1 );
    std :: reverse (m2 , last2 );
    std :: reverse (first2 , last2 );
  }
  return ! result ;
}
 
template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first ,
  BidirectionalIterator middle ,
  BidirectionalIterator last )
{
  return next_combination (first , middle , middle , last );
}
int n,m;
double l[21]={},a[21]={},b[21]={};
double dp[21][21]={{}};
double o=0;
int i,j,k;
int main(){
  
  cin >> n >> m;
  
  for(i=0;i<n;i++){
    cin >> l[i] >> a[i] >> b[i];
  }
  
  for(j=0;j<n;j++){
    for(k=0;k<n;k++){
      dp[j][k]=(l[j]-l[k])*(l[j]-l[k])+
	(a[j]-a[k])*(a[j]-a[k])+
	(b[j]-b[k])*(b[j]-b[k]);
    }
  }

  double sum=0;
  vector<int> data;
  for(i=0; i<n; i++){
    data.push_back(i);
  }
  do{
    sum=0;
    for(i=0;i<m;i++){
      for(j=i;j<m;j++){
      sum+=dp[data[i]][data[j]];
      }
    }
    if(o<sum)o=sum;
  }while(next_combination(data.begin(), data.begin()+m, data.end()));
 
  
  printf("%.6f\n",o);
  return 0;
}

