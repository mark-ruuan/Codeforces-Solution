#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1000 + 5;
const int MOD = 1e9 + 7;

ll p[N], s[N], mx[N], ans[N];
int main(){
	fast;
	ll n, m, k, ct = 0;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int j = 1; j <= n; j++){
		cin >> s[j];
		if(p[j] > mx[s[j]]){
			mx[s[j]] = p[j];
			ans[s[j]] = j;
		}
	}
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		if(ans[s[x]] != x) ct++;
	}
	cout << ct;
	
	return 0;
}

