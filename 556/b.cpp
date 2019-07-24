#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

char ch[55][55];
int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) cin >> ch[i][j];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(ch[i][j] == '.' && ch[i - 1][j] == '.' && ch[i + 1][j] == '.' && ch[i][j - 1] == '.' && ch[i][j + 1] == '.'){
				ch[i][j] = '#';
				ch[i - 1][j] = '#';
				ch[i + 1][j] = '#';
				ch[i][j - 1] = '#';
				ch[i][j + 1] = '#';
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(ch[i][j] == '.') return cout << "NO", 0;
		}
	}
	cout << "YES";
	
	return 0;
}

