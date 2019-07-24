#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 500 + 5;
const int MOD = 1e9 + 7;

set<pair<ll, ll> > st;
ll a[N][N], b[N][N];
int main(){
	fast;
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> b[i][j];
			st.insert({i, j});
		}
	}
	//cerr << "yo\n";
	while(!st.empty()){
		ll curx = st.begin()->first;
		ll cury = st.begin()->second;
		//cerr << curx << " " << cury << "\n";
		std::vector<ll> v, vv;
		while(curx < n && cury >= 0){
			v.push_back(a[curx][cury]);
			vv.push_back(b[curx][cury]);
			st.erase(st.find({curx, cury}));
			curx++;
			cury--;
		}
		sort(v.begin(), v.end());
		sort(vv.begin(), vv.end());
		if(v != vv) return cout << "NO", 0;
	}
	//cerr << "yo\n";
	cout << "YES";

	return 0;
}

