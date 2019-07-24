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
	ll n, z, ct = 0;
	cin >> n >> z;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	ll pt = 0, pt1 = n / 2;
	while(pt < n / 2 && pt1 < n){
		if(a[pt] + z <= a[pt1]){
			pt1++;
			pt++;
			ct++;
		}
		else pt1++;
	}
	cout << ct;
	
	return 0;
}

