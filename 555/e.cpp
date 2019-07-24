#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

ll a[N], pp[N], nxt[N];
std::vector<char> ans;
int main(){
	fast;
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	ll diff = -1, pdiff = -1;
	for(int i = n; i >= 0; i--){
		if(a[i] != a[diff]){
			nxt[i] = diff;
			pdiff = diff;
			diff = a[i];
			
		}
		else{
			nxt[i] = pdiff;
		}
	}
	pdiff = -1, diff = -1;
	for(int i = 0; i < n; i++){
		if(a[i] != diff){
			pp[i] = diff;
			pdiff = diff;
			diff = a[i];
		}
		else{
			pp[i] = pdiff;
		}
	}
	ll l = 0, r = n - 1, ppp = -1;
	while(l <= r){
		if(l == r){
			if(ppp < a[l]){
				ans.push_back('L');
				ppp = a[l];
			}
			l++;
			continue;
		}
		if(a[l] < a[r]){
			if(ppp < a[l]){
				ans.push_back('L');
				ppp = a[l];
				l++;
			}
			else if(ppp < a[r]){
				ans.push_back('R');
				ppp = a[r];
				r--;
			}
			else{
				break;
			}
		}
		else if(a[r] < a[l]){
			if(ppp < a[r]){
				ans.push_back('R');
				ppp = a[r];
				r--;
			}
			else if(ppp < a[l]){
				ans.push_back('L');
				ppp = a[l];
				l++;
			}
			else{
				break;
			}
		}
		else{
			if(nxt[l] < pp[r]){
				if(ppp < a[l]){
					ans.push_back('L');
					ppp = a[l];
					l++;
				}
				else if(ppp < a[r]){
					ans.push_back('R');
					ppp = a[r];
					r--;
				}
				else{
					break;
				
				}
			}
			else if(nxt[l] >= pp[r]){
				if(ppp < a[r]){
					ans.push_back('R');
					ppp = a[r];
					r--;
				}
				else if(ppp < a[l]){
					ans.push_back('L');
					ppp = a[l];
					l++;
				}
				else{
				
					break;
				}
			}
		}
	}
	cout << (int)ans.size() << "\n";
	for(auto i: ans) cout << i;
	
	return 0;
}

