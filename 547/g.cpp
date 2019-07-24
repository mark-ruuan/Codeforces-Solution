#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

std::vector<ll> v[N];
std::vector<pair<ll, ll> > vv;
set<ll> st;
ll ans;
map<ll, pair<ll, ll> > mp;
map<pair<ll, ll>, ll> mp1;
void dfs(ll node, ll k, ll par, ll col){
	bool flag = 0;
	if(k){
		if(st.find(node) != st.end()){
			flag = 1;
			k--;
			if(!col) col++;
		}
	}
	ll ct = 0;
	ans = max(ans, col);
	for(auto i: v[node]){
		if(i != par){
			if(!flag){
				ct++;
				if(ct == col) ct++;
				ans = max(ans, ct);
			}
			mp1[{min(node, i), max(node, i)}] = (flag == 1) ? col : ct;
			dfs(i, k, node, (flag == 1) ? col : ct);
		}
	}
}

int main(){
	fast;
	ll n, k;
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++){
		ll x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
		if(x > y) swap(x, y);
		mp[i + 1] = {x, y};
	}
	for(int i = 1; i <= n; i++){
		vv.push_back({v[i].size(), i});
	}
	sort(vv.rbegin(), vv.rend());
	for(int i = 0; i < k; i++){
		st.insert(vv[i].second);
	}
	dfs(vv[0].second, k, 0, 0);
	cout << ans << "\n";
	for(int i = 1; i < n; i++) cout << mp1[mp[i]] << " ";
	
	return 0;
}

