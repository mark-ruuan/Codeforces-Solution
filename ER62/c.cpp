#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N], b[N];
std::vector<pair<ll, ll> > v;
set<pair<ll, ll>> st;

int main(){
	fast;
	ll n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		v.push_back({a[i], b[i]});
	}
	sort(v.rbegin(), v.rend());
	ll len = 0, mx = 0, mul;
	for(int i = 0; i < k; i++){
		len += v[i].first;
		st.insert({v[i].second, i});
		mul = st.begin()->first;
		mx = max(mx, len * mul);
	}
	for(int i = k; i < n; i++){
		len -= v[st.begin()->second].first;
		st.erase(st.begin());
		len += v[i].first;
		st.insert({v[i].second, i});
		mul = st.begin()->first;
		mx = max(mx, len * mul);
	}
	while((int)st.size()){
		len -= v[st.begin()->second].first;
		st.erase(st.begin());
		if(!st.size()) break;
		mul = st.begin()->first;
		mx = max(mx, len * mul);
	}
	cout << mx;

	
	
	return 0;
}

