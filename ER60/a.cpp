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
	ll n, mx = 0, mx1 = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	for(int i = 1; i <= n; i++){
		if(a[i] == mx){
			a[i] = a[i - 1] + 1;
		}
		else a[i] = 0;
		mx1 = max(a[i], mx1);
	}
	cout << mx1;

	return 0;
}

