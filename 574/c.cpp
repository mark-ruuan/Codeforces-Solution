#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

ll dp[N][3];
int a[N][2];
int n;
ll go(int idx, int prev){
	if(idx == n) return 0;
	if(dp[idx][prev] != -1) return dp[idx][prev];
	ll x = 0;
	if(prev == 2)
		x = a[idx][0] + go(idx + 1, 1);
	else if(prev == 1)
		x = a[idx][1] + go(idx + 1, 2);
	else{
		x = a[idx][0] + go(idx + 1, 1);
		x = max(x, a[idx][1] + go(idx + 1, 2));
	}
	x = max(x, go(idx + 1, 0));
	return dp[idx][prev] = x;
}

int main(){
	fast;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i][0];
	for(int i = 0; i < n; i++) cin >> a[i][1];
	memset(dp, -1, sizeof dp);
	cout << go(0, 0);
	
	return 0;
}
