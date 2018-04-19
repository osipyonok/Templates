#include<bits/stdc++.h>
 
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
#define sz(c) (c).size()
#define rep(i,n) for( int i = 0; i < n; ++i )
#define repi(i,n) for( int i = 1 ; i <= n; ++i )
#define repn(i,n) for( int i = n - 1 ; i >= 0 ; --i )
#define repf(j,i,n) for( int j = i ; j < n ; ++j )
#define die(s) {std::cout << s << nl;}
#define dier(s) {std::cout << s; return 0;}
#define vi vector<int>
typedef long long ll;
#define MAXN 1E5 + 10
using namespace std;
 
int n;
 
vi t(2 * MAXN , 0);
 
void build(){
	for(int i = n - 1 ; i > 0 ; --i){
		t[i] = t[2 * i] + t[2 * i + 1];
	}
}
 
void modify(int p , int val){
	for(t[p += n] = val ; p > 1 ; p /= 2){
		t[p / 2] = t[p] + t[p ^ 1];
	}
}
 
int sum(int l , int r){//[l , r)
	int res = 0;
	for(l += n , r += n ; l < r ; l /= 2 , r /= 2){
		if(l % 2){
			res += t[l];
			++l;
		}
		if(r % 2){
			--r;
			res += t[r];
		}
	}
	return res;
}
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 
	cin >> n;
	rep(i , n){
		cin >> t[n + i];
	}
	build();
	int q;
	cin >> q;
	rep(i , q){
		char type;
		cin >> type;
		if(type == 'M'){
			int el , val;
			cin >> el >> val;
			--el;
			modify(el , val);
		}else{
			int l , r;
			cin >> l >> r;
			--l , --r;
			cout << sum(l , r) << nl;
		}
	}
	return 0;
}