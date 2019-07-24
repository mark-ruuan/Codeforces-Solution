#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n, m, x;
	cin >> n >> m;
	ll ev = 0, od = 0;
	for(int i = 0; i < n; i++){
		cin >> x;
		if(x & 1) od++;
		else ev++;
	}
	ll ev1 = 0, od1 = 0;
	for(int i =  0; i < m; i++){
		cin >> x;
		if(x & 1) od1++;
		else ev1++;
	}
	cout << min(ev, od1) + min(od, ev1);
	
	
	return 0;
}

