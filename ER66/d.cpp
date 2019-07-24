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

ll a[N];
std::vector<ll> v;
int main(){
	fast;
	ll n , k ;
    cin >> n >> k ;
    for( int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    vector < ll > suffix(n,0);
    suffix[n-1] = a[n-1];
    for( int i = n-2 ; i >= 0 ; i--){
        suffix[i] = suffix[i+1] + a[i] ;
    }
    vector < ll > v ;
    for( int i = 1 ; i < n ; i++){
        //cout << suffix[i] << " " ;
        v.push_back(suffix[i]);
    }
    sort(v.begin(), v.end());
    ll ans = suffix[0] ;
    k--;
    for( int i = (int)v.size()-1 ; i >= 0 ; i--){
            if(k==0) break ;
            ans += v[i] ;
            k--;
    }
    cout << ans ;
	
	return 0;
}

