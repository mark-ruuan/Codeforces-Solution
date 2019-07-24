#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N];
ll pre[N];
int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	ll q;
	cin >> q;
	while(q--){
		ll x, y;
		cin >> x >> y;
		cout << (pre[y] - pre[x - 1]) / 10 << "\n";
	}
	
	return 0;
}
