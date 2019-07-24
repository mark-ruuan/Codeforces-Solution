#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N], suff[N];

int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = n; i >= 1; i--){
		suff[i] = a[i] + suff[i + 1];
	}
	ll q, ans = 0;
	cin >> q;
	for(int i = 0; i < q; i++){
		ll x;
		cin >> x;
		ll idx = n - x + 2;
		//cout << idx << " " << suff[idx] << " ";
		cout << suff[idx] + suff[1] - suff[idx - 1] << "\n";
	}
	//cout << ans;
	
	return 0;
}

