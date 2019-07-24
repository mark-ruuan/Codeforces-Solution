#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n ;
	cin >> n ;
	set<int> a ;
	for(int i =1 ; i <= n ; i++ )
		a.insert(n/i);
	cout << a.size() << endl;
	for(auto i : a) cout << i << " ";
		cout << "\n" <<  (ll)sqrt(n);
	return 0;
}

