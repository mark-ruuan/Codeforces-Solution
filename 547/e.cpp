#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N];
int main(){
	fast;
	ll n, m, sum = 0, mn = 1e18;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a[i];
		sum += a[i];
		if(n + sum <= 0){
			return cout << i + 1, 0;
		}
		mn = min(sum, mn);
	}

	ll fin = n + sum;
	if(fin >= n) return cout << -1, 0;
	fin = n - fin;
	mn = abs(mn);
	ll lo = 0, hi = (n / fin) + 1;
	//cerr << lo << " " << hi  << "\n";
	while(hi - lo > 1){
		ll mid = (hi + lo) >> 1LL;
		ll sub = n - (fin * mid);
		if(sub <= mn){
			hi = mid;
		}
		else lo = mid;
	}
	//cerr << hi << " ";
	ll t = hi;
	t *= m;
	n = n - (hi * fin);
	sum = 0;
	for(int i = 0; i < m; i++){
		sum += a[i];
		if(n + sum <= 0){
			return cout << t + i + 1, 0;
		}
	}
	
	return 0;
}

