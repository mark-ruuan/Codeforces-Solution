/*
Yea, those will be the days that I will be missing
	When I’m old and when I’m gray and when I stop working
I hope that I can say
	When all my days are done
That I had my fun!!!!!!!
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[200];
int main(){
	fast;
	ll n, h, m;
	cin >> n >> h >> m;
	for(int i = 1; i <= n; i++){
		a[i] = h;
	}
	for(int i = 1; i <= m; i++){
		ll l, r, mx;
		cin >> l >> r >> mx;
		for(int i = l;  i <= r; i++){
			if(a[i] > mx) a[i] = mx;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans += a[i] * a[i];
	cout << ans;
	
	return 0;
}

