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

const int MAXN = (int)1e5 + 42 + 17;
const int MAXD = 5;

inline int64_t sq(int x) { return x * 1ll * x; }

struct point
{
	int c[MAXD];
	point() { }
};

struct cmp
{
	int current_d;
	cmp() { current_d = 0; }
	cmp(int d) { current_d = d; }
	bool operator() (const point& a, const point& b)  { return a.c[current_d] < b.c[current_d]; }
}; 

int64_t sq_dist(point a, point b, int d)
{
	int64_t answer = 0;
	for(int i = 0; i < d; i++)
		answer += sq(a.c[i] - b.c[i]);

	return answer;
}

struct kd_tree
{
	struct node
	{
		point p;
		int L, R, axis;
		node() { L = -1; R = -1; }
		node(point _p) { L = -1; R = -1; p = _p; }
	};

	int psz = 0, D, root;
	node tr[MAXN << 2];

	kd_tree() { D = 0; psz = 0; }	
	kd_tree(int d) { D = d; psz = 0; }

	int new_node() { return psz++; }

	int build(point *from, point *to, int axis)
	{
		if(to - from == 0) 
			return -1;
	
		point *mid = from + (to - from) / 2;
		
		nth_element(from, mid, to, cmp(axis));
	
		int c_node = new_node();
		tr[c_node] = node(*mid);
		
		tr[c_node].axis = axis;

		tr[c_node].L = build(from, mid, (axis + 1) % D);
		tr[c_node].R = build(mid + 1, to, (axis + 1) % D);

		return c_node;
	}

	void init(point *from, point *to, int d) 
	{ 
		D = d;
		random_shuffle(from, to);
		root = build(from, to, 0);  
	}

	void query(int idx, point q, int64_t &answer)
	{
		if(idx == -1) return;
		answer = min(answer, sq_dist(q, tr[idx].p, D));
		
		if(tr[idx].p.c[tr[idx].axis] <= q.c[tr[idx].axis])
		{
			query(tr[idx].R, q, answer); 
			if(tr[idx].L != -1 && q.c[tr[idx].axis] - sqrt(answer) <= tr[idx].p.c[tr[idx].axis]) query(tr[idx].L, q, answer); 
		}		
		else
		{
			query(tr[idx].L, q, answer); 
			if(tr[idx].R != -1 && q.c[tr[idx].axis] + sqrt(answer) >= tr[idx].p.c[tr[idx].axis]) query(tr[idx].R, q, answer); 
		}
	}

	double nearest_neigbhor(point q)
	{
		int64_t answer = (1ll << 62ll);
		query(root, q, answer);
		return sqrt(answer); 
	}
};


 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 

	int n, d;
	point li[MAXN];
	
	cin >> n >> d;
	for(int i = 0; i < n; i++)
		for(int x = 0; x < d; x++)
			cin >> li[i].c[x];
			
	kd_tree t;
	
	t.init(li, li + n, d);

	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		point q;
		for(int x = 0; x < d; x++)
			cin >> q.c[x];

		cout << setprecision(10) << fixed << t.nearest_neigbhor(q) << endl;
	}
	

	return 0;
}