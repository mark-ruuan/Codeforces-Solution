#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n, x, y;
		cin >> n;
		cout << 1 << " " << n - 1 << " " << 1 << " ";
		for(int i = 2; i <= n; i++){
			cout << i << " ";
		}
		cout << endl;
		cin >> x;
		ll lo = 1, hi = n + 1, mid;
		while(hi - lo > 1){
			mid = (hi + lo) >> 1LL;
			cout << 1 << " " << n - mid + 1 << " " << 1 << " " ;
			for(int i = mid; i <= n; i++) cout << i << " ";
			cout << endl;
			cin >> y;
			if(y < x) hi = mid;
			else lo = mid;
		}
		cout << 1 << " " << n - 1 << " " << lo << " ";
		for(int i = 1; i <= n; i++) if(i != lo) cout << i << " ";
		cout << endl;
		cin >> x;
		cout << "-1" << " " << x << endl;
	}
	
	
	return 0;
}

