#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

std::vector<ll> v;
int main(){
	fast;
	ll n, m;
	cin >> n >> m;
	ll prev;
	cin >> prev;
	ll out = prev;
	for(int i = 1; i < n; i++){
		ll x;
		cin >> x;
		v.push_back(x - prev);
		prev = x;
	}
	sort(v.begin(), v.end());
	ll gg = v[0];
	for(int i = 1; i < (int)v.size(); i++)
		gg = __gcd(gg, v[i]);
	for(int i = 0; i < m; i++){
		ll x;
		cin >> x;
		if(gg % x == 0){
			cout << "YES\n";
			cout << out << " " << i + 1;
			return 0;
		}
	}
	cout << "NO";
	return 0;
}

