#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll q;
	cin >> q;
	while(q--){
		ll n, a, b;
		cin >> n >> a >> b;
		if(a * 2 <= b){
			cout << n * a << "\n";
		}
		else{
			cout << (n / 2) * b + (n % 2) * a << "\n";
		}
	}
	
	return 0;
}

