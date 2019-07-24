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

ll a[N];
int main(){
	fast;
	ll n, k, m;
	cin >> n >> k >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll ct = 0, sum = 0;
	ld ans = 0.0;
	for(int i = n; i > 0; i--){
		sum += a[i];
		ct++;
		ll t = m - (i - 1);
		if(t < 0) continue;
		ll tt = min(ct * k, t);
		ans = max(ans, (ld)1.0 * (sum + tt) / ct);
	}
	cout << fixed << setprecision(12) << ans;
	
	
	return 0;
}
