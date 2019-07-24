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
	ll n, mx = 1e18, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = n; i >= 1; i--){
		if(a[i] < mx){
			mx = a[i];
			ans += a[i];
		}
		else{
			mx = max(0LL, mx - 1);
			ans += mx;
		}
	}
	cout << ans;
	return 0;
}

