#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

set<ll> st;
ll a[N];
int main(){
	fast;
	ll n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != i) st.insert(a[i]);
		if(!st.empty() && st.find(i) != st.end()){
			st.erase(st.find(i));
		}
		if(st.empty()) ans++;
	}
	cout << ans;
	
	return 0;
}

