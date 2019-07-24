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

set<ll> st;
map<ll, ll> mpp;
ll spf[N];
void seive(){
	spf[1] = 1;
	for(ll i = 2; i < N; i++){
		spf[i] = i;
	}
	for(int i = 4; i < N; i += 2) spf[i] = 2;
	for(int i = 3; i * i < N; i++){
		if(spf[i] == i){
			for(int j = i * i; j < N; j += i) 
				if(spf[j] == j) spf[j] = i;
		}
	}
}

void get(ll x){
	map<ll, ll> mp;
	while(x != 1){
		mp[spf[x]]++;
		x /= spf[x];
	}
	for(auto i:  mp){
		mpp[i.first] = max(mpp[i.first], i.second);
	}
}
int main(){
	fast;
	seive();
	int t;
	cin >> t;
	while(t--){
		int n; 
		cin >> n;
		st.clear();
		mpp.clear();
		for(int i = 0; i < n; i++){
			ll x;
			cin >> x;
			get(x);
			st.insert(x);
		}
		ll lcm = 1, mn = 0;
		for(auto i: mpp){
			if(mn == 0) mn = i.first;
			if(st.find(i.first) == st.end()){
				lcm = -1;
				break;
			}	
		}
		if(lcm == -1){
			cout << lcm << "\n";
			continue;
		}
		for(auto i: mpp){
			lcm *= powl(i.first, i.second);
		}
		auto it = --st.end();
		if(lcm == *it){
			lcm *= mn;
		}
		cout << lcm << "\n";
	}
	
	return 0;
}

