#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 5000 + 3;
const int MOD = 1e9 + 7;

ll p[N], c[N], rm[N], lft[N];
bool visit[N];
std::vector<ll> v[N];
ll match[N], ans[N];

bool dfs(ll node){
	if(visit[node]) return false;
	visit[node] = 1;
	for(auto i: v[node]){
		if(match[i] == -1 || dfs(match[i])){
			match[i] = node;
			return true;
		}
	}
	return false;
}

int main(){
	fast;
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	ll q;
	cin >> q;
	for(int i = 1; i <= q; i++){
		cin >> rm[i];
		lft[rm[i]] = 1;
	}
	for(int i = 1; i <= n; i++){
		if(!lft[i]) v[p[i]].push_back(c[i]);
	}
	ll mex = 0;
	memset(match, -1, sizeof match);
	for(int i = q; i >= 1; i--){
		memset(visit, 0, sizeof visit);
		while(dfs(mex)){
			mex++;
			memset(visit, 0, sizeof visit);
		}
		ans[i] = mex;
		v[p[rm[i]]].push_back(c[rm[i]]);
	}
	for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
	
	return 0;
}

