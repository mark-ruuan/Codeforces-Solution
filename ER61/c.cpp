#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll  int
#define ld long double
using namespace std;
const int N = 5000 + 5;
const int MOD = 1e9 + 7;


ll a[N], t[N], ans[N], q[N][2];
std::vector<ll> pos[N];
int main(){
	fast;
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> q[i][0] >> q[i][1];
		a[q[i][0]]++;
		a[q[i][1] + 1]--;
		for(int j = q[i][0]; j <= q[i][1]; j++)
			pos[j].push_back(i);
	}
	ll ct = 0;
	for(int i = 1; i <= n; i++){
		a[i] += a[i - 1];
		t[i] = a[i];	
		if(t[i]) ct++;
	}
	ll out = 1e18;
	//cout << "yo" << endl;
	for(int i = 0; i < m; i++){
		ll mx = 1e18;
		memset(ans, 0, sizeof ans);
		for(int k = 1; k <= n; k++) a[k] = t[k];
		for(int j = q[i][0]; j <= q[i][1]; j++){
			int p = a[j];
			a[j]--;
			if(p && a[j] == 0){
				ans[i]++;
			}
		}
		for(int k = 1; k <= n; k++){
			if(a[k] == 1){
				for(auto j: pos[k]){
					if(j != i) ans[j]++;
				}
			}
		}
		/*for(int k = 0; k < m; k++) cout << ans[k] << " ";
			cout << "\n";*/
		for(int k = 0; k < m; k++){
			if(k != i) mx = min(mx, ans[k]);
		}
		out = min(out, ans[i] + mx);
		//cout << mx << " " << out << "\n";
	}
	cout << ct - out;
	return 0;
}