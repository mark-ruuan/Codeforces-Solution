#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 700 + 5;
const int MOD = 1e9 + 7;

ll ad(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}

ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) % MOD);
}


int ans[N], ans1[N], n;
ll dp[N][N][3][3];

ll go(ll lft, ll rt, ll lp, ll rp){
	//cout << lft << " " << rt << " " << lp << " " << rp << "\n";
	if(lft > rt) return 1;
	if(dp[lft][rt][lp][rp] != -1) return dp[lft][rt][lp][rp];
	ll x = 0;
	for(int i = 1; i < 3; i++){
		if(i != lp){
			x = ad(x, mul(go(ans[lft] + 1, rt, 0, rp), go(lft + 1, ans[lft] - 1, i, 0)));
		}
		if(rt != ans[lft]){
			x = ad(x, mul(go(lft + 1, ans[lft] - 1, 0, i), go(ans[lft] + 1, rt, i, rp)));
		}
		else{
			if(i != rp)
				x = ad(x, go(lft + 1, rt - 1, 0, i));
		}
	}
	return dp[lft][rt][lp][rp] = x;
}

int main(){
	fast;
	string s;
	cin >> s;
	n = (int)s.size();
	stack<int> st;
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			st.push(i);
		}
		else{
			ans[st.top()] = i;
			ans1[i] = st.top();
			st.pop();
		}
	}
	memset(dp, -1, sizeof dp);
	cout << go(0, n - 1, 0, 0);
	
	return 0;
}
