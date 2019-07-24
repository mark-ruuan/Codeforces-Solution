#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


std::vector<int> v, vv;
vector<pair<int, int> >  occ;

int main(){
	fast;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		occ.push_back({x, i});
	}
	sort(occ.begin(), occ.end());
	ll xr = 0;
	for(int i = n - 1; i >= 0; i--){
		if(xr == 0){
			v.push_back(occ[i].second);
			xr ^= 1;
		}
		else{
			vv.push_back(occ[i].second);
			xr ^= 1;
		}
	}
	cout << v.size() << "\n";
	for(auto i: v) cout << i + 1 << " ";
	cout << "\n";
	cout << vv.size() << "\n";
	for(auto i: vv) cout << i + 1 << " ";
	return 0;
}
