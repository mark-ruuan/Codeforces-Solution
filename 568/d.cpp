#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N], pref[N], h[N];
int main(){
	fast;
	ll n, sum;
	cin >> n >> sum;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i++){
		if(pref[i] <= sum){
			cout << 0 << " ";
		}
		else{
			ll diff = pref[i] - sum;
			//cout << diff << endl;
			ll ans = 0, ct = 0;
			for(int j = 100; j >= 1; j--){
				if(h[j]){
					//cout << h[j] << " ";
					if((ct + (j * h[j])) <= diff){
						ct += (j * h[j]);
						ans += h[j];
					}
					else{
						ll tt = ((diff - ct) + (j - 1)) / j;
						ans += tt;
						ct += tt * j;
					}
					//cout << j << " " << ct << " : ";
				}

				if(ct >= diff) break;

			}
			//cout << endl;
			cout << ans << " ";
		}
		h[a[i]]++;
		
	}
	return 0;
}

