#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N];
map<ll, ll> mp;
int main(){
	fast;
	ll n, mx = 0;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		//cout << a[i] << "\n";
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			mp[a[i] + a[j]]++;
		}
	}
	for(auto i: mp){
		//cout << i.second << "\n";
		mx = max(mx, i.second / 2);
	}
	cout << mx << "\n";
	
	return 0;
}

