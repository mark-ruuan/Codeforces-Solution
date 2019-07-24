#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll power(ll x, ll y){
    x %= MOD;
    ll ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % MOD;
        y >>= 1LL;
        x = (x * x) % MOD;
    }
    return ans;
}
ll ad(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}
ll sub(ll a, ll b){
    return((a % MOD - b % MOD + MOD) % MOD);
}
ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) % MOD);
}

bool visit[N];
vector<ll> v[N];
ll ct = 0;
void dfs(ll node){
	visit[node] = 1;
	ct++;
	for(auto i: v[node]){
		if(!visit[i]) dfs(i);
	}
}

int main(){
	fast;
	ll n, m, ans = 0;
	cin >> n >> m;
	for(int i = 0 ;i < n; i++){
		ll x, y, w;
		cin >> x >> y >> w;
		if(w==1) continue;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		if(!visit[i]){
			ct = 0;
			dfs(i);
			ans += power(ct, m);
		}
	}
	cout << sub(power(n, m), ans);
	
	return 0;
}

