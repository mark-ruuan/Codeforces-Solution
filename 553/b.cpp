#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[505][505];
ll ans[505], ans1[505];
int main(){
	fast;
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < 10; i++){
		ll ct = 0;
		memset(ans, 0, sizeof ans);
		memset(ans1, 0, sizeof ans1);
		for(int j = 0; j < n; j++){
			ll on = 0, off = 0;
			for(int k = 0; k < m; k++){
				if(a[j][k] & (1LL << i)){
					//cout << i << " " << j << " " << k << "\n";
					if(!on)
						ans[j] = k + 1;
					on = 1;
				}
				else if(!off){
					ans1[j] = k + 1;
					off = 1;
				}
			}
			ct += on;
		}
		if(ct & 1){
			cout << "TAK\n";
			for(int k = 0; k < n; k++){
				if(ans[k]) cout << ans[k];
				else cout << ans1[k];
				cout << " ";
			}
			return 0;
		}
		else{
			ll ok  = -1;
			for(int k = 0; k < n; k++){
				if(ans[k] && ans1[k]) ok = k;
			}
			//cout << ok << "\n";
			if(ok != -1){
				//cout << ok << "\n";
				cout << "TAK\n";
				for(int k = 0; k < n; k++){
					if(k == ok) cout << ans1[k];
					else{
						if(ans[k]) cout << ans[k];
						else cout << ans1[k];
					}
					cout << " ";
				}
				return 0;
			}
		}
	}
	cout << "NIE\n";
	
	return 0;
}

