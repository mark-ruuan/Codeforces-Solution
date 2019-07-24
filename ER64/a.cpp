/*
I got a long way to go
		And a long memory
I've been searching for an answer
		Always just out of reach!!!!
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N];
int main(){
	fast;
	ll n, ans = 0;
	cin >> n;
	ll prev = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i == 0) continue;
		if((a[i] == 2 && a[i - 1] == 3) || (a[i] == 3 && a[i - 1] == 2)){
			return cout << "Infinite", 0;
		}
		if(a[i] == 1){
			ans += a[i - 1] + 1;
		}
		else if(a[i] == 3)
			ans += 4;
		else if(a[i] == 2){
			if(i - 2 >= 0 && a[i - 2] == 3) ans += 2;
			else ans += 3;
		}
	}
	cout << "Finite\n";
	cout << ans;
	
	return 0;
}

