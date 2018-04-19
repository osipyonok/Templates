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
const double dinf = (double)1e17;
const double eps = 0.00000000000001;

struct point
{
	double x, y;
	point() {x = 0; y = 0;}
	point(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
};

bool cmp(point a, point b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

double slope(point a, point b)
{
	double deltax = b.x - a.x;
	double deltay = b.y - a.y;
	if(max(-deltax, deltax) < eps) return (((deltax < 0) ? (-1) : 1) * deltay < 0) ? (-dinf) : (dinf);

	return deltay / deltax; 
}

struct convex_hull
{
	vector<point> st;
	convex_hull() {st.clear();}
	
	void compute_hull(vector<point> vec)
	{
		sort(vec.begin(), vec.end(), cmp);
	
		for(int i = 0; i < (int)vec.size(); i++)
		{
			while(st.size() >= 2 && slope(st[st.size() - 2], vec[i]) >= slope(st[st.size() - 2], st[st.size() - 1])) 
				st.pop_back();
			st.push_back(vec[i]);
		}
		
		st.pop_back();
		int k = st.size();
	
		for(int i = vec.size() - 1; i >= 0; i--)
		{
			while(st.size() - k >= 2 && slope(vec[i], st[st.size() - 2]) >= slope(st[st.size() - 1], st[st.size() - 2]))
				st.pop_back();
			st.push_back(vec[i]);
		}

		st.pop_back();
	}
};
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 

	return 0;
}