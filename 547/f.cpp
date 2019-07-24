#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1500 + 5;
const int MOD = 1e9 + 7;

set<ll> st;
ll a[N];
map<ll, set<pair<ll, ll> > > mp1;
std::vector<pair<ll, ll> > ans;
int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		ll sum = 0;
		for(int j = i; j <= n; j++){
			sum += a[j];
			st.insert(sum);
			mp1[sum].insert({j, i});
		}
	}
	std::vector<ll> temp;
	for(auto i: st) temp.push_back(i);
	for(auto i: temp){
		if(ans.size() >= mp1[i].size()) continue;
		set<pair<ll, ll> > st1 = mp1[i];
		std::vector<pair<ll, ll> > out;
		ll curr = 0;
		for(auto i: st1){
			ll l = i.second;
			ll r = i.first;
			if(l > curr){
				out.push_back({l, r});
				curr = r;
			}
		}
		if(out.size() > ans.size()){
			ans = out;
		}
	}
	cout << (int)ans.size() << "\n";
	for(auto i: ans){
		cout << i.first << " " << i.second << "\n";
	}
	
	return 0;
}

