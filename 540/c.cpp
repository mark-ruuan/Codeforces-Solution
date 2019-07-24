#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


set<set<pair<ll, ll> > >con[5];
ll h[N];
ll ans[50][50];
int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 0; i < n * n; i++){
		ll x;
		cin >> x;
		h[x]++;
	}
	for(int i = 1; i <= (n + 1) / 2; i++){
		for(int j = 1; j <= (n + 1) / 2; j++){
			set<pair<ll, ll> > pos;
			pos.insert({i, j});
			pos.insert({i, n - j + 1});
			pos.insert({n - i + 1, j});
			pos.insert({n - i + 1, n - j + 1});
			con[pos.size()].insert(pos);
		}
	}
	for(auto i: con[4]){
		for(int k = 1; k <= 1000; k++){
			if(h[k] >= 4){
				for(auto j: i){
					//cerr << j.first << " " << j.second << "\n";
					ans[j.first][j.second] = k;
				}
				h[k] -= 4;
				break;
			}
		}
		//cout << "\n";
	}
	for(auto i: con[2]){
		for(int k = 1; k <= 1000; k++){
			if(h[k] >= 2){
				for(auto j: i){
					ans[j.first][j.second] = k;
				}
				h[k] -=2;
				break;
			}
		}
	}
	for(auto i: con[1]){
		for(int k = 1; k <= 1000; k++){
			if(h[k] >= 1){
				for(auto j: i){
					ans[j.first][j.second] = k;
				}
				h[k] -=1;
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(ans[i][j] == 0) return cout << "NO", 0;
		}
	}
	cout << "YES\n";
	for(int i = 1; i <= n; i++, cout << "\n"){
		for(int j = 1; j <= n; j++) cout << ans[i][j] << " ";
	}
	
	return 0;
}

