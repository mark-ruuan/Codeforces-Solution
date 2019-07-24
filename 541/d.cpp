#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

char ch[1005][1005];
std::vector<ll> v[N], vv[N];
ll ans[N], ans1[N];

ll recur(ll idx, bool flag){
	if(flag == 0)
		if((int)v[idx].size() == 0) return 0;
	else
		if((int)vv[idx].size() == 0) return 0;
	ll mx = 0;
	if(flag == 0)
		for(auto j: v[idx]){
			mx = max(mx, 1 + recur(j, flag ^ 1));
		}
	else
		for(auto j: vv[idx]){
			mx =  max(mx, 1 + recur(j, flag ^ 1));
		}
	return mx;
}

ll recur1(ll idx, bool flag){
	if(flag == 0)
		if((int)vv[idx].size() == 0) return 0;
	else
		if((int)v[idx].size() == 0) return 0;
	ll mx = 0;
	if(flag == 0)
		for(auto j: vv[idx]){
			mx =  max(mx, 1 + recur1(j, flag ^ 1));
		}
	else
		for(auto j: v[idx]){
			mx = max(mx, 1 + recur1(j, flag ^ 1));
		}
	return mx;
}

int main(){
	fast;
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> ch[i][j];
			if(ch[i][j] == '>') v[i].push_back(j);
			else if(ch[i][j] == '<') vv[j].push_back(i);
		}
	}
	for(int i = 1; i <= max(n, m); i++){
		sort(v[i].begin(), v[i].end());
		sort(vv[i].begin(), vv[i].end());
	}
	for(int i = 1; i <= n; i++){
		for(auto j: v[i]){
			auto it = lower_bound(vv[j].begin(), vv[j].end(), i) - vv[j].begin();
			if(it != vv[j].size()){
				cout << i << " " << j << "\n";
				if(vv[j][it] == i) return cout << "No", 0;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		ll ct = 1 + recur(i, 0);
		ans[i] = ct;
	}
	for(int i = 1; i <= m; i++){
		ll ct = 1 + recur1(i, 0);
		ans1[i] = ct;
	}
	cout << "Yes\n";
	for(int i = 1; i <= n; i++){
		if(!ans[i]) ans[i]++;
		cout << ans[i] << " ";
	}
	cout << "\n";
	for(int i = 1; i <= m; i++){
		if(!ans1[i]) ans1[i]++;
		cout << ans1[i] << " ";
	}

	
	return 0;
}

