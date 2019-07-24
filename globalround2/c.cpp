#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll ct[505], a[505][505], ct1[505];
int main(){
	fast;
	ll n, m, x;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) cin >> a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			cin >> x;
			if(a[i][j] != x) ct[j]++, ct1[i]++;
		}
	for(int i = 1; i <= m; i++){
		if(ct[i] & 1) return cout << "No", 0;
	}
	for(int j = 1; j <= n; j++){
		if(ct1[j] & 1) return cout << "No", 0;
	}
	cout << "Yes";
	
	return 0;
}

