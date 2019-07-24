#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll power(ll x, ll y){
    x %= MOD;
    ll ans = 1;
    while(y){
        if(y & 1)
            ans = (ans * x) % MOD;
        y >>= 1LL;
        x = (x * x) % MOD;
    }
    return ans;
}
ll ad(ll a, ll b){
    return((a % MOD + b % MOD) % MOD);
}
ll sub(ll a, ll b){
    return((a % MOD - b % MOD + MOD) % MOD);
}
ll mul(ll a, ll b){
    return(((a % MOD) * (b % MOD)) % MOD);
}
ll divi(ll a, ll b){
    return(mul(a, power(b, MOD - 2)) % MOD);
}
int main(){
	fast;
	ll t ;
	cin >> t ;
	while(t--)
	{
		ll n , k ;
		cin >> n >> k ;
		ll ans[n]={0};
		
		ll val[2]={0};
		val[0] = ad(val[0],1);
		ans[0]=ans[1]=0;
		for(ll i=2 ; i < k ; i+=2)
		{
			ans[i]=val[0];
			val[0] = ad(mul(i,power(divi(1,2),i)),val[0]);

		}
				for(ll i=1 ; i < k ; i+=2)
		{
			ans[i]=val[1];
			val[1] = ad(val[1],mul(i,power(divi(1,2),i)));
		}
		
		

	}



	
	return 0;
}

