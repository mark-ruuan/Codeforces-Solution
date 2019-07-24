#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll  int
#define ld long double
using namespace std;
const int N = 150000 + 5;
const int MOD = 1e9 + 7;

std::vector<ll> v[N];
ll pos[N];
int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		v[i].push_back(i);
		pos[i] = i;
	}
	for(int i = 0; i < n - 1; i++){
		ll x, y;
		cin >> x >> y;
		ll cur = pos[y];
		ll cur1 = pos[x];
		if((int)v[cur].size() <= (int)v[cur1].size()){
			v[cur1].insert(v[cur1].end(), v[cur].begin(), v[cur].end());
			for(auto i: v[cur]){
				pos[i] = cur1;
			}
			v[cur].clear();
		}
		else{
			v[cur].insert(v[cur].end(), v[cur1].begin(), v[cur1].end());
			for(auto i: v[cur1]){
				pos[i] = cur;
			}
			v[cur1].clear();
		}
	}
	for(int i = 1; i <= n; i++){
		if((int)v[i].size()){
			for(auto j: v[i]) cout << j << " ";
		}
	}
	
	return 0;
}

