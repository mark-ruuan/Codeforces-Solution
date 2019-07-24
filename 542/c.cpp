#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

char a[55][55];
ll n;
bool visit[55][55];
set<pair<ll, ll> > st, st1;
bool isvalid(int r, int c){
	return r >= 1 && r <= n && c >= 1 && c<= n && a[r][c] == '0' && !visit[r][c];
}

void grid(int r, int c){
	if(!isvalid(r, c)) return;
	visit[r][c] = 1;
	grid(r + 1, c);
	grid(r - 1, c);
	grid(r, c + 1);
	grid(r, c - 1);

}

int main(){
	fast;
	cin >> n;
	ll r, c, rr, cc;
	cin >> r >> c >> rr >> cc;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	grid(r, c);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(visit[i][j] && a[i][j] == '0'){
				st.insert({i, j});
				//cout << i  << "  " <<j << "\n";
			}
		}
	}
	if(st.find({rr, cc}) != st.end()) return cout << 0, 0;
	memset(visit, 0, sizeof visit);
	grid(rr, cc);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(visit[i][j] && a[i][j] == '0'){
				st1.insert({i, j});
				//cout << i << " " << j << "\n";
			}
		}
	}
	ll ans = 1e18;
	for(auto i: st){
		for(auto j: st1){
			ans = min(ans, (i.first - j.first) * (i.first - j.first)  + (i.second - j.second) * (i.second - j.second));
		}
	}
	cout << ans;

	return 0;
}

