#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll x[N], y[N];
std::vector<pair<ll, ll> > v;
int main(){
	fast;
	ll n;
	cin >> n;
	ll ans = 0, ct = 0, ct1 = n - 1, ctt = n - 1, ctt1 = 0;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		v.push_back({x[i] - y[i] , i});
	}
	sort(v.rbegin(), v.rend());
	for(int i = 0, j = n - 1, t = 0; i <= j; i++,  j--, t++){
			ans += x[v[i].second] * ct + y[v[i].second] * ct1;
			ct++;
			ct1--;
			if(i == j) break;
			ans += x[v[j].second] * ctt + y[v[j].second] * ctt1;
			ctt--;
			ctt1++;
	}
	cout << ans;
	
	return 0;
}

