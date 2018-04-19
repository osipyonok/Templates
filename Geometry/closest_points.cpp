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

const int MAXN = (1 << 20);
const double eps = 0.000001;
const int inf = (int)1e17 + 42;


struct point
{
	int x, y;

	point() {x = 0; y = 0;}
	point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

bool cmpbyx(point a, point b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool cmpbyy(point a, point b)
{
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

vector<point> p;
int dist(point p_i, point p_j) { return (p_i.x - p_j.x) * (p_i.x - p_j.x) + (p_i.y - p_j.y) * (p_i.y - p_j.y); }

int rec(int l, int r)
{
	if(l >= r) return inf;

	int ret, mid = (l + r) >> 1;
	double d;
	ret = min(rec(l, mid), rec(mid + 1, r));
	d = sqrt(ret);

	vector<point> c;
	for(int i = l; i <= r; i++)
		if(abs(p[i].x - p[mid].x) <= d)
			c.push_back(p[i]);

	sort(c.begin(), c.end(), cmpbyy);

	for(int i = 0; i < c.size(); i++)
		for(int j = i + 1; j < c.size() && (c[j].y - c[i].y) <= d; j++)
		{
			ret = min(ret, dist(c[i], c[j]));
			d = sqrt(ret);
		}
		
	return ret;
}



 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 

	sort(p.begin(), p.end(), cmpbyx);

	int ans = rec(0, p.size() - 1);
	cout << ans << endl;

	return 0;
}