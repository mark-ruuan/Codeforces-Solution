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
	if(n & 1) cout << 0 << "\n";
	else{
		ll ans = 1;
		for(int i = 0; i < n / 2; i++) ans *= 2;
		cout << ans;
	}
	
	return 0;
}

