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
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		ll mx = 1e16, out;
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i + k < n; i++){
			ll mean = (a[i] + a[i + k]) / 2;
			ll tt = max(abs(a[i] - mean), abs(a[i + k] - mean));
			if(tt < mx){
				mx = tt;
				out = mean;
			}
		}
		cout << out << "\n";
	}	
	
	return 0;
}

