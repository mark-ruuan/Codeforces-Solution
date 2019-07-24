#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

ll x[N], y[N], k[N];
std::vector<ll> v;
int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		v.clear();
		ll n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> x[i] >> y[i];
		}
		for(int i = 0; i < n; i++){
			ll sum = 0;
			for(int j = 0; j < n; j++){
				sum += abs(x[i] - x[j]) + abs(y[i] - y[j]);
			}
			v.push_back(sum);
		}
		sort(v.begin(), v.end());
		for(int i = 0; i < n; i++) cin >> k[i];
		sort(k, k + n);
		ll ans = 0;
		for(int i = 0, j = n - 1; i < n; i++, j--){
			ans += (k[i] * v[j]);
		}
		cout << ans <<"\n";
	}
	
	return 0;
}

