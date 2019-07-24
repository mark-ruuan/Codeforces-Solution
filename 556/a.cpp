#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n, m, k, mn = 1e16, mx = 0;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		mn = min(mn, x);
	}
	for(int i = 0; i < m; i++){
		ll x;
		cin >> x;
		mx = max(mx, x);
	}
	ll buy = k / mn;
	ll rem = k % mn;
	buy = buy * mx;
	cout << max(k, buy + rem);
	
	return 0;
}

