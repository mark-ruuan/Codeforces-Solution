#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll h[N];
std::vector<pair<ll, ll> > v;

int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		ll x, y;
		cin >> x >> y;
		v.push_back({x, y});
		h[x]++;
		h[y]++;
	}
	for(auto i: v){
		if(h[i.first] == 1 && h[i.second] == 1) continue;
		else if(h[i.first] == 1){
			if(h[i.second] < 3) return cout << "NO\n", 0;
		}
		else if(h[i.second] == 1){
			if(h[i.first] < 3) return cout << "NO\n", 0;
		}
		else{
			if(h[i.first] >= 3 && h[i.second] >= 3) continue;
			else return cout << "NO\n", 0;
		}
	}
	cout << "YES\n";
	
	return 0;
}
