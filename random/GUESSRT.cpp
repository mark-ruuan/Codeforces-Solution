/*
 * @Author: a_kk 
 * @Date: 2019-02-07 02:22:19 
*/

//

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
const long double pi = 3.14159265358979323;
const double EPS = 1e-12;
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
    ll t;
    cin >> t;
    while(t--){
        ll n, k, m;
        cin >> n >> k >> m;
        ll prob_fail = 1, prob_suc = divi(1, n), con = divi(n - 1, n);
        ll con1 = power(con, (m + 1) / 2);
        ll sum =  mul(prob_suc, divi(sub(con1, 1), sub(con, 1)));
        if(m % 2 == 0)
            sum = ad(sum, mul(con1, divi(1, n + k)));
        cout << sum << "\n";
    }
    
    
    return 0;
}