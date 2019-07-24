#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

map<ll, ll> mp;
int main(){
	fast;
	ll n;
	cin >> n;
	mp[n] = 1;
	ll ct = 1;
	while(1){
		n++;
		while(n % 10 == 0){
			n /= 10;
		}
		if(mp.find(n) != mp.end()) break;
		mp[n] = 1;
		ct++;
	}
	cout << ct;
	
	return 0;
}

