 /*
    __                      _    _            __                 __
   / /_/\__        __ _    | | _| | __     _  \ \       __/\__  / /
  / /\    /       / _` |   | |/ / |/ /    (_)  | |      \    / / / 
 / / /_  _\      | (_| |   |   <|   <      _   | |      /_  _\/ /  
/_/    \/         \__,_|___|_|\_\_|\_\    (_)  | |        \/ /_/   
                      |_____|                 /_/                  

*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll ct[N], cost[N];
priority_queue <pair<ll, ll> , vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
int main(){
	fast;
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> ct[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> cost[i];
		pq.push({cost[i], i});
	}
	while(m--){
		ll x, y, ans = 0;
		cin >> x >> y;
		while(y != 0){
			if(ct[x] > 0){
				ll tt = min(ct[x], y);
				ct[x] -= tt;
				ans += cost[x] * tt;
				y -= tt;
			}
			else{
				while(!pq.empty() && ct[pq.top().second] == 0){
					pq.pop();
				}
				if(pq.empty()){
					y = 0;
					ans = 0;
				}
				else x = pq.top().second;
			}
		}
		cout << ans << "\n";
	}
	
	
	return 0;
}
