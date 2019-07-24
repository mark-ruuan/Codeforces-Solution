#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll col[N], dp[N][3], tot[3], x[N], y[N];
std::vector<ll> v[N];
bool visit[N];
ll ans;

void dfs(ll node){
	visit[node] = 1;
	for(auto i: v[node]){
		if(!visit[i]){
			dfs(i);
			for(int j = 0; j < 3; j++)
				dp[node][j] += dp[i][j];
		}
	}
	dp[node][col[node]]++;
}

void dfs1(ll node){
	visit[node] = 1;
	for(auto i: v[node]){
		if(!visit[i]){
			ll red = tot[1] - dp[i][1];
			ll blue = tot[2] - dp[i][2];
			ll no = tot[0] - dp[i][0];
			if((red == 0 || blue == 0) && (dp[i][1] == 0 || dp[i][2] == 0)) ans++;
			dfs1(i);
		}
	}
}

int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> col[i];
		tot[col[i]]++;
	}
	for(int i = 0; i < n - 1; i++){
		cin >> x[i] >> y[i];
		v[x[i]].push_back(y[i]);
		v[y[i]].push_back(x[i]);
	}
	dfs(1);
	memset(visit, 0, sizeof visit);
	dfs1(1);
	cout << ans;
	return 0;
}

