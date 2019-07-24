#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll x, y, n;
	cin >> x >> y >> n;
	ll buy = (x + y) / n;
	ll fb = x / n;
	ll sb = y / n;
	if(fb + sb == buy) return cout << buy << " " << 0, 0;
	cout << buy << " " << min(n - (x % n), n - (y  % n));
	
	return 0;
}

