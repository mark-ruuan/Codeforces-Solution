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
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

ll a[N], h[N][12];
int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		ll x;
		cin >> x;
		h[i][x]++;
		a[i] = x;
	}
	for(int j = 1; j <= n; j++){
		for(int i = 1; i <= 10; i++)
			h[j][i] += h[j - 1][i];
	}
	for(int j = n; j >= 1; j--){
		for(int k = 1; k <= 10; k++){
			if(h[j][k] == 0) continue;
			h[j][k]--;
			ll ct = 0;
			for(int i = 1; i <= 10; i++){
				if(h[j][i]){
					if(ct == 0) ct = h[j][i];
					else if(h[j][i] != ct){
						ct = -1;
						break;
					}
				}
			}
			if(ct != -1) return cout << j, 0;
			h[j][k]++;
		}
	}
	
	cout << 0;
	return 0;
}

