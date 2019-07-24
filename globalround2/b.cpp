#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

std::vector<ll> v, vv;

int main(){
	fast;
	ll n, h, x, ans = 0, ht = 0;
	cin >> n >> h;
	for(int i = 0; i < n; i++){
		cin >> x;
		v.push_back(x);
	}
	for(int i = 0; i < n; i++){
		vv.clear();
		ht = 0;
		for(int j = 0; j <= i; j++) vv.push_back(v[j]);
		sort(vv.begin(), vv.end());
		for(int j = (int)vv.size() - 1; j >= 0; j -= 2){
			ht += vv[j];
		}
		if(ht <= h) ans = i + 1;
	}
	cout << ans;
	return 0;
}

