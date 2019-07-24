#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
 ll RMQ[20][N], floorlog[N];
 void pre(){
 	for(int i = 0; (1<<i) < N; i++){
 		for(int j = (1<<i); j < N & j < (1<<(i+1)); j++)
 			floorlog[j] = i;
 	}
 	for(int i = n; i >= 1; i--){
 		RMQ[0][i] = a[i];
 		ll mxj = floorlog[n - i + 1];
 		ll pw = 1;
 		for(int j = 1; j <= mxj; j++){
 			RMQ[j][i] = max(RMQ[j - 1][i], RMQ[j - 1][i + pw]);
 			pw <<= 1; 
 		}
 	}
 }

 ll querry(ll l, ll r){
 	ll k = floorlog[r - l + 1];
 	return max(RMQ[k][l], RMQ[k][r - (1 << k) + 1]);
 }

int main(){
	fast;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	pre();
	cout << querry(2, 5) << "\n";
	
	
	return 0;
}

