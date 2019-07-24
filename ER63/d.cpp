#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 4 * 1e5 + 5;
const int MOD = 1e9 + 7;

ll n, x;
ll dp[N][3];
ll a[N];
ll go(int idx, int type){
	if(idx == n) return 0;
	if(dp[idx][type] != -1) return dp[idx][type];
	ll ans = 0;
	if(type == 0){
		ans = max(ans, a[idx] + go(idx + 1, 0));
		ans = max(ans, a[idx] * x + go(idx + 1, 1));
	}
	else if(type == 1){
		ans = max(ans, a[idx] * x + go(idx + 1, 1));
		ans = max(ans, a[idx] + go(idx + 1, 2));
	}
	else{
		ans = max(ans, a[idx] + go(idx + 1, 2));
	}
	return dp[idx][type] = ans;
}
int main(){
	fast;
	ll ans = 0;
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	ans = max(ans, go(0, 0));
	for(int i = 1; i < n; i++)
		ans =  max(ans, dp[i][0]);
	cout << ans;
	
	return 0;
}

