#pragma comment(linker, "/STACK:66777216")

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cstdarg>
#include <cstring>
#include <cstdio>
#include <memory>
#include <random>
#include <cmath>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
 
#define INF 1000010000
#define nl '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pdd pair<double,double>
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) for( int i = 0; i < n; ++i )
#define repi(i,n) for( int i = 1 ; i <= n; ++i )
#define repn(i,n) for( int i = n - 1 ; i >= 0 ; --i )
#define repf(j,i,n) for( int j = i ; j < n ; ++j )
#define die(s) {std::cout << s << nl;}
#define dier(s) {std::cout << s; return 0;}
#define vi vector<int>
typedef long long ll;

using namespace std;
	
const double EPS = 1e-9;
#define pi 3.1415926535897932384626433832795028841971

// signed
int triangle_area_2 (int x1, int y1, int x2, int y2, int x3, int y3) {
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

double triangle_area (int x1, int y1, int x2, int y2, int x3, int y3) {
	return abs (triangle_area_2 (x1, y1, x2, y2, x3, y3)) / 2.0;
}

bool clockwise (int x1, int y1, int x2, int y2, int x3, int y3) {
	return triangle_area_2 (x1, y1, x2, y2, x3, y3) < 0;
}

bool counter_clockwise (int x1, int y1, int x2, int y2, int x3, int y3) {
	return triangle_area_2 (x1, y1, x2, y2, x3, y3) > 0;
}

/*lines intersection*/
struct pt {
	double x, y;
	bool operator< (const pt & p) const {
		return x < p.x-EPS || abs(x-p.x) < EPS && y < p.y - EPS;
	}
};
 
struct line {
	double a, b, c;
	
	line() {}
	line (pt p, pt q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = - a * p.x - b * p.y;
		norm();
	}
 
	void norm() {
		double z = sqrt (a*a + b*b);
		if (abs(z) > EPS)
			a /= z,  b /= z,  c /= z;
	}
 
	double dist (pt p) const {
		return a * p.x + b * p.y + c;
	}
};
 
 
double det (double a, double b, double c, double d) {
	return a * d - b * c;
}
 
bool intersect (line m, line n, pt & res) {
	double zn = det (m.a, m.b, n.a, n.b);
	if (abs (zn) < EPS)
		return false;
	res.x = - det (m.c, m.b, n.c, n.b) / zn;
	res.y = - det (m.a, m.c, n.a, n.c) / zn;
	return true;
}
 
bool parallel (line m, line n) {
	return abs (det (m.a, m.b, n.a, n.b)) < EPS;
}
 
bool equivalent (line m, line n) {
	return abs (det (m.a, m.b, n.a, n.b)) < EPS
		&& abs (det (m.a, m.c, n.a, n.c)) < EPS
		&& abs (det (m.b, m.c, n.b, n.c)) < EPS;
}

/*segment intersection*/
inline int det (int a, int b, int c, int d) {
	return a * d - b * c;
}
 
inline bool between (int a, int b, double c) {
	return min(a,b) <= c + EPS && c <= max(a,b) + EPS;
}
 
inline bool intersect_1 (int a, int b, int c, int d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max(a,c) <= min(b,d);
}
 
bool intersect (pt a, pt b, pt c, pt d) {
	int A1 = a.y-b.y,  B1 = b.x-a.x,  C1 = -A1*a.x - B1*a.y;
	int A2 = c.y-d.y,  B2 = d.x-c.x,  C2 = -A2*c.x - B2*c.y;
	int zn = det (A1, B1, A2, B2);
	if (zn != 0) {
		double x = - det (C1, B1, C2, B2) * 1. / zn;
		double y = - det (A1, C1, A2, C2) * 1. / zn;
		return between (a.x, b.x, x) && between (a.y, b.y, y)
			&& between (c.x, d.x, x) && between (c.y, d.y, y);
	}
	else
		return det (A1, C1, A2, C2) == 0 && det (B1, C1, B2, C2) == 0
			&& intersect_1 (a.x, b.x, c.x, d.x)
			&& intersect_1 (a.y, b.y, c.y, d.y);
}

/*polygon area*/
double polygon_area(vector<pdd> & v) {
	double a = 0.0;
	int sz = v.size();
	for (int i = 0; i < sz; ++i) {
		a += v[i].first * (v[(i + 1) % sz].second - v[(sz + i - 1) % sz].second);
	}
	return 0.5 * abs(a);
}

/*line and circle intersection*/
void landc(){
	double r, a, b, c; // входные данные
	// 0,0 - center of the circle
	double x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
	if (c*c > r*r*(a*a+b*b)+EPS)
		puts ("no points");
	else if (abs (c*c - r*r*(a*a+b*b)) < EPS) {
		puts ("1 point");
		cout << x0 << ' ' << y0 << '\n';
	}
	else {
		double d = r*r - c*c/(a*a+b*b);
		double mult = sqrt (d / (a*a+b*b));
		double ax,ay,bx,by;
		ax = x0 + b * mult;
		bx = x0 - b * mult;
		ay = y0 - a * mult;
		by = y0 + a * mult;
		puts ("2 points");
		cout << ax << ' ' << ay << '\n' << bx << ' ' << by << '\n';
	}
}

/*two circles intersection*/
/*
x2 + y2 = r12
(x - x2)2 + (y - y2)2 = r22

<=> intersection of circle an line
x2 + y2 = r12
Ax + By + C = 0,
A = -2x_2,
B = -2y_2,
C = x_2^2 + y_2^2 + r_1^2 - r_2^2.
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 



	return 0;
}