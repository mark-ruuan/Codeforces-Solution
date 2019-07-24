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
#define ull unsigned long long int
using namespace std;
const long double pi = 3.14159265358979323;
const double EPS = 1e-12;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

std::vector<pair<ll, ll>> v;
void factorize(ll n){
	ll ct = 0, mx1 = 0;
	while(!(n % 2)){
		n >>= 1;
		ct++;
	}
	if(ct) v.push_back({2, ct});
	for(ll i = 3; i <= sqrtl(n); i += 2){
		ct = 0;
		while(n % i == 0){
			ct++;
			n = n / i;
		}
		if(ct) v.push_back({i, ct});
	}
	if(n > 2)
	v.push_back({n, 1});
}

int main(){
	fast;
	ll n, b, out = 6 * 1e18 + 5;
	cin >> n >> b;
	factorize(b);
	for(auto i: v){
		//cout << i.first << " " << i.second << "\n";
		ll div = i.first, c = n, ct = 0;
		while(c/div > 0){
			ct += (c / div);
			c/=div;
		}
		//cout << ct << "\n";
		out = min(out, ct / i.second);
	}
	cout << out << "\n";
	
	return 0;
}
