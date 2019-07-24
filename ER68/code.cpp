#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e3+ 5;
const int MOD = 1e9 + 7;

int n;
int c, b, aa;
int a[N];
int dp[N][N];
int go(int idx, int prev){
	if(idx == n) return 0;
	if(dp[idx][prev] != -1) return dp[idx][prev];
	int x = 1e9, y = 1e9;
	if((a[idx] >= b && a[idx] <= c) && prev == 1){
		x = 1 + go(idx + 1, prev);
		if(a[idx] >= 1 && a[idx] <= aa)
			y = 3 + go(idx + 1, prev ^ 1);
	}
	else if((a[idx] >= 1 && a[idx] <= aa) && prev == 0){
		x = 1 + go(idx + 1, prev);
		if(a[idx] >= b && a[idx] <= c)
			y = 3 + go(idx + 1, prev ^ 1);
	}   
	return dp[idx][prev] = min(x, y);
}

int main(){
	fast;
	cin >> c >> b >> aa;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	memset(dp, -1, sizeof dp);
	int ans = go(0, 1);
	memset(dp, -1, sizeof dp);
	int ans1 = go(0, 0);
	cout << min(ans, ans1);
	return 0;
}
