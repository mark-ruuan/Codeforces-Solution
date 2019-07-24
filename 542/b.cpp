#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N];
set<pair<ll, ll> >  st;
int main(){
	fast;
	ll n, ans = 0;
	cin >> n;
	for(int i = 0; i < 2 * n; i++){
		cin >> a[i];
		st.insert({a[i], i});
	}
	ll prev[2] = {0, 0}, x = 0;
	for(auto i: st){
		ans += abs(i.second - prev[x]);
		//cout << x << " " << i.first << " " << i.second << " " << prev[x] << "\n";
		prev[x] = i.second;
		x ^= 1;
	}
	cout << ans;
	
	return 0;
}

