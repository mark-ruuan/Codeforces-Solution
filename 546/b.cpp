#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n, k;
	cin >> n >> k;
	ll ans = min((k - 1) * 2 + (n - k), (n - k) * 2 + (k - 1));
	//cerr << ans;
	ans += n + 1 + n;
	cout << ans;
	
	return 0;
}

