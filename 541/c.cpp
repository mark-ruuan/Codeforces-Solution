#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

std::vector<int> v, lft, rt;

int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.rbegin(), v.rend());
	ll cur = v[0];
	for(int i = 1; i < (int)v.size(); i++){
		if(i & 1){
			lft.push_back(v[i]);
		}
		else
			rt.push_back(v[i]);
	}
	reverse(lft.begin(), lft.end());
	for(auto i: lft) cout << i << " ";
	cout << cur << " ";
	for(auto j: rt) cout << j << " ";

	return 0;
}

