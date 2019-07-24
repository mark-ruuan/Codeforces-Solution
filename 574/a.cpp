#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int h[N];
int main(){
	fast;
	int ans = 0;
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		h[x]++;
	}
	int ct = 0;
	for(int i = 1; i <= k; i++){
		ct += (h[i] / 2) * 2;
		ans+=(h[i] / 2);
		h[i] %= 2;
	}
	for(int i = 1; i <= k; i++){
		if(h[i] && ans < (n + 1) / 2){
			h[i]--;
			ct++;
			ans++;
		}
	}
	cout << ct;
	
	return 0;
}
