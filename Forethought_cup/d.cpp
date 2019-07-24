#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e4 + 5;
const int MOD = 1e9 + 7;

ll path[N][2], a[N];
int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		memset(path, 0, sizeof path);
		ll n, flag = 0, mx = 0;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] >= 0) flag = 1;
			mx = max(mx, a[i]);
		}
		if(flag == 0){
			cout << mx << "\n";
			continue;
		}
		ll incl = a[0];
		ll exl = 0, ans = 0;
		path[0][0] = a[0];
		path[0][1] = 0;
		for(int i = 1; i < n; i++){
			ll tt = max(incl, exl);
			incl = exl + a[i];
			exl = tt;
			path[i][0] = incl;
			path[i][1] = exl;
		}
		ans = max(incl, exl);
		for(int i = n - 1; i >= 0; i--){
			if(i > 0  && ans == path[i][0] && ans == path[i][1]){
				if(a[i] > a[i - 1]){
					cout << a[i];
					ans -= a[i];
				}
			}
			else if(ans == path[i][0]){
				cout << a[i];
				ans -= a[i];
			}
		}
		cout << "\n";
	}
	return 0;
}

