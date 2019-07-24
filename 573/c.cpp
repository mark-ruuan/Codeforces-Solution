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
	ll pt = 0;
	ll n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
		cin >> a[i];
	ll en = (a[0] + k - 1) / k * k;
	ll ans = 0;
	while(pt != m){
		ll ct = 0;
		while(pt < m && a[pt] <= en){
			pt++;
			ct++;
		}
		if(ct == 0){
			if(pt == m) break;
			ll diff = (a[pt] - en + k - 1) / k;
			en += diff * k;
		}
		else{
			ans++;
			en += ct;
		}
	}
	cout << ans;
	return 0;
}
