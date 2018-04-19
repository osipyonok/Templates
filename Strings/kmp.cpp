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

string str, pat;

vector<int> failure_function(string p)
{
	int sz = p.size();
	vector<int> f;
	f.assign(sz + 1, 0);

	int j = 0;
	f[0] = 0;

	for(int i = 1; i < sz; i++)
	{
		while(j >= 0 && p[i] != p[j])
		{
			if(j >= 1) j = f[j - 1];
			else j = -1;
		}

		j++;
		f[i] = j;
	}

	return f;
}

void match(vector<int> f, string p, string s)
{
	int psz = p.size(), sz = s.size();

	int j = 0;
	for(int i = 0; i < sz; i++)
	{
		while(j >= 0 && p[j] != s[i])
			if(j >= 1) j = f[j - 1];
			else j = -1;

		j++;
		if(j == psz)
		{
			j = f[j - 1];
			cout << "Found pattern in [" << i - psz + 1 << "; " << i << "]" << endl;
		}
	}
}

vector<int> f;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 

	f = failure_function(pat);
	match(f, pat, str);

	return 0;
}