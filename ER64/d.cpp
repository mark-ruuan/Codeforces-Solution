/*
I got a long way to go
		And a long memory
I've been searching for an answer
		Always just out of reach!!!!
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll p[N], h[N], sz, sz1;
bool visit[N];
std::vector<ll> v[N];


ll root(ll x){
	while(x != p[x]){
		p[x] = p[p[x]];
		x = p[x];
	}
	return x;
}

void join(ll x, ll y){
	p[root(y)] = root(x);
}

void dfs(ll node){
	visit[node] = 1;
	sz++;
	sz1 += h[root(node)] - 1;
	for(auto i: v[node]){
		if(!visit[i])
			dfs(i);
	}
}

int main(){
	fast;
	ll n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) p[i] = i;
	for(int i = 0; i < n; i++){
		ll x, y, w;
		cin >> x >> y >> w;
		if(w == 0){
			v[x].push_back(y);
			v[y].push_back(x);
		}
		else{
			if(root(x) != root(y)){
				join(x, y);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		h[root(i)]++;
	}
	for(int i = 1; i <= n; i++){
		if(!visit[i]){
			sz = 0, sz1 = 0;
			dfs(i);
			ans += sz * (sz - 1);
			ans += sz * sz1;
		}
	}
	cout << ans;
	
	
	return 0;
}

