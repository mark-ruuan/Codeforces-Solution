#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll n, k;
std::vector<ll> v;
ll calc(ll mid){
	vector<ll> p = v;
	ll pt = 0, sum = 0;
	for(int i = 0; ; i++){
		for(int j = 0; j < mid; j++){
			sum += max(0LL, p[pt++] - i);
			if(sum >= k) return 1;
			if(pt == n) return 0;
		}
	}
}

int main(){
	fast;
	ll x;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
	}
	sort(v.rbegin(), v.rend());
	ll lo = 0, hi = n + 1;
	while(hi - lo > 1){
		ll mid = hi + lo >> 1LL;
		if(calc(mid)) hi = mid;
		else lo = mid;
	}	
	if(hi == n + 1) hi = -1;
	cout << hi << "\n";
	
	return 0;
}

