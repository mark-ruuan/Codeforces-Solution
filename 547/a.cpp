#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll x, y, ans = 1e18;;
	cin >> x >> y;
	if(y % x) return cout << -1, 0;
	ll rem = y / x;
	for(int i = 0; i < 60; i++){
		ll pow = (1LL << i);
		if(pow > rem) continue;
		for(int j = 0; j < 60; j++){
			ll t = powl(3, j);
			if(t > rem) continue;
			if(pow * t == rem){
				ans = min(ans, (ll)(i + j));
			}
		}
	}
	if(ans == 1e18) ans = -1;
	cout << ans;
	
	return 0;
}

