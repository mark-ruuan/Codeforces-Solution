#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N], suff1sum[N][2];
int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	ll sumodd = 0, sumeve = 0, sum1eve = 0, sum1odd = 0;
	for(int i = n; i > 0; i--){
		if(i & 1){
			sum1eve += a[i];
		}
		else{
			sum1odd += a[i];
		}
		suff1sum[i][0] = sum1odd;
		suff1sum[i][1] = sum1eve;
	}
	ll curodd = 0, cureve = 0, ct = 0;
	for(int i = 1; i <= n; i++){
		ll todd = curodd;
		ll teve = cureve;
		todd += suff1sum[i + 1][0];
		teve += suff1sum[i + 1][1];
		if(todd == teve) ct++;
		if(i & 1) curodd += a[i];
		else cureve += a[i];
	}
	cout << ct;
	
	return 0;
}

