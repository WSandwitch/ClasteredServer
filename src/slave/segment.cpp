#include <cstdio>
#include <math.h>

#include "world.h"
#include "point.h"
#include "segment.h"

namespace clasteredServerSlave {
	
	segment::segment(){
		
	}

	segment::segment(point _a, point _b){
		a=_a;
		b=_b;
	}
	
	float segment::distanse(point &p){
		if (point::scalar(point::toVector(a,p), point::toVector(a,b))<0)
			return a.distanse(p);
		if (point::scalar(point::toVector(b,p), point::toVector(b,a))<0)
			return b.distanse(p);
		return fabs(((b.x-a.x)*(p.y-a.y)-(b.y-a.y)*(p.x-a.x))/length());
	}

	float segment::length(){
		return a.distanse(b);
	}

}

/*
using namespace clasteredServerSlave;
int main(){
	point p(0,0);
	point p1(5,5);
	point p2(0,5);
	segment s(p,p1);
	printf("dist %g\n", p.distanse(p1));
	printf("dist %g\n", s.distanse(p2));
}
*/
