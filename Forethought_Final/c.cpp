/*
Yea, those will be the days that I will be missing
	When I’m old and when I’m gray and when I stop working
I hope that I can say
	When all my days are done
That I had my fun!!!!!!!
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll h[N], hm[N];

int main(){
	fast;
	ll n, m, ans = 0;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		ll x;
		cin >> x;
		if(!hm[x]) hm[x] = i + 1;
		h[x] = i + 1;
	}
	for(int i = 1; i <= n; i++){
		ll x = i;
		if(h[x]){
			if(x + 1 <= n){
				if(!h[x + 1]) ans++;
				else if(hm[x] - h[x + 1] >= 1) ans++;
			}
			if(x - 1 > 0){
				if(!h[x - 1]) ans++;
				else if(hm[x] - h[x - 1] >= 1) ans++;
			}
		}
		else if(!h[x]){
			ans++;
			if(x - 1  > 0){
				ans++;
			}
			if(x + 1 <= n){
				ans++;
			}
		}
		//cout << i << " " << ans << endl;
	}
	cout << ans;
	return 0;
}

