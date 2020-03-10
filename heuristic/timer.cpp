#include<bits/stdc++.h>
using namespace std;

/**
 * @ignore
 */
//BEGIN CUT HERE
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

// AtCoder
const i64 CYCLES_PER_SEC = 2800000000;

struct Timer {
	i64 start;
	Timer(){reset();}
	void reset(){start=getCycle();}
	inline double get(){return (double)(getCycle()-start)/CYCLES_PER_SEC;}
	inline i64 getCycle(){
		u32 low,high;
		__asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
		return ((i64)low)|((i64)high<<32);
	}
};

Timer timer;
//END CUT HERE

//INSERT ABOVE HERE
void nxt(){
  static i64 x = 0;
  static i64 y = 1;
  x=(x<<10)+y;
  y=x/3;
}

signed main(){
  cout<<fixed<<setprecision(12);
  auto start1=clock(),stop1=clock();
  for(int i=0;i<1000000;i++) stop1=clock();

  double d=0;
  auto start2=clock();
  for(int i=0;i<1000000;i++) d+=timer.get();
  auto stop2=clock();

  cout<<(double)(stop1-start1)/CLOCKS_PER_SEC<<endl;
  cout<<(double)(stop2-start2)/CLOCKS_PER_SEC<<endl;
  return 0;
}
