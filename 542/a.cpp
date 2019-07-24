#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ld a[N];
int main(){
	fast;
	ll n, ct = 0;
	cin >> n;
	ll d = 1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] / d > 0.0) ct++;
	}
	if(ct >= (n + 1) / 2) return cout << d, 0;
	ct = 0, d = -1;
	for(int i = 0; i < n; i++){
		if(a[i] / d > 0.0) ct++;
	}
	if(ct >= (n + 1) / 2) return cout << d, 0;
	d = 0;
	cout << d;
	return 0;
}

