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


int main(){
	fast;
	ll t;
	cin >> t;
	while(t--){
		ll n, k, ct = 0;
		cin >> n >> k;
		while(n){
			if(n % k == 0){
				n /= k;
				ct++;
			}
			else{
				ct += n % k;
				n -= (n % k);
			}
		}
		cout << ct << "\n";
	}
	
	return 0;
}

