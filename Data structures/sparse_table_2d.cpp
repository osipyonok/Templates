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
	

struct SparseTable2D{
	vector<vector<vector<vector<int>>>> sparse;
	vi prec_lg2;
	int R , C;
	
	static int operation(const int a , const int b){
		return max(a , b);
	}
 
	int query(int x1 , int y1 , int x2 , int y2 , bool build = false){
		int x_sz = x2 - x1 + 1;
		int y_sz = y2 - y1 + 1;
		int k1 = (x_sz == 1) ? 0 : prec_lg2[build ? (x_sz - 1) : x_sz];
		int k2 = (y_sz == 1) ? 0 : prec_lg2[build ? (y_sz - 1) : y_sz];
		int NW = sparse[k1][k2][x1][y1];
		int NE = sparse[k1][k2][x1][y_sz - (1 << k2) + y1];			   
		int SW = sparse[k1][k2][x_sz - (1 << k1) + x1][y1]; 		   
		int SE = sparse[k1][k2][x_sz - (1 << k1) + x1][y_sz - (1 << k2) + y1]; 
		return operation(operation(NW , NE) , operation(SW , SE));
	}
 
	SparseTable2D(vector<vi> & arr , int R , int C){
		this->R = R;
		this->C = C;
		
		prec_lg2.resize(max(R , C) + 1000);
		for(int i = 2 ; i < prec_lg2.size() ; ++i){		
			prec_lg2[i] = ((i & (i - 1)) == 0) ? prec_lg2[i-1] + 1 : prec_lg2[i-1];
		}
		
		int k1 = prec_lg2[R] + 1;
		int k2 = prec_lg2[C] + 1;
		sparse = vector<vector<vector<vector<int>>>>(
			k1, vector<vector<vector<int>>>(
				k2, vector<vector<int>>(
					R, vector<int>(
						C, 0	
					)	
				)	
			)	
		);

		for(int i = 0 ; i < R ; ++i)
			for(int j = 0 ; j < C ; ++j)
				sparse[0][0][i][j] = arr[i][j];
 
		for(int h = 0 ; h < k1 ; ++h){
			for(int v = 0 ; v < k2 ; ++v){
				if(!(h == 0 && v == 0)){
					for(int i = 0 ; i + (1 << h) <= R ; ++i){
						for(int j = 0 ; j + (1 << v) <= C ; ++j){
							sparse[h][v][i][j] = query(i , j , i + (1 << h) - 1, 
								j + (1 << v) - 1 , true);
						}
					}
				}
			}
		}
 
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 

	int n = 15 , m = 68;
	vector<vi> a(n , vi(m , 0));
	rep(i , n){
		rep(j , m){
			a[i][j] = 1 + rand() % 322;
		}
	}
	
	SparseTable2D table(a , n , m);
	

	return 0;
}