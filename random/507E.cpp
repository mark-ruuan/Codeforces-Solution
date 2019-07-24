/*
 * @Author: a_kk 
 * @Date: 2019-02-07 19:08:48 
*/

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
const long double pi = 3.14159265358979323;
const double EPS = 1e-12;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N];
vector<ll> v;
map<ll, ll> mp;

ll ct(ll x){
	if(x == 1) return 1;
	return 1 + ct(x / 2);
}

int main(){
	fast;
	ll q;
	for(int i = 2; i < 20; i++){
		ll no = (1LL << i) - 1, out = 0;
		for(int j = 1; j < no; j += 2){
			ll t = __gcd((no ^ j), (no & j));
			out = max(out, t);
		}
		//cout << no << " " << out << endl;
		mp[no] = out;
	}
	//cout << (1LL << 20) - 1 << "\n";
	mp[16777215] = 5592405;
	mp[8388607] = 178481;
	mp[4194303] = 1398101;
	mp[2097151] = 299593;
	mp[1048575] = 349525;
	mp[33554431] = 1082401;
	cin >> q;
	while(q--){
		ll x;
		cin >> x;
		ll bit = ct(x);
		bool flag = 0;
		ll ans = 0;
		for(int i = 0; i < bit; i++){
			if(!(x & (1LL << i))) flag = 1;
			ans += (1LL << i);
		}
		if(flag == 1) cout << ans;
		else cout << mp[x];
		cout << "\n";

	}
	
	return 0;
}