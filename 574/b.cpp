#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ull unsigned long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n, k;
	cin >> n >> k;
	ll lo = 0, hi = n + 1;
	while(hi - lo > 1){
		ll mid = (hi + lo) / 2;
		ll val = (mid * (mid + 1)) / 2 - (n - mid);
		if(val >= k) hi = mid;
		else lo = mid;
	}
	cout << n - hi;
	return 0;
}
