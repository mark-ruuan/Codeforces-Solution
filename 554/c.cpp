#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll a, b;
	if(a > b) swap(a, b);
	cin >> a >> b;
	ll x = b - a;
	cout  << x-b%x ;
	
	return 0;
}

