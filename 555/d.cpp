#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N], b[N];
multiset<ll> st;
std::vector<ll> ans;
int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		st.insert(x);
	}
	for(int i = 0; i < n; i++){
		ll nxt = n - a[i];
		nxt %= n;
		auto it = st.lower_bound(nxt);
		if(it == st.end()) it = st.begin();
		ans.push_back((a[i] + *it) % n);
		st.erase(it);
	}
	for(auto i: ans) cout << i << " ";
	
	return 0;
}

