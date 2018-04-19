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
const int bound = 1000000;
const ll mod = (ll)1e9 + 7;

ll bin_pow(ll x, ll p, ll MOD)
{
    if(p == 0) return 1;
    if(p % 2 == 1) return (x * bin_pow(x, p - 1, MOD)) % MOD;
    ll half = bin_pow(x, p / 2, MOD);
    return (half * half) % MOD;
}

int lp[bound + 1], phi[bound + 1];
vector<int> pr;

template<class T>
vector<T> get_divs(T x)
{
    if(x <= bound)
    {
        vector<T> ret;
        while(x != 1) { ret.push_back(lp[x]); x /= lp[x]; }
        return ret;
    }

    vector<T> ret;
    for(T d = 2; d * 1ll * d <= x; d++)
        while(x % d == 0) ret.push_back(d), x /= d;

    if(x != 1) ret.push_back(x);
    return ret;
}

ll gcd(ll a, ll b, ll &x, ll &y)
{
	if(a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}

	ll x1, y1, g = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;

	return g;
}

// phi = Функция Эйлера - количество натуральных чисел, меньших n и взаимно простых с ним. 
void prepare()
{
    phi[1] = 1;
    for(int i = 2; i <= bound; i++)
    {
        if(lp[i] == 0) lp[i] = i, phi[i] = i - 1, pr.push_back(i);
        else if(lp[i] == lp[i / lp[i]]) phi[i] = phi[i / lp[i]] * lp[i];
        else phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        for(int j = 0; j < pr.size() && i * 1ll * pr[j] <= bound && pr[j] <= lp[i]; j++)
            lp[i * pr[j]] = pr[j];
    }
}

ll gcd(ll a, ll b)
{
    if(a == 0 || b == 0) return a + b;
    return __gcd(a, b);
}

ll get_phi(ll x)
{
    ll cop = x, ret = x;
    for(ll div = 2; div * div <= cop; div++)
        if(cop % div == 0)
        {
            while(cop % div == 0) cop /= div;
            ret /= div;
            ret *= (div - 1);
        }

    if(cop != 1) ret /= cop, ret *= (cop - 1);
    return ret;
}

ll pinv(ll x, ll MOD) { return bin_pow(x, MOD - 2, MOD); }

ll inv(ll x, ll MOD)
{
    if(gcd(x, MOD) != 1) return -1;
    if(MOD <= bound) return bin_pow(x, phi[MOD] - 1, MOD);
    return bin_pow(x, get_phi(MOD) - 1, MOD);
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 


	return 0;
}