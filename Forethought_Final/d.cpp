/*
Yea, those will be the days that I will be missing
	When I’m old and when I’m gray and when I stop working
I hope that I can say
	When all my days are done
That I had my fun!!!!!!!
*/
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll  int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

std::vector<pair<ll, ll> > v;
std::vector<ll> divi;

int main(){
	fast;
	ll 	n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		ll x, y;
		cin >> x >> y;
		if(x > y) swap(x, y);
		v.push_back({x, y});
	}
	sort(v.begin(), v.end());
	for(int i = 1; i < n; i++){
		if(n % i == 0) divi.push_back(i);
	}
	for(int i = 0; i < divi.size(); i++){
		std::vector<pair<ll, ll> > vv;
		for(int j = 0; j < (int)v.size(); j++){
			ll x = v[j].first + divi[i];
			ll y = v[j].second + divi[i];
			if(x > n) x -=  n;
			if(y > n) y -= n;
			if(x > y) swap(x, y);
			vv.push_back({x, y});
		}
		sort(vv.begin(), vv.end());
		if(v == vv){
			return cout << "Yes", 0;
		}
	}
	cout << "No";
	
	return 0;
}