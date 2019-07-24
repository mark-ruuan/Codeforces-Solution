#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

set<ll> st[N];
stack<ll> del;
ll p[N];
int main(){
	fast;
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for(int i = 1; i <= m; i++){
		ll x, y;
		cin >> x >> y;
		st[y].insert(x);
	}
	ll ct = 0;
	for(int i = n - 1; i  >= 0; i--){
		if(st[p[n]].size() == 0) break;
		if(st[p[n]].find(p[i]) != st[p[n]].end()){
				ct++;
				st[p[n]].erase(p[i]);
		}
		else{
			for(auto j: st[p[n]]){
				if(st[p[i]].find(j) == st[p[i]].end()){
					del.push(j);
				}
			}
			while(!del.empty()){
				st[p[n]].erase(del.top());
				del.pop();
			}
		}
	}
	cout << ct;
	
	return 0;
}

