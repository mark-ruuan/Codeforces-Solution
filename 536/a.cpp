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

char ch[505][505];
int main(){
	fast;
	memset(ch, '#', sizeof ch);
	ll n;
	ll ct = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			cin >> ch[i][j];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			if(ch[i][j] == 'X'){
				if(ch[i - 1][j - 1] == 'X' && ch[i - 1][j + 1] == 'X' && ch[i + 1][j + 1] == 'X' && ch[i + 1][j - 1] == 'X') ct++; 
			}
	}
	cout << ct;
	return 0;
}
