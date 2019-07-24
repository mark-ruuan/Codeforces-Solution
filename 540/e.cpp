#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

set<pair<ll, ll> > st;
int main(){
	fast;
	ll n, k, flag = 0;
	cin >> n >> k;
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= k; j++){
			if(i == j) continue;
			st.insert({i, j});
			if(st.size() == n){
				flag = 1;
				break;
			}
		}
		if(flag == 1) break;
	}
	if(flag == 0) return cout << "NO", 0;
	cout << "YES\n";
	ll ct = 0;
	while(ct < n){
		pair<ll, ll> p = *st.begin();
		cout << p.first << " " << p.second << "\n";
		st.erase(st.find(p));
		ct++;
		swap(p.first, p.second);
		if(ct < n){
			cout << p.first << " " << p.second << "\n";
			if(st.find(p) != st.end())
			st.erase(st.find(p));
			ct++;
		}
	}
	
	return 0;
}

