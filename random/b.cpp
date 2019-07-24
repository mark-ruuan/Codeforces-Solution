#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
    fast;
    ll n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        xr ^= x;
        ans[i] = xr;
    }
    ans[n] = xr;

    
    return 0;
}

