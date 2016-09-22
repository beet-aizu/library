#include <bits/stdc++.h>
#include "testlib.h"
#include "constraints.h"

using namespace std;
typedef long double Double;

// -------------------- library --------------------
const Double EPS=1e-9;
const Double PI=acos(-1);

int Signum(Double x){
	return x<-EPS?-1:x>EPS?1:0;
}

struct Point{
	Double x,y;
	Point(){}
	Point(Double x,Double y):x(x),y(y){}
	Point& operator+=(Point p){x+=p.x,y+=p.y; return *this;}
	Point& operator-=(Point p){x-=p.x,y-=p.y; return *this;}
	Point& operator*=(Double c){x*=c,y*=c; return *this;}
	Point& operator/=(Double c){x/=c,y/=c; return *this;}
};
Point operator+(Point a,Point b){return a+=b;}
Point operator-(Point a,Point b){return a-=b;}
Point operator*(Point a,Double c){return a*=c;}
Point operator*(Double c,Point a){return a*=c;}
Point operator/(Point a,Double c){return a/=c;}
bool operator==(Point a,Point b){return abs(a.x-b.x)<EPS && abs(a.y-b.y)<EPS;}
bool operator!=(Point a,Point b){return !(a==b);}

Double Abs(Point p){
	return sqrt(p.x*p.x+p.y*p.y);
}
Double Abs2(Point p){
	return p.x*p.x+p.y*p.y;
}
Double Arg(Point p){
	return atan2(p.y,p.x);
}
Double Dot(Point a,Point b){
	return a.x*b.x+a.y*b.y;
}
Double Cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}
Point Rot(Point p,Double t){
	return Point(cos(t)*p.x-sin(t)*p.y,sin(t)*p.x+cos(t)*p.y);
}

int CCW(Point a,Point b,Point c){
	b-=a,c-=a;
	Double d=max(Abs(b),Abs(c));
	if(int sign=Signum(Cross(b,c)/d))
		return sign; // 1:ccw,-1:cw
	if(Dot(b,c)<-EPS)
		return -2;   // c-a-b
	if(Abs2(b)<Abs2(c)-EPS)
		return 2;    // a-b-c
	return 0;      // a-c-b (inclusive)
}

Double Area(const vector<Point>& ps){
	Double res=0;
	for(int i=2;i<ps.size();i++)
		res+=Cross(ps[i-1]-ps[0],ps[i]-ps[0])/2;
	return res;
}

bool CoverGP(const vector<Point>& ps,Point p){
	for(int i=0;i<ps.size();i++){
		int ccw=CCW(ps[i],ps[(i+1)%ps.size()],p);
		if(!(ccw==1 || ccw==0))
			return false;
	}
	return true;
}

struct Line{
	Point pos,dir;
	Line(){}
	Line(Point p,Point d):pos(p),dir(d){}
	Line(Double x,Double y,Double u,Double v):pos(x,y),dir(u,v){}
};

struct Segment{
	Point pos,dir;
	Segment(){}
	Segment(Point p,Point d):pos(p),dir(d){}
	Segment(Double x,Double y,Double u,Double v):pos(x,y),dir(u,v){}
	Segment(Line l):pos(l.pos),dir(l.dir){}
	operator Line()const{return Line(pos,dir);}
};

Point InterPointLL(Line a,Line b){
	if(abs(Cross(a.dir,b.dir))<EPS) return a.pos;
	return a.pos+Cross(b.pos-a.pos,b.dir)/Cross(a.dir,b.dir)*a.dir;
}
Point InterPointLS(Line l,Segment s){
	return InterPointLL(Line(s),l);
}

vector<Point> ConvexCut(const vector<Point>& ps,Line l){
	int n=ps.size();
	vector<Point> res;
	for(int i=0;i<n;i++){
		int c1=CCW(l.pos,l.pos+l.dir,ps[i]);
		int c2=CCW(l.pos,l.pos+l.dir,ps[(i+1)%n]);
		if(c1!=-1)
			res.push_back(ps[i]);
		if(c1*c2==-1)
			res.push_back(InterPointLS(l,Segment(ps[i],ps[(i+1)%n]-ps[i])));
	}
	return res;
}
// -------------------------------------------------

int main(int argc,char** argv)
{
	setName("judge for Voronoi");
	registerTestlibCmd(argc,argv);
	
	// input
	int n=inf.readInt();
	int m=inf.readInt();
	vector<Point> ps(n);
	for(int i=0;i<n;i++){
		ps[i].x=inf.readInt();
		ps[i].y=inf.readInt();
	}
	vector<int> rs(m);
	for(int i=0;i<m;i++)
		rs[i]=inf.readInt();
	
	// submission
	vector<Point> qs(m);
	for(int i=0;i<m;i++){
		qs[i].x=ouf.readDouble();
		qs[i].y=ouf.readDouble();
		ouf.readEoln();
	}
	if(!ouf.eof())
		quitf(_fail,"#output_lines >= %d",m);
	
	// ボロノイ点の距離
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(j==i) continue;
			if(Abs(qs[j]-qs[i])<DIST_EPS)
				quitf(_wa,"distance between q_%d and q_%d < %e",i+1,j+1,DIST_EPS);
		}
	}
	
	// ボロノイ点が凸多角形の内側にあるか
	for(int i=0;i<m;i++)
		if(!CoverGP(ps,qs[i]))
			quitf(_wa,"q_%d is outside a boundary of given convex polygon.",i+1);
	
	// ボロノイ領域の面積
	Double area=Area(ps);
	int rsum=accumulate(rs.begin(),rs.end(),0);
	
	for(int i=0;i<m;i++){
		vector<Point> ts=ps;
		for(int j=0;j<m;j++){
			if(j==i) continue;
			Point c=(qs[i]+qs[j])/2;
			Line l(c,Rot(qs[j]-qs[i],PI/2));
			ts=ConvexCut(ts,l);
			/*
			   cout << l.pos.x << ' ' << l.pos.y << ' ' << l.dir.x << ' ' << l.dir.y << endl;
			   for(Point &p : ts) {
			   cout << p.x << ' ' << p.y << endl;
			   }
			   cout << "-----" << endl;
			   */
		}
		Double expected=area*rs[i]/rsum;
		Double received=Area(ts);
		if(!doubleCompare(expected,received,AREA_EPS))
			quitf(_wa,"area of voronoi region %d is expected %.10Lf, found %.10Lf",i+1,expected,received);
	}
	
	quitf(_ok,"ac.");
}
