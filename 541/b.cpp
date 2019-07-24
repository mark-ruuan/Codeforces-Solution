#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n, ans = 1;
	cin >> n;
	ll preva = 0, prevb = 0;
	for(int i = 0; i < n; i++){
		ll x, y;
		cin >> x >> y;
		ll mn = min(x, y);
		ll ct = max(0LL, mn - preva + 1);
		ll ct1 = max(0LL, mn - prevb + 1);
		ans += min(ct, ct1);
		if(preva == prevb){
			if(min(ct, ct1) != 0) ans--;
		}
		preva = x;
		prevb = y;
	}
	cout << ans << "\n";
	
	return 0;
}

