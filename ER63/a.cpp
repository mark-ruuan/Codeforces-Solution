#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 1; i < n; i++){
		if(s[i] < s[i - 1]){
			cout << "YES\n";
			cout << i << " " << i + 1 << "\n";
			return 0;
		}
	}
	cout << "NO\n";
	
	return 0;
}

