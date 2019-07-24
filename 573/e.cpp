#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

std::vector<ll> v, vv;

int h[N][26];

int main(){
	fast;
	int n;
	cin >> n;	
	string s;
	cin >> s;
	for(int i = 0; i < n; i++){
		h[i + 1][s[i] - 'a']++;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 26; j++){
			h[i][j] += h[i - 1][j];
			cout << h[i][j] << " ";
		}
		cout << "\n";
	}
	int q;
	cin >> q;
	while(q--){
		int x;
		cin >> x;
		cout << h[x][s[x - 1] - 'a'] - 1 << "\n";
	}
	
	return 0;
}
