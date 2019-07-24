	#include <bits/stdc++.h>
	#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
	#define ll long long int
	#define ld long double
	using namespace std;
	const int N = 1e6 + 5;
	const int MOD = 1e9 + 7;

	ll ad(ll a, ll b){
	    return((a % MOD + b % MOD) % MOD);
	}
	ll sub(ll a, ll b){
	    return((a % MOD - b % MOD + MOD) % MOD);
	}
	ll mul(ll a, ll b){
	    return(((a % MOD) * (b % MOD)) % MOD);
	}

	ll fib[N], a[N];

	map<long, long> F, mp;

	long f(long n) {
		if (F.count(n)) return F[n];
		long k=n/2;
		if (n%2==0) { // n=2*k
			return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % MOD;
		} else { // n=2*k+1
			return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % MOD;
		}
	}

	int main(){
		fast;
		F[0] = F[1] = 1;
		fib[1] = 1;
		for(int i = 2; i < N; i++){
		
		 fib[i] = ad(fib[i - 1], fib[i - 2]);
		  //cout << fib[i] << "\n";
		}

		ll t;
		cin >> t;
		while(t--){
			mp.clear();
			//std::vector<ll> v;
			ll n, ans = 0;
			cin >> n;
			for(int i = 0; i < n; i++){
				ll x;
				cin >> x;
				mp[x]++;
			}

			for(auto i: mp){
				for(auto j: mp){
					for(auto k: mp){
						ll t = i.first + j.first - k.first;
						if(t == 0) continue;
						ll ct = mul(i.second, mul(j.second, k.second));
						ans = ad(ans, mul(ct, fib[t]));
					}
				}
			}
				/*for(auto i: mp){
					for(int k = 0; k < n; k++){
						if(i.first - a[k] < N) ans =  ad(ans, mul(i.second, fib[i.first - a[k]]));
						else if(i.first - a[k])
						ans = ad(ans, mul(i.second, f(i.first - a[k] - 1)));
					}
				}*/
			cout << ans << "\n";
		}	
		return 0;
	}

