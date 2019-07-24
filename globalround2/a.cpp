#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N];
int main(){
	fast;
	ll n, lst;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n; i++){
		if(a[i] != a[0]) lst = i;
	}

	for(ll i = n - 2, ct = 1; i >= 0; i--, ct++){
		if(a[i] != a[n - 1]){
			lst = max(lst, ct);
		}
	}
	cout << lst;
	
	return 0;
}

