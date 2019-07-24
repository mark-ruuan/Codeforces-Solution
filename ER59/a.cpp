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


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		string s;
		cin >> s;
		if(n == 2){
			if(s[0] < s[1]){
				cout << "YES\n2\n";
				cout << s[0] << " " << s[1] << "\n"; 
			}
			else{
				cout << "NO\n";
				continue;
			}
		}
		else{
			cout << "YES\n2\n";
			cout << s[0] << " ";
			for(int i = 1; i < n; i++) cout << s[i];
		}
		cout << "\n";
	}
	
	return 0;
}
