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
	ll n, mn = 1e18, mx = -1, sum = 0;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		cin >> a[i];
		sum += a[i];
		if(sum == 0) return cout << -1, 0;
		if(sum < 0)
			mn = min(mn, sum);
	 	else
	 		mx = max(mx, sum);
	}

	if(mn == 1e18) mn = 0;
	if(mx == -1) mx = 0;
	//cerr << mx << " " << mn;
	ll st = -1;
	for(int i = 1; i <= n; i++){
		if((i + mx == n) && (i + mn == 1)){
			st = i;
			break;
		}
	}
	if(st == -1) return cout << -1, 0;
	cout << st << " ";
	for(int i = 0; i < n - 1; i++){
		st += a[i];
		cout << st << " ";
	}

	
	return 0;
}

