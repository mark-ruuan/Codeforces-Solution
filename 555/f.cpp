#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

std::vector<ll> ans;
set<ll> st;
set<ll> v[N];

ll dfs(ll node){
	ll ct = 0;
	auto it = st.begin();
	for(; it != st.end(); ){
		if(v[node].find(*it) == v[node].end()){
			ll x = *it;
			st.erase(it);
			ct += dfs(x);
			it = st.upper_bound(x);
		}
		else it++;
	}
	return ct + 1;
}

int main(){
	fast;
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		ll x, y;
		cin >> x >> y;
		v[x].insert(y);
		v[y].insert(x);
	}
	for(int i = 1; i <= n; i++){
		st.insert(i);
	}
	while(st.size()){
		ll cur = *st.begin();
		st.erase(st.begin());
		ll x = dfs(cur);
		ans.push_back(x);
	}
	sort(ans.begin(), ans.end());
	cout << (int)ans.size() << "\n";
	for(auto i: ans) cout << i << " ";
	
	return 0;
}

