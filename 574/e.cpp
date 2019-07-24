#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


bool visit[N];
vector<int> v[N];

int dfs(int node, int par){
	visit[node] = 1;
	int x = 0;
	for(auto i: v[node]){
		if(!visit[i]){
			x |= dfs(i, node);
		}
		else{
			if(i != par) return 1;
		}
	}
	return 0;
}

int solve(){
	for(int i = 0; i < N; i++) v[i].clear(), visit[i] = 0;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		if(x == y) return 1;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int res = 0;
	for(int i = 0; i < n; i++){
		if(!visit[i]) res |= dfs(i, -1);
	}
	return res;
}


int main(){
	fast;
	int t;
	cin >> t;
	while(t--){
		cout << solve() << "\n";
	}
	
	
	return 0;
}
