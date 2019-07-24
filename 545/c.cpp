#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

ll a[N][N], b[N][N];
ll p[N];
set <ll> st;
int main(){
	fast;
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		st.clear();
		for(int j = 1; j <= m; j++){ cin >> a[i][j];
			st.insert(a[i][j]);}
		ll ct = 1;
		for(auto i: st){
			p[i] = ct++;
		}
		for(int j = 1; j <= m; j++){
			b[i][j] = p[a[i][j]];
		}
	}
	for(int i = 1; i <= m; i++){
		st.clear();
		for(int j = 1; j <= n; j++){
			st.insert(b[j][i]);
		}
		ll ct = 1;
		for(auto i: st) p[i] = ct++;
		for(int j = 1; j <= n; j++){
			b[j][i] = max(b[j][i], ct - 1);
		}

	}
	for(int i = 1; i <= n; i++, cout << "\n"){
		for(int j = 1; j <= m; j++) cout << b[i][j] << " ";
	}
	
	return 0;
}

