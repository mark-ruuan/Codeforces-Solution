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
using namespace std;
const long double pi = 3.14159265358979323;
const double EPS = 1e-12;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

map<ll, set<ll> > mp;
ll a[N];
std::vector<ll> v;
int main(){
	fast;
	ll n, m, k, sum = 0;
	cin >> n >> m >> k;
	ll ct = m * k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mp[a[i]].insert(i);
	}
	sort(a, a + n);
	for(int i = n - 1; i >= 0 && ct > 0; i--, ct--){
		ll val = *mp[a[i]].begin();
		sum += a[i];
		v.push_back(val);
		mp[a[i]].erase(mp[a[i]].begin());
	}
	sort(v.begin(), v.end());
	cout << sum <<  "\n";
	ct = 0;
	for(int i = 0; i < (int)v.size() - 1; i++){
		ct++;
		if(ct == m){
			cout << v[i] + 1 << " ";
			ct = 0; 
		}
	}
	
	return 0;
}
