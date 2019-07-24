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
const int N = 5200 + 5;
const int MOD = 1e9 + 7;


std::vector<ll> v;
string s[N];
map<char, string> mp;
ll n;

void seive(){
	for(int i = 1; i <= n; i++){
		if(n % i == 0)
			v.push_back(i);
	}
	mp['0'] = "0000";
	mp['1'] = "0001";
	mp['2'] = "0010";
	mp['3'] = "0011";
	mp['4'] = "0100";
	mp['5'] = "0101";
	mp['6'] = "0110";
	mp['7'] = "0111";
	mp['8'] = "1000";
	mp['9'] = "1001";
	mp['A'] = "1010";
	mp['B'] = "1011";
	mp['C'] = "1100";
	mp['D'] = "1101";
	mp['E'] = "1110";
	mp['F'] = "1111";

}

bool calc(ll m){
	if(m == 1) return 1;
	for(int i = 1; i <= n; i += m){
		for(int j = i + 1; j <= n && j < i + m; j++){
			if(s[j] != s[i]) return 0;
		}
	}
	for(int i = 1; i <= n; i += m){
		for(int j = 1; j <= n; j += m){
			ll stx = i, sty = j, endx = min(n + 1, i + m), endy = min(n + 1, j + m);
			ll tx = stx, ty = (sty - 1) / 4;
			char ch = mp[s[tx][ty]][(sty - 1) % 4];
			//cout << ch << " " << m << "\n";
			for(int k = sty; k < endy; k++){
				ty = (k - 1) / 4;
				char chh = mp[s[tx][ty]][(k - 1) % 4];
				if(chh != ch){
					return 0;
				}
			}

		}
	}
	return 1;
}

int main(){
	fast;
	cin >> n;
	seive();
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	ll lo = -1, hi = (ll)v.size();
	for(int i  = hi - 1; i >= 0; i--){
		if(calc(v[i])){
		 lo = v[i];
		 break;
		}
	}
	cout << lo;
	
	return 0;
}
