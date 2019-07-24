#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

std::vector<ll> ans;
ll a[N], pre[N];
int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		if(a[i] == a[i - 1]){
			pre[i] = pre[i - 1] + 1;
		}
		else{
			pre[i] = 1;
		}
	}
	pre[0] = pre[n + 1] = 1e16;
	for(int i = 1; i <= n; i++){
		if(pre[i] >= pre[i + 1]){
			ans.push_back(pre[i]);
		}
		
	}
	ans.push_back(pre[n]);
	ll out  = 0;
	for(int i = 0; i < (int)ans.size() - 1; i++){
		out = max(out, min(ans[i], ans[i + 1]) * 2);
	}
	cout << out;
	
	return 0;
}

