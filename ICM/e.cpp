#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int M = 1e7 + 1;
const int MOD = 1e9 + 7;

ll spf[N];
map<ll, ll> mp;
ll ans[M];
ll ans1[M];

void seive(){
	ll mx = N - 1;
	spf[1] = 1;
	for(int i = 2;  i <= mx; i++)
		spf[i] = i;
	for(int i = 4; i <= mx; i+= 2)
		spf[i] = 2;
	for(int i = 3; i * i <= mx; i++){
		if(spf[i] == i){
			for(int j = i * i; j <= mx; j += i){
				if(spf[j] == j) spf[j] = i;
			}
		}
	}
}

void getFactor(int x){
	mp.clear();
	while(x != 1){
		mp[spf[x]]++;
		x /= spf[x];
	}
}

ll get(ll n){
	ll ans = 1;
	while(n){
		ans *= n % 10;
		n /= 10;
	}
	return ans;
}

int main(){
	fast;
	seive();
	for(int i = 1; i <= 1e6; i++){
		ll k = get(i);
		if(k == 0) continue;
		/*if(ans1[k]){
			ans[i] = ans1[k];
			continue;
		} 	*/	
		getFactor(k);
		ll sum = 0;
		for(auto j: mp){
			sum += (j.first * (j.second % 2));
		}
		ans[i] = sum;
		//ans1[k] = sum;
	}
	for(int i = 1; i <= 1e6; i++) ans[i] += ans[i - 1];
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << ans[n] << "\n";
	}
	
	
	return 0;
}

